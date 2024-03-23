#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->switchTableButton, &QPushButton::clicked, this, &MainWindow::switchToPostuplenieTable);
    //swtichtableknigi
    connect(ui->swtichtableknigi, &QPushButton::clicked, this, &MainWindow::switchToKnigiTable);


    // Загрузка данных из базы данных
    loadDataFromDatabase();

    // Отображение данных из таблицы "Книги" в QTableView
    displayData("SELECT * FROM Книги");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDataFromDatabase()
{
    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных:" << db.lastError().text();
        return;
    }

    qDebug() << "База данных открыта успешно";

    // Retrieve data from the database
    QString tableName = "Книги";
    QSqlQuery query;
    query.prepare("SELECT * FROM Книги");
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        Book book;
        book.id = query.value("Код_книги").toInt();
        book.name = query.value("Название").toString().toStdString();
        book.typebook = query.value("Жанр").toString().toStdString();
        book.author = query.value("Авторы").toString().toStdString();
        book.izdatelstvo = query.value("Издательство").toString().toStdString();
        book.count_pages = query.value("Количество_страниц").toInt();
        books.push_back(book);
    }
}
void MainWindow::switchToKnigiTable()
{
    // Clear existing data
    books.clear();

    // Load data from the "Книги" table
    QString tableName = "Книги";
    QString queryStr = "SELECT * FROM " + tableName;
    QSqlQuery query;
    query.prepare(queryStr);
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        Book book;
        book.id = query.value("Код_книги").toInt();
        book.name = query.value("Название").toString().toStdString();
        book.typebook = query.value("Жанр").toString().toStdString();
        book.author = query.value("Авторы").toString().toStdString();
        book.izdatelstvo = query.value("Издательство").toString().toStdString();
        book.count_pages = query.value("Количество_страниц").toInt();
        books.push_back(book);
    }

    // Display data in QTableView
    displayData(queryStr);
}

void MainWindow::switchToPostuplenieTable()
{
    // Clear existing data
    books.clear();

    // Load data from the "Поступление_книги" table
    QString tableName = "Поступление_книги";
    QString queryStr = "SELECT * FROM " + tableName;
    QSqlQuery query;
    query.prepare(queryStr);
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        Book book;
        book.id = query.value("Код_поступления_книги").toInt();
        book.name = query.value("Номер_документа").toString().toStdString();
        book.typebook = query.value("Сведения_о_поставщике").toString().toStdString();
        book.author = query.value("Количество_экземпляров").toString().toStdString();
        books.push_back(book);
    }

    // Display data in QTableView
    displayData(queryStr);
}

void MainWindow::displayData(const QString &queryStr)
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
    ui->tableView->setModel(model);
}
