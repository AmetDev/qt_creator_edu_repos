/********************************************************************************
** Form generated from reading UI file 'prodaz.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODAZ_H
#define UI_PRODAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Prodaz
{
public:
    QTableView *tableViewProdaz;
    QPushButton *goBackProdazBtn;
    QPushButton *addBtnProdaz;
    QPushButton *updateBtnProdaz;
    QTextEdit *codeProdszInput;
    QTextEdit *deleteInputProdaz;
    QLabel *label;
    QPushButton *deleteBtnProdaz;
    QTextEdit *textPrice;
    QTextEdit *sumInputProdaz;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_10;
    QLabel *label_11;
    QDateEdit *dateEdit;

    void setupUi(QWidget *Prodaz)
    {
        if (Prodaz->objectName().isEmpty())
            Prodaz->setObjectName(QString::fromUtf8("Prodaz"));
        Prodaz->resize(1120, 651);
        tableViewProdaz = new QTableView(Prodaz);
        tableViewProdaz->setObjectName(QString::fromUtf8("tableViewProdaz"));
        tableViewProdaz->setGeometry(QRect(20, 10, 621, 451));
        goBackProdazBtn = new QPushButton(Prodaz);
        goBackProdazBtn->setObjectName(QString::fromUtf8("goBackProdazBtn"));
        goBackProdazBtn->setGeometry(QRect(190, 480, 121, 25));
        addBtnProdaz = new QPushButton(Prodaz);
        addBtnProdaz->setObjectName(QString::fromUtf8("addBtnProdaz"));
        addBtnProdaz->setGeometry(QRect(840, 600, 80, 25));
        updateBtnProdaz = new QPushButton(Prodaz);
        updateBtnProdaz->setObjectName(QString::fromUtf8("updateBtnProdaz"));
        updateBtnProdaz->setGeometry(QRect(950, 600, 80, 25));
        codeProdszInput = new QTextEdit(Prodaz);
        codeProdszInput->setObjectName(QString::fromUtf8("codeProdszInput"));
        codeProdszInput->setGeometry(QRect(840, 50, 201, 31));
        deleteInputProdaz = new QTextEdit(Prodaz);
        deleteInputProdaz->setObjectName(QString::fromUtf8("deleteInputProdaz"));
        deleteInputProdaz->setGeometry(QRect(650, 100, 161, 31));
        label = new QLabel(Prodaz);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 70, 101, 17));
        deleteBtnProdaz = new QPushButton(Prodaz);
        deleteBtnProdaz->setObjectName(QString::fromUtf8("deleteBtnProdaz"));
        deleteBtnProdaz->setGeometry(QRect(690, 140, 80, 25));
        textPrice = new QTextEdit(Prodaz);
        textPrice->setObjectName(QString::fromUtf8("textPrice"));
        textPrice->setGeometry(QRect(840, 410, 201, 31));
        sumInputProdaz = new QTextEdit(Prodaz);
        sumInputProdaz->setObjectName(QString::fromUtf8("sumInputProdaz"));
        sumInputProdaz->setGeometry(QRect(840, 540, 201, 31));
        label_2 = new QLabel(Prodaz);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(850, 20, 91, 17));
        label_3 = new QLabel(Prodaz);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(840, 90, 91, 17));
        label_4 = new QLabel(Prodaz);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(840, 160, 161, 17));
        label_5 = new QLabel(Prodaz);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(840, 230, 161, 17));
        label_6 = new QLabel(Prodaz);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(840, 310, 161, 17));
        label_7 = new QLabel(Prodaz);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(840, 380, 161, 17));
        label_8 = new QLabel(Prodaz);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(840, 450, 161, 17));
        label_9 = new QLabel(Prodaz);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(840, 520, 161, 17));
        comboBox = new QComboBox(Prodaz);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(840, 330, 201, 25));
        comboBox_2 = new QComboBox(Prodaz);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(840, 260, 201, 25));
        label_10 = new QLabel(Prodaz);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(840, 120, 161, 17));
        label_11 = new QLabel(Prodaz);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(750, 180, 321, 41));
        dateEdit = new QDateEdit(Prodaz);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(840, 470, 181, 26));

        retranslateUi(Prodaz);

        QMetaObject::connectSlotsByName(Prodaz);
    } // setupUi

    void retranslateUi(QWidget *Prodaz)
    {
        Prodaz->setWindowTitle(QCoreApplication::translate("Prodaz", "Form", nullptr));
        goBackProdazBtn->setText(QCoreApplication::translate("Prodaz", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\275\320\260\320\267\320\260\320\264", nullptr));
        addBtnProdaz->setText(QCoreApplication::translate("Prodaz", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        updateBtnProdaz->setText(QCoreApplication::translate("Prodaz", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Prodaz", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 ", nullptr));
        deleteBtnProdaz->setText(QCoreApplication::translate("Prodaz", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("Prodaz", "\320\232\320\276\320\264_\320\277\321\200\320\276\320\264\320\260\320\266", nullptr));
        label_3->setText(QCoreApplication::translate("Prodaz", "\320\232\320\276\320\264_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("Prodaz", "\320\232\320\276\320\264_\320\277\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\321\217_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("Prodaz", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265_\320\272\320\275\320\270\320\263\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("Prodaz", "\320\241\320\262\320\265\320\264\320\265\320\275\320\270\321\217_\320\276_\320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("Prodaz", "\320\246\320\265\320\275\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("Prodaz", "\320\224\320\260\321\202\320\260_\320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_9->setText(QCoreApplication::translate("Prodaz", " \320\241\321\203\320\274\320\274\320\260_\320\277\321\200\320\276\320\264\320\260\320\266\320\270", nullptr));
        label_10->setText(QCoreApplication::translate("Prodaz", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label_11->setText(QCoreApplication::translate("Prodaz", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \320\276 \320\277\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Prodaz: public Ui_Prodaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODAZ_H
