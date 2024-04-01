#include "admincheck.h"
#include "ui_admincheck.h"

admincheck::admincheck(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::admincheck)
{

    ui->setupUi(this);

}

admincheck::~admincheck()
{
    delete ui;

}
