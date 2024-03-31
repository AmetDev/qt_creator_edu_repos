/********************************************************************************
** Form generated from reading UI file 'admincheck.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCHECK_H
#define UI_ADMINCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admincheck
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *admincheck)
    {
        if (admincheck->objectName().isEmpty())
            admincheck->setObjectName(QString::fromUtf8("admincheck"));
        admincheck->resize(800, 600);
        centralwidget = new QWidget(admincheck);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        admincheck->setCentralWidget(centralwidget);
        menubar = new QMenuBar(admincheck);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        admincheck->setMenuBar(menubar);
        statusbar = new QStatusBar(admincheck);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        admincheck->setStatusBar(statusbar);

        retranslateUi(admincheck);

        QMetaObject::connectSlotsByName(admincheck);
    } // setupUi

    void retranslateUi(QMainWindow *admincheck)
    {
        admincheck->setWindowTitle(QCoreApplication::translate("admincheck", "admincheck", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admincheck: public Ui_admincheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCHECK_H
