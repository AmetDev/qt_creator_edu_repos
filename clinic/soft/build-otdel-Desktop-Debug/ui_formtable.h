/********************************************************************************
** Form generated from reading UI file 'formtable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTABLE_H
#define UI_FORMTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTable
{
public:
    QTableView *tableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTable;
    QPushButton *pushUpdate;

    void setupUi(QWidget *FormTable)
    {
        if (FormTable->objectName().isEmpty())
            FormTable->setObjectName(QString::fromUtf8("FormTable"));
        FormTable->resize(1300, 816);
        tableView = new QTableView(FormTable);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 50, 751, 421));
        verticalLayoutWidget = new QWidget(FormTable);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(830, 40, 191, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(FormTable);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(1070, 0, 201, 651));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(FormTable);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(300, 500, 241, 91));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelTable = new QLabel(FormTable);
        labelTable->setObjectName(QString::fromUtf8("labelTable"));
        labelTable->setGeometry(QRect(290, 20, 151, 17));
        pushUpdate = new QPushButton(FormTable);
        pushUpdate->setObjectName(QString::fromUtf8("pushUpdate"));
        pushUpdate->setGeometry(QRect(880, 650, 111, 41));

        retranslateUi(FormTable);

        QMetaObject::connectSlotsByName(FormTable);
    } // setupUi

    void retranslateUi(QWidget *FormTable)
    {
        FormTable->setWindowTitle(QCoreApplication::translate("FormTable", "Form", nullptr));
        labelTable->setText(QCoreApplication::translate("FormTable", "TextLabel", nullptr));
        pushUpdate->setText(QCoreApplication::translate("FormTable", "update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTable: public Ui_FormTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTABLE_H
