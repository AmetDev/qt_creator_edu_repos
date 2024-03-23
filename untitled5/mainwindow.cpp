#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include <iostream>
#include <vector>
#include "booktablemodel.h" // Include the header file for BookTableModel

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bookModel(this) // Initialize bookModel
{
    ui->setupUi(this);

    // Connect to the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amexdev/docs/library.db");

    if (!db.open()) {
        cout << "Ошибка при открытии базы данных" << endl;
        return;
    }

    cout << "База данных открыта успешно" << endl;

    // Retrieve data from the database
    QString tableName = "Книги";
    QSqlTableModel model;
    model.setTable(tableName);
    model.select();

    vector<Book> books;

    QSqlQuery query;
    query.setForwardOnly(false);
    query.exec("SELECT * FROM Книги");

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

    // Set up the model and view
    bookModel.setBooks(books);

    QTableView *tableView = new QTableView(this);
    tableView->setModel(&bookModel); // Corrected model setting
    tableView->resize(600, 400);
    tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clickme_clicked()
{
    QMessageBox::information(this, "Alert", "Button Clicked!");
}
