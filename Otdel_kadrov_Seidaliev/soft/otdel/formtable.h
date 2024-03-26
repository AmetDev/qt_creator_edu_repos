#ifndef FORMTABLE_H
#define FORMTABLE_H

#include <QWidget>

namespace Ui {
class FormTable;
}

class FormTable : public QWidget
{
    Q_OBJECT
private slots:
    void connectToDB();
private slots:
    void updateTableView(const QString& tableName);
private slots:
    void addData(const QList<QWidget*>& inputWidgets, const QString& tableName);
public:
    explicit FormTable(QWidget *parent = nullptr);
    ~FormTable();

private:
    Ui::FormTable *ui;
};

#endif // FORMTABLE_H
