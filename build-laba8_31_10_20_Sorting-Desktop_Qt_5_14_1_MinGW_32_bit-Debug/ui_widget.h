/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTableWidget *mainTable;
    QPushButton *randomFill;
    QComboBox *typeOfSorting;
    QPushButton *sortButton;
    QLineEdit *numOfColumns;
    QLineEdit *numOfRows;
    QLineEdit *maxInt;
    QLineEdit *minInt;
    QTextBrowser *textOut;
    QCheckBox *visualCheck;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *getMinButton;
    QPushButton *getMaxButton;
    QPushButton *meanInt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(894, 600);
        QFont font;
        font.setPointSize(16);
        Widget->setFont(font);
        mainTable = new QTableWidget(Widget);
        mainTable->setObjectName(QString::fromUtf8("mainTable"));
        mainTable->setGeometry(QRect(10, 130, 521, 461));
        randomFill = new QPushButton(Widget);
        randomFill->setObjectName(QString::fromUtf8("randomFill"));
        randomFill->setGeometry(QRect(400, 30, 101, 81));
        QFont font1;
        font1.setPointSize(12);
        randomFill->setFont(font1);
        randomFill->setIconSize(QSize(12, 12));
        randomFill->setAutoRepeat(false);
        randomFill->setAutoExclusive(false);
        typeOfSorting = new QComboBox(Widget);
        typeOfSorting->addItem(QString());
        typeOfSorting->addItem(QString());
        typeOfSorting->addItem(QString());
        typeOfSorting->addItem(QString());
        typeOfSorting->addItem(QString());
        typeOfSorting->setObjectName(QString::fromUtf8("typeOfSorting"));
        typeOfSorting->setGeometry(QRect(540, 100, 131, 31));
        sortButton = new QPushButton(Widget);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));
        sortButton->setGeometry(QRect(620, 150, 131, 51));
        numOfColumns = new QLineEdit(Widget);
        numOfColumns->setObjectName(QString::fromUtf8("numOfColumns"));
        numOfColumns->setGeometry(QRect(20, 30, 171, 41));
        numOfRows = new QLineEdit(Widget);
        numOfRows->setObjectName(QString::fromUtf8("numOfRows"));
        numOfRows->setGeometry(QRect(20, 70, 171, 41));
        maxInt = new QLineEdit(Widget);
        maxInt->setObjectName(QString::fromUtf8("maxInt"));
        maxInt->setGeometry(QRect(200, 70, 181, 41));
        minInt = new QLineEdit(Widget);
        minInt->setObjectName(QString::fromUtf8("minInt"));
        minInt->setGeometry(QRect(200, 30, 181, 41));
        textOut = new QTextBrowser(Widget);
        textOut->setObjectName(QString::fromUtf8("textOut"));
        textOut->setGeometry(QRect(550, 200, 281, 391));
        visualCheck = new QCheckBox(Widget);
        visualCheck->setObjectName(QString::fromUtf8("visualCheck"));
        visualCheck->setGeometry(QRect(680, 90, 221, 51));
        visualCheck->setChecked(false);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(530, 30, 302, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        getMinButton = new QPushButton(layoutWidget);
        getMinButton->setObjectName(QString::fromUtf8("getMinButton"));

        horizontalLayout->addWidget(getMinButton);

        getMaxButton = new QPushButton(layoutWidget);
        getMaxButton->setObjectName(QString::fromUtf8("getMaxButton"));

        horizontalLayout->addWidget(getMaxButton);

        meanInt = new QPushButton(layoutWidget);
        meanInt->setObjectName(QString::fromUtf8("meanInt"));

        horizontalLayout->addWidget(meanInt);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        randomFill->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214\n"
" \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\274\320\270\n"
" \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217\320\274\320\270", nullptr));
        typeOfSorting->setItemText(0, QCoreApplication::translate("Widget", "\320\237\321\203\320\267\321\213\321\200\321\214\320\272\320\276\320\274", nullptr));
        typeOfSorting->setItemText(1, QCoreApplication::translate("Widget", "\320\221\321\213\321\201\321\202\321\200\320\260\321\217", nullptr));
        typeOfSorting->setItemText(2, QCoreApplication::translate("Widget", "\320\240\320\260\321\201\321\207\321\221\321\201\320\272\320\260", nullptr));
        typeOfSorting->setItemText(3, QCoreApplication::translate("Widget", "\320\223\320\275\320\276\320\274\321\214\321\217", nullptr));
        typeOfSorting->setItemText(4, QCoreApplication::translate("Widget", "\320\236\320\261\320\265\320\267\321\214\321\217\320\275\321\214\321\217", nullptr));

        sortButton->setText(QCoreApplication::translate("Widget", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        numOfColumns->setText(QString());
        numOfColumns->setPlaceholderText(QCoreApplication::translate("Widget", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\276\320\262", nullptr));
        numOfRows->setText(QString());
        numOfRows->setPlaceholderText(QCoreApplication::translate("Widget", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\276\320\272", nullptr));
        maxInt->setText(QString());
        maxInt->setPlaceholderText(QCoreApplication::translate("Widget", "\320\234\320\260\320\272\321\201. \321\201\320\273\321\203\321\207. \320\267\320\275\320\260\321\207.", nullptr));
        minInt->setText(QString());
        minInt->setPlaceholderText(QCoreApplication::translate("Widget", "\320\234\320\270\320\275. \321\201\320\273\321\203\321\207. \320\267\320\275\320\260\321\207.", nullptr));
        visualCheck->setText(QCoreApplication::translate("Widget", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217  \n"
"(\321\204\320\270\321\207\320\260 \321\202\320\265\321\201\321\202\320\270\321\200\321\203\320\265\321\202\321\201\321\217)", nullptr));
        getMinButton->setText(QCoreApplication::translate("Widget", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274", nullptr));
        getMaxButton->setText(QCoreApplication::translate("Widget", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274", nullptr));
        meanInt->setText(QCoreApplication::translate("Widget", "\320\241\321\200.\320\267\320\275\320\260\321\207.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
