#ifndef FORMTABLE_H
#define FORMTABLE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include "admincheck.h" // Assuming admincheck is defined in admincheck.h
#include <QComboBox>
#include <QLabel>
namespace Ui {
class FormTable;
}

class FormTable : public QWidget
{
    Q_OBJECT
private slots:
    void deleteDataById(const QString& tableName, int id);
private slots:
    void connectToDB();
    void deleteData();
private slots:
    void tableButtonClicked();
private:
    QList<QPair<QString, QWidget*>> inputWidgets;
private slots:
    void updateData(const QList<QPair<QString, QWidget*>>& inputWidgets);
private slots:
    void updateTableView(const QString& tableName);
private slots:
    void addData(const QList<QPair<QString, QWidget*>>& inputWidgets, const QString& tableName);
    int checkAdmin(const QString& login, const QString& password, admincheck* w);
    void setIsAdmin(const QString& value);
    void calculateTotalPrice(QComboBox *motherboardComboBox, QComboBox *CPUComboBox, QComboBox *RAMComboBox, QComboBox *ACComboBox, QComboBox *CorpusComboBox, QComboBox *GPUComboBox);
    int getPriceFromComboBox(QComboBox *comboBox);
private:
    int userStatus_; // 1 - admin, 2 - reader

public:
    explicit FormTable(QWidget *parent = nullptr);
    ~FormTable();

private:
    Ui::FormTable *ui;
    QPushButton *deleteButton; // Move deleteButton declaration here
    QLineEdit *idLineEdit; // Move idLineEdit declaration here
    QString currentTableName;
    int sum_price;
    QLabel* sumPriceLabel = nullptr; // Инициализируем указатель nullptr, чтобы убедиться, что он не содержит мусорных данных


};

#endif // FORMTABLE_H
