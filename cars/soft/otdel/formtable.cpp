#include "formtable.h"
#include "ui_formtable.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QComboBox>
#include <QTableView>
#include <globalpath.h>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QSqlTableModel>
#include <globalpath.h>
#include <authclass.hpp>
#include <admincheck.h>
#include <QInputDialog>
FormTable::FormTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTable)
    , deleteButton(nullptr)
{
    ui->setupUi(this);
    connectToDB();

    admincheck w;

    // Get login and password from the user via a dialog box
    QString login = QInputDialog::getText(&w, "Enter Login", "Login:");
    QString password = QInputDialog::getText(&w, "Enter Password", "Password:", QLineEdit::Password);

    // Check login and password
    int isAdmin = checkAdmin(login, password, &w);

    if (isAdmin == 1) {
        // If administrator
        setIsAdmin("1");
        QMessageBox::information(nullptr, "Success", "You have successfully logged in as an administrator");
        show();
    } else if(isAdmin == 0) {
        // If not an administrator
        QMessageBox::critical(nullptr, "Failure", "You failed to log in");
        return;
    } else if(isAdmin == 2) {
        // If a regular user
        setIsAdmin("2");
        QMessageBox::information(nullptr, "Success", "You have successfully logged in as a reader");
        show();
    }

}
int FormTable::checkAdmin(const QString& login, const QString& password, admincheck* w) {
    QSqlQuery checkAdminQuery;
    checkAdminQuery.prepare("SELECT login, password, isAdmin FROM users WHERE login = :login AND password = :password");
    checkAdminQuery.bindValue(":login", login);
    checkAdminQuery.bindValue(":password", password);

    if (!checkAdminQuery.exec()) {
        qDebug() << "Error executing query: " << checkAdminQuery.lastError().text();
        return 0;
    }

    if (checkAdminQuery.next()) {
        QString retrievedLogin = checkAdminQuery.value(0).toString();
        QString retrievedPassword = checkAdminQuery.value(1).toString();
        QString retrievedStatus = checkAdminQuery.value(2).toString();
        if (retrievedLogin == login && retrievedPassword == password && retrievedStatus == "true") {
            return 1;
        } else if(retrievedLogin == login && retrievedPassword == password && retrievedStatus == "false") {
            return 2;
        } else {
            return 0;
        }
    } else {
        return 0; // No matching user found
    }
}

void FormTable::setIsAdmin(const QString& value) {
    if (value == "1") {
        // Handle case when the user is an administrator
        userStatus_ = 1;
        qDebug()<<"it a admin";
    } else if (value == "2") {
        // Handle case when the user is a regular user
        userStatus_ = 2;
        qDebug()<<"it a user";
    } else {
        // Handle other cases if necessary
        qDebug() << "Unknown user status";
    }
}


void FormTable::connectToDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(globalPath::getDatabasePath());
    if (!db.open()) {
        QMessageBox::critical(this, "Error", "Error opening database: " + db.lastError().text());
        return;
    }

    QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table'");
    while (query.next()) {
        QString tableName = query.value(0).toString();
        if (tableName != "users" && tableName != "sqlite_sequence") { // Exclude the 'users' table and 'sqlite_sequence' table
            QPushButton *button = new QPushButton(tableName);
            ui->verticalLayout->addWidget(button); // Assuming you have a QVBoxLayout named verticalLayout in your form
            connect(button, &QPushButton::clicked, this, [this, tableName]() {
                updateTableView(tableName);
            connect(deleteButton, &QPushButton::clicked, this, &FormTable::tableButtonClicked);
            });
        }
    }

}

