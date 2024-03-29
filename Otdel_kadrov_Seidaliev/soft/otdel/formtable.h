#ifndef FORMTABLE_H
#define FORMTABLE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
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

public:
    explicit FormTable(QWidget *parent = nullptr);
    ~FormTable();

private:
    Ui::FormTable *ui;
    QPushButton *deleteButton; // Move deleteButton declaration here
    QLineEdit *idLineEdit; // Move idLineEdit declaration here
    QString currentTableName;
};

#endif // FORMTABLE_H
