#ifndef ADMINCHECK_H
#define ADMINCHECK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class admincheck;
}
QT_END_NAMESPACE

class admincheck : public QMainWindow
{
    Q_OBJECT

public:
    admincheck(QWidget *parent = nullptr);
    ~admincheck();

private:
    Ui::admincheck *ui;
};
#endif // ADMINCHECK_H