void FormTable::deleteData() {
    if (userStatus_ == 2) {
        QMessageBox::critical(this, "Access Denied", "You don't have permission to delete data.");
        return;
    }
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id = index.sibling(index.row(), 0).data().toInt(); // Assuming id is in the first column
    QString tableName; /* Get the table name */
    deleteDataById(tableName, id);
}
void FormTable::deleteDataById(const QString& tableName, int id) {
    if (userStatus_ == 2) {
        QMessageBox::critical(this, "Access Denied", "You don't have permission to delete data.");
        return;
    }
    // Получаем текст из labelTable
    QString labelText = ui->labelTable->text().toLower(); // Преобразуем текст в нижний регистр

    // Создаем SQL-запрос для удаления данных из таблицы с использованием имени таблицы

    // Подготавливаем запрос
    QSqlQuery query;
    QString name_id;
    qDebug() << labelText;
    if(labelText == "workers") {
        name_id = "worker";
    } else {
        name_id = labelText;
    }
    // Формируем строку запроса с использованием имени таблицы и значения id
    QString queryString = "DELETE FROM " + labelText + " WHERE id_" + name_id+ " = :id";

    // Подготавливаем запрос с сформированной строкой
    query.prepare(queryString);
    query.bindValue(":id", id);

    qDebug() << "Binding id:" << id; // Отладочное сообщение для отображения значения id
    QString tableName2 = ui->labelTable->text().toLower();
    qDebug() <<"table"<<tableName2;
    updateTableView(tableName2);
    // Выполняем запрос
    if (query.exec()) {

        QMessageBox::information(this, "Success", "Data with ID " + QString::number(id) + " deleted successfully.");
        // Опционально обновляем представление таблицы после успешного удаления

    } else {
        QMessageBox::critical(this, "Error", "Failed to delete data with ID " + QString::number(id) + ": " + query.lastError().text());
    }
    updateTableView(tableName2);
}


// В конструкторе FormTable или в другом удобном месте
void FormTable::updateData(const QList<QPair<QString, QWidget*>>& inputWidgets) {
    QString tableName = ui->labelTable->text().toLower(); // Получаем имя текущей таблицы
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id = index.sibling(index.row(), 0).data().toInt(); // Assuming id is in the first column

    QStringList fieldNames;
    QStringList fieldValues;

    // Получаем значения из виджетов для ввода данных
    for (const auto& pair : inputWidgets) {
        const QString& fieldName = pair.first;
        const QWidget* widget = pair.second;

        if (const QLineEdit* lineEdit = qobject_cast<const QLineEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(lineEdit->text());
        } else if (const QDateEdit* dateEdit = qobject_cast<const QDateEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(dateEdit->date().toString("yyyy-MM-dd"));
        } else if (const QComboBox* comboBox = qobject_cast<const QComboBox*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(comboBox->currentText());
        }
    }

    // Проверяем, что есть поля для обновления
    if (fieldNames.isEmpty() || fieldValues.isEmpty()) {
        QMessageBox::critical(this, "Error", "No fields to update.");
        return;
    }

    QString labelText = ui->labelTable->text().toLower(); // Преобразуем текст в нижний регистр

    // Создаем SQL-запрос для обновления данных
    QString name_id = (labelText == "workers") ? "worker" : labelText;
    qDebug() << "Table Label: " << labelText;
    qDebug() << "ID Label: " << name_id;
    qDebug() << "Field Names: " << fieldNames;
    qDebug() << "Field Values: " << fieldValues;

    QString queryString = "UPDATE " + labelText + " SET ";
    for (int i = 0; i < fieldNames.size(); ++i) {
        queryString += fieldNames[i] + " = '" + fieldValues[i] + "'";
        if (i < fieldNames.size() - 1) {
            queryString += ", ";
        }
    }
    queryString += " WHERE id_" + name_id + " = :id";

    // Выполняем SQL-запрос
    QSqlQuery query;
    qDebug() << "SQL Query: " << queryString;

    query.prepare(queryString);
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data updated successfully.");
        updateTableView(tableName); // Обновляем представление таблицы
    } else {
        QMessageBox::critical(this, "Error", "Failed to update data: " + query.lastError().text());
    }

    // Закрываем запрос
   // query.finish();
}

// Определение слота для обновления данных

