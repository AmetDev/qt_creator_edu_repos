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
    struct Book {
        int id;
        string name;
        string typebook;
        string author;
        string izdatelstvo;
        int count_pages;
        // Add more fields as needed
    };
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/amex/library.db");


    if (!db.open()) {
        cout << "Ошибка при открытии базы данных" << endl;
    } else {
        cout << "База данных открыта успешно" << endl;
    }

    QString tableName = "Книги";

    // Create a QSqlTableModel for the table
    QSqlTableModel model;
    model.setTable(tableName);
    model.select();

    // Retrieve the column names
    QSqlRecord record = model.record();


    vector<Book> books;
    // for (int row = 0; row < model.rowCount(); ++row) {
    //     Book book;
    //     for (int col = 0; col < record.count(); ++col) {
    //         if (record.fieldName(col) == "Код_книги") {
    //             book.id = model.record(row).value(col).toInt();
    //         } else if (record.fieldName(col) == "Название") {
    //             book.name = model.record(row).value(col).toString().toStdString();
    //         } else if (record.fieldName(col) == "Жанр") {
    //             book.typebook = model.record(row).value(col).toString().toStdString();
    //         }
    //         else if (record.fieldName(col) == "Авторы") {
    //             book.author = model.record(row).value(col).toString().toStdString();
    //         }
    //         else if (record.fieldName(col) == "Издательство") {
    //             book.izdatelstvo = model.record(row).value(col).toString().toStdString();
    //         }
    //         else if (record.fieldName(col) == "Количество_страниц") {
    //             book.count_pages = model.record(row).value(col).toInt();
    //         }
    //         // Add additional fields as needed
    //     }
    //     books.push_back(book);
    // }
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
    for (const auto& book : books) {
        cout << "Book ID: " << book.id << ", Title: " << book.name << ", Author: " << book.author << ", Type: " << book.typebook
             << ", Publisher: " << book.izdatelstvo << ", Pages: " << book.count_pages << endl;
    }
    // Display the retrieved data
    // for (const auto& book : books) {
    //     cout << "Book ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << endl;
    //     // Output additional fields as needed
    // }
    //db.close();
    // QSqlQuery query;
    // //query.exec("SELECT * FROM Поступление_книги");
    // QSqlQuery query("SELECT * FROM Поступление_книги");
    // while (query.next()) {
    //     // Обработка результатов запроса
    //     QString result = query.value(1).toString(); // Пример: получение значения из первого столбца
    //     QTextStream stream(stdout);
    //     stream << result << endl;
    // }

    // QSqlRecord rec = query.record();

    // int columnCount = rec.count();

    // for (int i = 0; i < columnCount; i++) {
    //     QString columnName = rec.fieldName(i);
    //     // Output the column name using qDebug()
    //     cout << "Column name: " << columnName.toStdString()  << endl;
    // }
    QApplication a(argc, argv);

    // // Создаем объект QTextStream для вывода информации в терминал
    // QTextStream stream(stdout);

    // Выводим информацию в терминал
//stream << "Hello World!" << endl;



    MainWindow w;
    w.show();
    return a.exec();
}
