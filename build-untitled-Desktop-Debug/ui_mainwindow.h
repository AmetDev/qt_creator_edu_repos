/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *postBtn;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextEdit *textEdit_delete;
    QLabel *label_7;
    QPushButton *updateBtnBooks;
    QPushButton *addBtnBooks;
    QPushButton *deleteBtnBooks_2;
    QPushButton *Prodazbtn;
    QTextEdit *textEdit_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1048, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 50, 631, 381));
        postBtn = new QPushButton(centralwidget);
        postBtn->setObjectName(QString::fromUtf8("postBtn"));
        postBtn->setGeometry(QRect(90, 460, 171, 25));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(810, 50, 161, 31));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(810, 110, 161, 31));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(810, 180, 161, 31));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(810, 250, 161, 31));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(810, 320, 161, 31));
        textEdit_6 = new QTextEdit(centralwidget);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setGeometry(QRect(810, 400, 161, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 30, 91, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(810, 90, 91, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(820, 160, 91, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 220, 91, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(820, 290, 91, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(810, 370, 91, 20));
        textEdit_delete = new QTextEdit(centralwidget);
        textEdit_delete->setObjectName(QString::fromUtf8("textEdit_delete"));
        textEdit_delete->setGeometry(QRect(640, 50, 161, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(640, 30, 91, 17));
        updateBtnBooks = new QPushButton(centralwidget);
        updateBtnBooks->setObjectName(QString::fromUtf8("updateBtnBooks"));
        updateBtnBooks->setGeometry(QRect(920, 510, 80, 25));
        addBtnBooks = new QPushButton(centralwidget);
        addBtnBooks->setObjectName(QString::fromUtf8("addBtnBooks"));
        addBtnBooks->setGeometry(QRect(770, 510, 80, 25));
        deleteBtnBooks_2 = new QPushButton(centralwidget);
        deleteBtnBooks_2->setObjectName(QString::fromUtf8("deleteBtnBooks_2"));
        deleteBtnBooks_2->setGeometry(QRect(680, 90, 80, 25));
        Prodazbtn = new QPushButton(centralwidget);
        Prodazbtn->setObjectName(QString::fromUtf8("Prodazbtn"));
        Prodazbtn->setGeometry(QRect(310, 460, 171, 25));
        textEdit_7 = new QTextEdit(centralwidget);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));
        textEdit_7->setGeometry(QRect(810, 470, 161, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(820, 440, 91, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1048, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        postBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\320\265_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\226\320\260\320\275\321\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\321\201\321\202\321\200", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264_\320\272\320\275\320\270\320\263\320\270", nullptr));
        updateBtnBooks->setText(QCoreApplication::translate("MainWindow", "\320\236\320\221\320\235\320\236\320\222\320\230\320\242\320\254", nullptr));
        addBtnBooks->setText(QCoreApplication::translate("MainWindow", "\320\224\320\236\320\221\320\220\320\222\320\230\320\242\320\254", nullptr));
        deleteBtnBooks_2->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        Prodazbtn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\275\320\270\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
