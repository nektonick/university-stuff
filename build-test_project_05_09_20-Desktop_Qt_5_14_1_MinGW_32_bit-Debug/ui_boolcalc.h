/********************************************************************************
** Form generated from reading UI file 'boolcalc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOLCALC_H
#define UI_BOOLCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_boolcalc
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QComboBox *op1;
    QComboBox *operation;
    QComboBox *op2;
    QPushButton *demonstration_button;

    void setupUi(QMainWindow *boolcalc)
    {
        if (boolcalc->objectName().isEmpty())
            boolcalc->setObjectName(QString::fromUtf8("boolcalc"));
        boolcalc->resize(723, 205);
        QFont font;
        font.setPointSize(20);
        boolcalc->setFont(font);
        centralWidget = new QWidget(boolcalc);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        op1 = new QComboBox(centralWidget);
        op1->addItem(QString());
        op1->addItem(QString());
        op1->setObjectName(QString::fromUtf8("op1"));

        gridLayout->addWidget(op1, 0, 0, 1, 1);

        operation = new QComboBox(centralWidget);
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->addItem(QString());
        operation->setObjectName(QString::fromUtf8("operation"));

        gridLayout->addWidget(operation, 0, 1, 1, 1);

        op2 = new QComboBox(centralWidget);
        op2->addItem(QString());
        op2->addItem(QString());
        op2->setObjectName(QString::fromUtf8("op2"));

        gridLayout->addWidget(op2, 0, 2, 1, 1);

        demonstration_button = new QPushButton(centralWidget);
        demonstration_button->setObjectName(QString::fromUtf8("demonstration_button"));

        gridLayout->addWidget(demonstration_button, 1, 1, 1, 1);

        boolcalc->setCentralWidget(centralWidget);

        retranslateUi(boolcalc);

        QMetaObject::connectSlotsByName(boolcalc);
    } // setupUi

    void retranslateUi(QMainWindow *boolcalc)
    {
        boolcalc->setWindowTitle(QCoreApplication::translate("boolcalc", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\213\321\205", nullptr));
        op1->setItemText(0, QCoreApplication::translate("boolcalc", "False", nullptr));
        op1->setItemText(1, QCoreApplication::translate("boolcalc", "True", nullptr));

        operation->setItemText(0, QCoreApplication::translate("boolcalc", "&& (\320\232\320\276\320\275\321\212\321\216\320\275\320\272\321\206\320\270\321\217)", nullptr));
        operation->setItemText(1, QCoreApplication::translate("boolcalc", "|| (\320\224\320\270\320\267\321\212\321\216\320\275\320\272\321\206\320\270\321\217)", nullptr));
        operation->setItemText(2, QCoreApplication::translate("boolcalc", "\342\212\225 (\320\241\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 \320\274\320\276\320\264\321\203\320\273\321\216 2)", nullptr));
        operation->setItemText(3, QCoreApplication::translate("boolcalc", "=> (\320\230\320\274\320\277\320\273\320\270\320\272\320\260\321\206\320\270\321\217)", nullptr));
        operation->setItemText(4, QCoreApplication::translate("boolcalc", "== (\320\240\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\276)", nullptr));
        operation->setItemText(5, QCoreApplication::translate("boolcalc", "!= (\320\235\320\265\321\200\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\276)", nullptr));
        operation->setItemText(6, QCoreApplication::translate("boolcalc", "! (\320\236\321\202\321\200\320\270\321\206\320\260\320\275\320\270\320\265)", nullptr));
        operation->setItemText(7, QCoreApplication::translate("boolcalc", "| (\320\250\321\202\321\200\320\270\321\205 \320\250\320\265\314\201\321\204\321\204\320\265\321\200\320\260)", nullptr));
        operation->setItemText(8, QCoreApplication::translate("boolcalc", "\342\206\223 (\320\244\321\203\320\275\320\272\321\206\320\270\321\217 \320\222\320\265\320\261\320\261\320\260)", nullptr));

        op2->setItemText(0, QCoreApplication::translate("boolcalc", "False", nullptr));
        op2->setItemText(1, QCoreApplication::translate("boolcalc", "True", nullptr));

        demonstration_button->setText(QCoreApplication::translate("boolcalc", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\264\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class boolcalc: public Ui_boolcalc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOLCALC_H