void FormTable::updateTableView(const QString& tableName) {
    // Очистка предыдущих виджетов и кнопки перед созданием новых
    QLayoutItem *oldItem;
    while ((oldItem = ui->verticalLayout_2->takeAt(0)) != nullptr) {
        delete oldItem->widget();
        delete oldItem;
    }

    // Создание новых виджетов и кнопки
    // ... ваш код создания виджетов и кнопки ...

    QSqlQuery query;
    if (!query.exec("SELECT * FROM " + tableName)) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }
    QSqlRecord record = query.record();

    // Set the label text to the current table name
    ui->labelTable->setText(tableName); // Assuming labelTable is the name of your QLabel

    // Create delete data button if it doesn't exist
    if (!deleteButton) {
        deleteButton = new QPushButton("Delete Data");
        ui->verticalLayout_3->addWidget(deleteButton);

        // Connect the delete button to the deleteData slot
        connect(deleteButton, &QPushButton::clicked, this, &FormTable::deleteData);
    }

    // Update input fields
    QVBoxLayout *layout = new QVBoxLayout();
    QList<QPair<QString, QWidget*>> inputWidgets; // Store input widgets to access them later
    for (int i = 0; i < record.count(); ++i) {
        QString fieldName = record.fieldName(i);
        if (fieldName.startsWith("id"))
            continue; // Skip fields starting with 'id'
        QLabel *label = new QLabel(fieldName);
        layout->addWidget(label);

        QWidget *widget = nullptr;
        if (fieldName.startsWith("data")) {
            QDateEdit *dateEdit = new QDateEdit();
            widget = dateEdit;
        } else if (fieldName.contains("combox")) {
            QComboBox *comboBox = new QComboBox();
            // Execute SQL query to populate comboBox
            QString queryText;
            if (fieldName == "carModel_combox") {
                queryText = "SELECT DISTINCT car_model FROM Cars";
            } else  if (fieldName == "clientFullname_combox") {
                queryText = "SELECT DISTINCT client_fullname  FROM Clients";
            }
            qDebug() << "Executing query:" << queryText;
            QSqlQuery comboQuery(queryText);
            if (!comboQuery.exec()) {
                qDebug() << "Error executing query:" << comboQuery.lastError().text();
                continue;
            }
            while (comboQuery.next()) {
                QString value = comboQuery.value(0).toString();
                qDebug() << "Value:" << value;
                comboBox->addItem(value);
            }
            widget = comboBox;
        } else {
            QLineEdit *lineEdit = new QLineEdit();
            widget = lineEdit;
        }

        layout->addWidget(widget);
        inputWidgets.append(qMakePair(fieldName, widget)); // Store the widget with the field name
    }

    // Добавление фильтрации для таблицы Otdel по полю name_otdel
    if (tableName == "Rental") {
        // Создаем комбобокс для фильтрации


        QLabel *clientLabel = new QLabel("Select Client:");
        QComboBox *clientComboBox = new QComboBox();
        QPushButton *showButton = new QPushButton("SHOW");

        // Заполнение комбобокса списком клиентов
        QSqlQuery clientQuery("SELECT DISTINCT client_fullname FROM Clients");
        while (clientQuery.next()) {
            QString clientName = clientQuery.value(0).toString();
            clientComboBox->addItem(clientName);
        }

        // Добавляем элементы управления на форму
        layout->addWidget(clientLabel);
        layout->addWidget(clientComboBox);
        layout->addWidget(showButton);

        // Подключаем сигнал кнопки "SHOW" к слоту для вычисления суммы аренды
        connect(showButton, &QPushButton::clicked, this, [this, clientComboBox]() {
            QString clientName = clientComboBox->currentText();
            QSqlQuery sumQuery;
            if (sumQuery.exec("SELECT SUM(amount_days_rental * cost_one_day_rental) FROM Rental WHERE clientFullname_combox = '" + clientName + "'")) {
                if (sumQuery.next()) {
                    double totalRent = sumQuery.value(0).toDouble();
                    QMessageBox::information(this, "Итоговая сумма", "Итоговая сумма клиент(а)(ки) " + clientName + " руб." +QString::number(totalRent));
                }
            } else {
                qDebug() << "Error executing query:" << sumQuery.lastError().text();
            }
        });
        QLabel *dateLabel = new QLabel("Select Date:");
        QDateEdit *dateEdit = new QDateEdit();
        QPushButton *showButton2 = new QPushButton("SHOW WITH DATA");

        // Добавляем элементы управления на форму
        layout->addWidget(dateLabel);
        layout->addWidget(dateEdit);
        layout->addWidget(showButton2);

        // Подключаем сигнал кнопки "SHOW" к слоту для вычисления суммы аренды
        connect(showButton2, &QPushButton::clicked, this, [this, dateEdit]() {
            QDate selectedDate = dateEdit->date();
            QSqlQuery sumQuery;
            if (sumQuery.exec("SELECT SUM(amount_days_rental * cost_one_day_rental) FROM Rental WHERE data_startRental = '" + selectedDate.toString("yyyy-MM-dd") + "'")) {
                if (sumQuery.next()) {
                    double totalRent = sumQuery.value(0).toDouble();
                    QMessageBox::information(this, "Итоговая сумма", "Итоговая сумма за " + selectedDate.toString("yyyy-MM-dd") + " руб." + QString::number(totalRent));
                }
            } else {
                qDebug() << "Error executing query:" << sumQuery.lastError().text();
            }
        });
    }


    // Clear previous input layout and create a new inputWidget
    QWidget *inputWidget = new QWidget();
    inputWidget->setLayout(layout);

    // Remove previous inputWidget from the main input layout
    QLayoutItem *item;
    while ((item = ui->verticalLayout_2->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Add the new inputWidget to the main input layout
    ui->verticalLayout_2->addWidget(inputWidget);

    // Add a QPushButton to submit data
    QPushButton *submitButton = new QPushButton("Add Data");
    ui->verticalLayout_2->addWidget(submitButton);
    // Подключение кнопки update к слоту updateData
    // Удаление старых соединений
    disconnect(ui->pushUpdate, &QPushButton::clicked, nullptr, nullptr);
    disconnect(submitButton, &QPushButton::clicked, nullptr, nullptr);

    // Установка новых соединений
    connect(ui->pushUpdate, &QPushButton::clicked, this, [this, inputWidgets]() {
        this->updateData(inputWidgets);
    });
    connect(submitButton, &QPushButton::clicked, this, [this, inputWidgets, tableName]() {
        this->addData(inputWidgets, tableName);
    });

    // Update table view
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->select();
    ui->tableView->setModel(model); // Assuming you have a QTableView named tableView in your form
}

void FormTable::addData(const QList<QPair<QString, QWidget*>>& inputWidgets, const QString& tableName) {
    if (userStatus_ == 2) {
        QMessageBox::critical(this, "Access Denied", "You don't have permission to delete data.");
        return;
    }
    QStringList fieldNames;
    QStringList fieldValues;

    // Собираем имена полей и их значения из виджетов для ввода данных
    for (const auto& pair : inputWidgets) {
        const QString& fieldName = pair.first;
        const QWidget* widget = pair.second;

        if (const QLineEdit* lineEdit = qobject_cast<const QLineEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(lineEdit->text());
        } else if (const QDateEdit* dateEdit = qobject_cast<const QDateEdit*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(dateEdit->date().toString("yyyy-MM-dd"));
        } else if (const QComboBox* comboBox = qobject_cast<const QComboBox*>(widget)) {
            fieldNames.append(fieldName);
            fieldValues.append(comboBox->currentText());
        }
    }

    // Проверяем, что есть поля и значения для добавления
    if (fieldNames.isEmpty() || fieldValues.isEmpty()) {
        QMessageBox::critical(this, "Error", "No fields to add.");
        return;
    }

    // Строим текст SQL-запроса
    QString queryText = "INSERT INTO " + tableName + " (" + fieldNames.join(", ") + ") VALUES (";
    QStringList valuePlaceholders;
    for (int i = 0; i < fieldValues.size(); ++i) {
        valuePlaceholders.append("?");
    }
    queryText += valuePlaceholders.join(", ") + ")";

    // Подготавливаем SQL-запрос
    QSqlQuery query;
    query.prepare(queryText);
    for (const QString& value : fieldValues) {
        query.addBindValue(value);
    }

    // Выполняем SQL-запрос
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Data added successfully.");
        updateTableView(tableName); // Обновляем представление таблицы
    } else {
        QMessageBox::critical(this, "Error", "Failed to add data: " + query.lastError().text());
    }
}


void FormTable::tableButtonClicked() {
        QPushButton *button = qobject_cast<QPushButton*>(sender());
        if (button) {
            currentTableName = button->text(); // Установка текущего имени таблицы
            updateTableView(currentTableName); // Обновление представления таблицы
        }
}


    FormTable::~FormTable()
    {
        delete ui;
        // Clean up deleteButton
        delete deleteButton;
    }

