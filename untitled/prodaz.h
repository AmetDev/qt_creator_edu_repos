#ifndef PRODAZ_H
#define PRODAZ_H

#include <QWidget>

namespace Ui {
class Prodaz;
}

class Prodaz : public QWidget
{
    Q_OBJECT
private:
    int global_code_post_books;
    std::string global_name_books;
    int global_code_post_sved;
    std::string global_name_post_sved;
private slots:
    void deleteObjProdaz();
private slots:
    void addSvedeniya();
private slots:
    void updateObjProdaz();

private slots:
    void displayDataProdaz(const QString &queryStr);
private slots:
    void addNewObjProdaz();
private slots:
    void addItemNameBook();
private slots:
    void comboBoxActivated(int index);
private slots:
    void comboBoxActivatedSved(int index);
public:
    explicit Prodaz(QWidget *parent = nullptr);
    ~Prodaz();

private:
    Ui::Prodaz *ui;
    struct ProdazStruct {
        int code_prodaz;
        int code_books;
        int code_post_books;
        std::string name_book;
        std::string sved_postav;
        int price;
        std::string dataname;
        int sum_price;
    };
    QVector<ProdazStruct> Prodazs;
};

#endif // PRODAZ_H
