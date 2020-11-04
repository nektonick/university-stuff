/********************************************************************************
** Form generated from reading UI file 'buttonswithscore.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONSWITHSCORE_H
#define UI_BUTTONSWITHSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buttonsWithScore
{
public:
    QGridLayout *gridLayout;
    QPushButton *plus;
    QLineEdit *score;
    QPushButton *minus;
    QLabel *characteristic;

    void setupUi(QWidget *buttonsWithScore)
    {
        if (buttonsWithScore->objectName().isEmpty())
            buttonsWithScore->setObjectName(QString::fromUtf8("buttonsWithScore"));
        buttonsWithScore->resize(138, 51);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(30);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(buttonsWithScore->sizePolicy().hasHeightForWidth());
        buttonsWithScore->setSizePolicy(sizePolicy);
        buttonsWithScore->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setPointSize(16);
        buttonsWithScore->setFont(font);
        gridLayout = new QGridLayout(buttonsWithScore);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plus = new QPushButton(buttonsWithScore);
        plus->setObjectName(QString::fromUtf8("plus"));
        plus->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(plus, 0, 3, 1, 1);

        score = new QLineEdit(buttonsWithScore);
        score->setObjectName(QString::fromUtf8("score"));
        score->setMaximumSize(QSize(30, 16777215));
        score->setReadOnly(true);

        gridLayout->addWidget(score, 0, 2, 1, 1);

        minus = new QPushButton(buttonsWithScore);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(minus, 0, 1, 1, 1);

        characteristic = new QLabel(buttonsWithScore);
        characteristic->setObjectName(QString::fromUtf8("characteristic"));

        gridLayout->addWidget(characteristic, 0, 0, 1, 1);


        retranslateUi(buttonsWithScore);

        QMetaObject::connectSlotsByName(buttonsWithScore);
    } // setupUi

    void retranslateUi(QWidget *buttonsWithScore)
    {
        buttonsWithScore->setWindowTitle(QCoreApplication::translate("buttonsWithScore", "Form", nullptr));
        plus->setText(QCoreApplication::translate("buttonsWithScore", "+", nullptr));
        score->setText(QCoreApplication::translate("buttonsWithScore", "0", nullptr));
        minus->setText(QCoreApplication::translate("buttonsWithScore", "-", nullptr));
        characteristic->setText(QCoreApplication::translate("buttonsWithScore", "\320\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buttonsWithScore: public Ui_buttonsWithScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONSWITHSCORE_H
