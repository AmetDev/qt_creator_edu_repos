// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void displayData(const QString &queryStr);

private slots:
    void ToSwtchNewForm();
private slots:
    void AddNewDataBooks();
private slots:
    void UpdateNewDataBooks();
private slots:
    void DeleteNewDataBooks();
private slots:
    void ToSwitchProdazForm();


private:
    Ui::MainWindow *ui;

    // Определение структуры Book
    struct Book {
        int id;
        std::string name;
        std::string typebook;
        std::string author;
        std::string izdatelstvo;
        int count_pages;
        int count_books;
    };


    // Вектор для хранения книг
    QVector<Book> books;

    // Функция для загрузки данных из базы данных
    void loadDataFromDatabase();
};

#endif // MAINWINDOW_H
