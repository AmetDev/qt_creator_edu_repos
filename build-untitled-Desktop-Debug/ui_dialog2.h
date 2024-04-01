/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QTableView *TableDialog2;
    QPushButton *addData;
    QPushButton *deleteBtn;
    QPushButton *updatePostBtn;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *gobackBtn;

    void setupUi(QWidget *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName(QString::fromUtf8("Dialog2"));
        Dialog2->resize(964, 627);
        TableDialog2 = new QTableView(Dialog2);
        TableDialog2->setObjectName(QString::fromUtf8("TableDialog2"));
        TableDialog2->setGeometry(QRect(0, 20, 601, 431));
        addData = new QPushButton(Dialog2);
        addData->setObjectName(QString::fromUtf8("addData"));
        addData->setGeometry(QRect(760, 360, 80, 25));
        deleteBtn = new QPushButton(Dialog2);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(640, 180, 80, 25));
        updatePostBtn = new QPushButton(Dialog2);
        updatePostBtn->setObjectName(QString::fromUtf8("updatePostBtn"));
        updatePostBtn->setGeometry(QRect(850, 360, 80, 25));
        textEdit = new QTextEdit(Dialog2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(760, 100, 161, 31));
        textEdit_2 = new QTextEdit(Dialog2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(760, 170, 161, 31));
        textEdit_3 = new QTextEdit(Dialog2);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(760, 240, 161, 31));
        textEdit_4 = new QTextEdit(Dialog2);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(760, 320, 161, 31));
        textEdit_5 = new QTextEdit(Dialog2);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(630, 140, 104, 31));
        label = new QLabel(Dialog2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(760, 80, 161, 17));
        label_2 = new QLabel(Dialog2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(770, 150, 161, 17));
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(770, 210, 161, 17));
        label_4 = new QLabel(Dialog2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(760, 290, 161, 17));
        gobackBtn = new QPushButton(Dialog2);
        gobackBtn->setObjectName(QString::fromUtf8("gobackBtn"));
        gobackBtn->setGeometry(QRect(210, 480, 151, 25));

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QWidget *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Form", nullptr));
        addData->setText(QCoreApplication::translate("Dialog2", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteBtn->setText(QCoreApplication::translate("Dialog2", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        updatePostBtn->setText(QCoreApplication::translate("Dialog2", "\320\236\320\221\320\235\320\236\320\222\320\230\320\242\320\254", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "\320\232\320\276\320\264_\320\277\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\321\217_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog2", "\320\235\320\276\320\274\320\265\321\200_\320\264\320\276\320\272\321\203\320\274\320\265\320\275\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog2", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217_\320\276_\320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog2", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276_\321\215\320\272\320\267\320\265\320\274\320\277\320\273\321\217\321\200\320\276\320\262", nullptr));
        gobackBtn->setText(QCoreApplication::translate("Dialog2", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
