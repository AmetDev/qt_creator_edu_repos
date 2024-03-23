#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // определяем данные для модели

    QStandardItemModel* model=  new QStandardItemModel(3, 2); // 3 строки, 2 столбца
    model->setItem(0, 0, new QStandardItem("Tom"));
    model->setItem(0, 1, new QStandardItem("39"));
    model->setItem(1, 0, new QStandardItem("Bob"));
    model->setItem(1, 1, new QStandardItem("43"));
    model->setItem(2, 0, new QStandardItem("Sam"));
    model->setItem(2, 1, new QStandardItem("28"));

    // установка заголовков таблицы
    model->setHeaderData(0, Qt::Horizontal, "Name");
    model->setHeaderData(1, Qt::Horizontal, "Age");

    // определяем представление
    QTableView *view = new QTableView(this);
    // устанавливаем модель для представления
    view->setModel(model);

    view->setMinimumSize(400, 300); // устанавливаем минимальный размер представления

    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clickme_clicked()
{
    QMessageBox::information(this, "Alert", "Button Clicked!");
}
