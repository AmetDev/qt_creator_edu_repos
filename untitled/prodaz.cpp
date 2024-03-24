#include "prodaz.h"
#include "ui_prodaz.h"
#include <QtSql>
#include <QMessageBox>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDialogButtonBox>
using namespace std;
Prodaz::Prodaz(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prodaz)
{
    ui->setupUi(this);
    addItemNameBook();
    addSvedeniya();
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::activated), this, &Prodaz::comboBoxActivated);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), this, &Prodaz::comboBoxActivatedSved);
    connect(ui->addBtnProdaz, &QPushButton::clicked, this, &Prodaz::addNewObjProdaz);
    connect(ui->updateBtnProdaz, &QPushButton::clicked, this, &Prodaz::updateObjProdaz);
    connect(ui->deleteBtnProdaz, &QPushButton::clicked, this, &Prodaz::deleteObjProdaz);

    displayDataProdaz("SELECT * FROM Продажи");
}



void Prodaz::deleteObjProdaz() {
    QString ID = ui->deleteInputProdaz->toPlainText();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        qDebug() << "Ошибка: не удалось подключиться к базе данных";
        return;
    }
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Продажи WHERE Код_продаж = :ID");
    checkQuery.bindValue(":ID", ID);
    if (!checkQuery.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << checkQuery.lastError().text();
        return;
    }
    checkQuery.next(); // Переход к первой строке результата запроса
    int count = checkQuery.value(0).toInt();
    if (count == 0) {
        QMessageBox::critical(this, "Ошибка", "Объект не был найден");
        return;
    }
    QSqlQuery query;
    query.prepare("DELETE FROM Продажи WHERE Код_продаж = :ID");
    query.bindValue(":ID", ID);
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос");
    } else {
        QMessageBox::information(this, "Удачно", "Удалось удалить объект");
    }
    displayDataProdaz("SELECT * FROM Продажи");
}

