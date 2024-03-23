#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableView>
#include <vector>
#include "booktablemodel.h" // Включаем заголовочный файл для класса BookTableModel

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clickme_clicked();

private:
    Ui::MainWindow *ui;
    BookTableModel bookModel; // Делаем bookModel членом класса MainWindow
};

#endif // MAINWINDOW_H
