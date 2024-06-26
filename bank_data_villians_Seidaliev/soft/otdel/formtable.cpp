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

FormTable::FormTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormTable)
    , deleteButton(nullptr) // Initialize deleteButton to nullptr
{
    ui->setupUi(this);
    connectToDB();

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
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();
    int id = index.sibling(index.row(), 0).data().toInt(); // Assuming id is in the first column
    QString tableName; /* Get the table name */
    deleteDataById(tableName, id);
}
void FormTable::deleteDataById(const QString& tableName, int id) {
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
            if (fieldName == "polling_station_num_combox") {
                queryText = "SELECT DISTINCT polling_station_num FROM PollingStations";
            } else if (fieldName == "additional_info_combox") {
                queryText = "SELECT DISTINCT additional_info FROM AdditionalInfo";
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
    if (tableName == "Inhabitants") {
        // Создаем комбобокс для фильтрации
        QLabel *filterLabel = new QLabel("Filter by inhabitant_fullname:");
        QComboBox *filterComboBox = new QComboBox();
        QPushButton *filterButton = new QPushButton("Apply Filter");
        QPushButton *clearFilterButton = new QPushButton("Clear Filter");

        // Заполнение комбобокса значениями из базы данных
        QString queryText = "SELECT DISTINCT inhabitant_fullname FROM Inhabitants";
        QSqlQuery comboQuery(queryText);
        if (!comboQuery.exec()) {
            qDebug() << "Error executing query:" << comboQuery.lastError().text();
        } else {
            while (comboQuery.next()) {
                QString value = comboQuery.value(0).toString();
                filterComboBox->addItem(value);
            }
        }

        // Добавление элементов управления на форму
        layout->addWidget(filterLabel);
        layout->addWidget(filterComboBox);
        layout->addWidget(filterButton);
        layout->addWidget(clearFilterButton);

        // Подключение сигналов к слотам для применения и сброса фильтра по inhabitant_fullname
        connect(filterButton, &QPushButton::clicked, this, [this, tableName, filterComboBox]() {
            QString filterValue = filterComboBox->currentText();
            QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
            if (model) {
                model->setFilter("inhabitant_fullname = '" + filterValue + "'");
            }
        });

        connect(clearFilterButton, &QPushButton::clicked, this, [this, tableName, filterComboBox]() {
            filterComboBox->setCurrentIndex(0); // Сбрасываем выбранный индекс
            QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
            if (model) {
                model->setFilter("");
            }
        });

        // Выполнение сортировки по polling_station_num_combox
        QSqlTableModel *model = new QSqlTableModel(this);
        model->setTable(tableName);
        model->setSort(model->fieldIndex("polling_station_num_combox"), Qt::AscendingOrder);
        model->select();
        ui->tableView->setModel(model);
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

