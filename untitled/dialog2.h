#ifndef DIALOG2_H
#define DIALOG2_H
#include <QSqlError>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QWidget
{

    Q_OBJECT


    // Вектор для хранения книг

    // Функция для загрузки данных из базы данных
    //void loadDataFromDatabase();

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;
    struct BookPost {
        int id;
        int number_document;
        std::string svedeniya;
        int count_ezk;
    };
    QVector<BookPost> booksPost;
private slots:
    void switchToPostuplenieTable();
    // Определение структуры Book
private slots:
    void addNewData();
private slots:
    void UpdateData();
private slots:
    void deleteData();

private slots:
    void closeAndReturnToParent();
public slots:
    void displayDataDialog2(const QString &queryStr);

};

#endif // DIALOG2_H
