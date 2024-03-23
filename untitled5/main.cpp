#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <json/reader.h>
#include <QTableView>
#include <QStandardItemModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTextStream>
#include <QDebug>
#include <vector>
#include <QChar>
using namespace std;

void fl(const char * filename)
{
    ifstream file(filename);
    string s;
    while(getline(file, s))
        cout << s << endl;
}

int main(int argc, char *argv[])
{
    // struct Book {
    //     int id;
    //     string name;
    //     string typebook;
    //     string author;
    //     string izdatelstvo;
    //     int count_pages;
    //     // Add more fields as needed
    // };
    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("/home/amexdev/docs/library.db");


    // if (!db.open()) {
    //     cout << "Ошибка при открытии базы данных" << endl;
    // } else {
    //     cout << "База данных открыта успешно" << endl;
    // }

    // QString tableName = "Книги";

    // // Create a QSqlTableModel for the table
    // QSqlTableModel model;
    // model.setTable(tableName);
    // model.select();

    // // Retrieve the column names
    // QSqlRecord record = model.record();


    // vector<Book> books;

    // QSqlQuery query;
    // query.setForwardOnly(false);
    // query.exec("SELECT * FROM Книги");

    // while (query.next()) {

    //     Book book;
    //     cout <<  query.value("Название").toString().toStdString() << endl;
    //     book.id = query.value("Код_книги").toInt();
    //     book.name = query.value("Название").toString().toStdString();
    //     book.typebook = query.value("Жанр").toString().toStdString();
    //     book.author = query.value("Авторы").toString().toStdString();
    //     book.izdatelstvo = query.value("Издательство").toString().toStdString();
    //     book.count_pages = query.value("Количество_страниц").toInt();
    //     books.push_back(book);
    // }

    // for (const auto& book : books) {
    //     std::cout << "Книга: " << book.name << std::endl;
    // }
    QApplication a(argc, argv);




    MainWindow w;
    w.show();
    return a.exec();
}