void Prodaz::comboBoxActivated(int index) {
    // Получение текста выбранного элемента
    QString selectedItemText = ui->comboBox_2->currentText();

    // Получение кода книги, соответствующего выбранному элементу
    QVariant itemData = ui->comboBox_2->itemData(index);
    int bookCode = itemData.toInt();
    global_code_post_books = bookCode;
    global_name_books = selectedItemText.toStdString();
    // Установка текста в QLabel, возможно, вам нужно что-то другое сделать с кодом книги
    ui->label_10->setText(selectedItemText + " (Код книги: " + QString::number(bookCode) + ")");
}
void Prodaz::updateObjProdaz() {
    // Создайте диалоговое окно для получения значений для обновления
    QDialog dialog(this);
    dialog.setWindowTitle("Введите данные для обновления");

    // Создайте элементы управления для ввода значений
    QLabel* codeLabel = new QLabel("Код продажи:");
    QLineEdit* codeLineEdit = new QLineEdit();
    QLabel* priceLabel = new QLabel("Цена:");
    QLineEdit* priceLineEdit = new QLineEdit();
    QLabel* dateLabel = new QLabel("Дата продажи:");
    QDateEdit* dateEdit = new QDateEdit();
    QLabel* sumLabel = new QLabel("Сумма продажи:");
    QLineEdit* sumLineEdit = new QLineEdit();

    // Установите текущие значения в поля ввода, если они уже есть
    codeLineEdit->setText(ui->codeProdszInput->toPlainText());
    priceLineEdit->setText(ui->textPrice->toPlainText());
    dateEdit->setDate(ui->dateEdit->date());
    sumLineEdit->setText(ui->sumInputProdaz->toPlainText());

    // Создайте менеджер компоновки для размещения элементов управления
    QVBoxLayout* layout = new QVBoxLayout(&dialog);
    layout->addWidget(codeLabel);
    layout->addWidget(codeLineEdit);
    layout->addWidget(priceLabel);
    layout->addWidget(priceLineEdit);
    layout->addWidget(dateLabel);
    layout->addWidget(dateEdit);
    layout->addWidget(sumLabel);
    layout->addWidget(sumLineEdit);

    // Создайте кнопки для подтверждения и отмены
    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    layout->addWidget(buttons);

    // Показать диалоговое окно и дождаться ввода пользователя
    if (dialog.exec() == QDialog::Accepted) {
        // Получите значения из полей ввода
        QString code_prodaz = codeLineEdit->text();
        QString textPrice = priceLineEdit->text();
        QDate selectedDate = dateEdit->date();
        QString sumInputProdaz = sumLineEdit->text();
        QString dateString = selectedDate.toString("yyyy-MM-dd");

        // Open the database connection
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/home/amexdev/docs/library.db");
        if (!db.open()) {
            qDebug() << "Ошибка: не удалось подключиться к базе данных";
            return;
        }

        // Prepare the SQL SELECT query to check if the record exists
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM Продажи WHERE Код_продаж = :code_prodaz");
        checkQuery.bindValue(":code_prodaz", code_prodaz);
        if (!checkQuery.exec()) {
            qDebug() << "Ошибка выполнения запроса:" << checkQuery.lastError().text();
            db.close();
            return;
        }

        // Fetch the result
        checkQuery.next();
        int count = checkQuery.value(0).toInt();

        if (count == 0) {
            // Если запись с указанным кодом продажи не существует, выдайте сообщение об ошибке
            QMessageBox::critical(this, "Ошибка", "Запись с указанным кодом продажи не существует");
            db.close();
            return;
        }

        // Prepare the SQL UPDATE query
        QSqlQuery query;
        query.prepare("UPDATE Продажи SET Цена = :textPrice, Дата_продажи = :dateString, Сумма_продажи = :sumInputProdaz WHERE Код_продаж = :code_prodaz");
        query.bindValue(":textPrice", textPrice);
        query.bindValue(":dateString", dateString);
        query.bindValue(":sumInputProdaz", sumInputProdaz);
        query.bindValue(":code_prodaz", code_prodaz);

        // Execute the SQL query
        if (!query.exec()) {
            qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
            db.close();
            return;
        }

        // Handle the successful update
        QMessageBox::information(this, "Обновление успешно", "Запись успешно обновлена");
        displayDataProdaz("SELECT * FROM Продажи");
    }
}

void Prodaz::addNewObjProdaz()
{
    QString code_prodaz = ui->codeProdszInput->toPlainText();
    QString textPrice = ui->textPrice->toPlainText();
    QDate selectedDate = ui->dateEdit->date();
    QString sumInputProdaz = ui->sumInputProdaz->toPlainText();
    // Convert the QDate to a string for display or further processing
    QString dateString = selectedDate.toString("yyyy-MM-dd");

    // Create a message string to display in QMessageBox
    QString message = "code_prodaz: " + code_prodaz + "\n" +
                      "textPrice: " + textPrice + "\n" +
                      "dateString: " + dateString + "\n" +
                      "sumInputProdaz: " + sumInputProdaz + "\n" +
                      "global_code_post_books: " + QString::number(global_code_post_books) + "\n" +
                      "global_name_books: " + QString::fromStdString(global_name_books) + "\n" +
                      "global_code_post_sved: " + QString::number(global_code_post_sved) + "\n" +
                      "global_name_post_sved: " + QString::fromStdString(global_name_post_sved);

    // Display the message using QMessageBox
    QMessageBox::information(this, "Успех", message);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        qDebug() << "Ошибка: не удалось подключиться к базе данных";
        return;
    }

    // Prepare the SQL SELECT query to check for duplicates
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Продажи WHERE Код_продаж = :code_prodaz");
    checkQuery.bindValue(":code_prodaz", code_prodaz);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка выполнения запроса:" + checkQuery.lastError().text());
        db.close();
        return;
    }

    // Fetch the result
    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::critical(this, "Ошибка", "Запись с указанным кодом продажи уже существует");
        db.close();
        return;
    }

    // If no duplicate is found, proceed with the insertion
    QSqlQuery query;
    query.prepare("INSERT INTO Продажи (Код_продаж, Код_книги, Код_поступления_книги, Название_книги, Сведения_о_поставщике, Цена, Дата_продажи, Сумма_продажи) VALUES(:code_prodaz, :global_code_post_books, :global_code_post_sved, :global_name_books,  :global_name_post_sved, :textPrice, :dateString, :sumInputProdaz)");
    query.bindValue(":code_prodaz", code_prodaz);
    query.bindValue(":global_code_post_books", global_code_post_books);
    query.bindValue(":global_code_post_sved", global_code_post_sved);
    query.bindValue(":global_name_books", QString::fromStdString(global_name_books));
    query.bindValue(":global_name_post_sved", QString::fromStdString(global_name_post_sved));
    query.bindValue(":textPrice", textPrice); // Add this line to bind textPrice
    query.bindValue(":dateString", dateString); // Add this line to bind dateString
    query.bindValue(":sumInputProdaz", sumInputProdaz); // Add this line to bind sumInputProdaz
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        db.close();
        return;
    }
    // Handle the successful insertion
    QMessageBox::information(this, "Успех", "Данные успешно добавлены");
    displayDataProdaz("SELECT * FROM Продажи");
}


