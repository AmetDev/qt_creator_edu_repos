#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Загрузка данных из базы данных
    loadDataFromDatabase();

    // Отображение данных в QTableView
    displayData();
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
void MainWindow::displayData()
{
    // Создаем модель данных
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Устанавливаем запрос в модель данных
    model->setQuery("SELECT * FROM Книги");

    // Устанавливаем модель в QTableView
    ui->tableView->setModel(model);
}