void Prodaz::comboBoxActivatedSved(int index)
{
    // Получение текста выбранного элемента
    QString selectedItemText = ui->comboBox->currentText();

    // Получение кода книги, соответствующего выбранному элементу
    QVariant itemData = ui->comboBox->itemData(index);
    int bookCode = itemData.toInt();


    global_code_post_sved = bookCode;
    global_name_post_sved = selectedItemText.toStdString();
    // Установка текста в QLabel, возможно, вам нужно что-то другое сделать с кодом книги
    ui->label_11->setText(selectedItemText + " (Код_поступления_книги: " + QString::number(bookCode) + ")");
}
void Prodaz::addSvedeniya()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        qDebug() << "Ошибка: не удалось подключиться к базе данных";
        return;
    }

    // Выполнение запроса на получение данных
    QSqlQuery query;
    if (!query.exec("SELECT Сведения_о_поставщике, Код_поступления_книги FROM Поступление_книги")) {
        qDebug() << "Ошибка: не удалось выполнить запрос";
        return;
    }

    // Добавление данных в ComboBox_2
    while (query.next()) {
        QString itemName = query.value(0).toString();
        int itemCode = query.value(1).toInt();
        global_code_post_sved = itemCode;
        global_name_post_sved = itemName.toStdString();
        ui->comboBox->addItem(itemName, itemCode); // Сохраняем код книги как данные элемента
    }

}

void Prodaz::addItemNameBook() {
    // Установка соединения с базой данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");
    if (!db.open()) {
        qDebug() << "Ошибка: не удалось подключиться к базе данных";
        return;
    }

    // Выполнение запроса на получение данных
    QSqlQuery query;
    if (!query.exec("SELECT Название, Код_книги FROM Книги")) {
        qDebug() << "Ошибка: не удалось выполнить запрос";
        return;
    }

    // Добавление данных в ComboBox_2
    while (query.next()) {
        QString itemName = query.value(0).toString();
        int itemCode = query.value(1).toInt();
        global_code_post_books = itemCode;
        global_name_books = itemName.toStdString();
        ui->comboBox_2->addItem(itemName, itemCode); // Сохраняем код книги как данные элемента
    }

    // Закрытие соединения с базой данных
    // db.close();
}
void Prodaz::displayDataProdaz(const QString &queryStr)
{
    // Создаем модель данных
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Устанавливаем запрос в модель данных
    model->setQuery(queryStr);

    // Проверяем ошибки при выполнении запроса
    if (model->lastError().isValid()) {
        qDebug() << "Ошибка выполнения запроса:" << model->lastError().text();
        return;
    }

    // Устанавливаем модель в QTableView
    ui->tableViewProdaz->setModel(model);
}

Prodaz::~Prodaz()
{
    delete ui;
}
