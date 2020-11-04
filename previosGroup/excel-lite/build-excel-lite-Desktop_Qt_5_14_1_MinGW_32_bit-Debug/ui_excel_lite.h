/********************************************************************************
** Form generated from reading UI file 'excel_lite.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCEL_LITE_H
#define UI_EXCEL_LITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_excel_lite
{
public:
    QWidget *centralwidget;
    QTableWidget *table;
    QComboBox *find;
    QComboBox *sort;
    QComboBox *fill;
    QPushButton *sort_b;
    QPushButton *find_b;
    QPushButton *fill_b;
    QLabel *find_output;
    QSpinBox *size_r;
    QSpinBox *size_c;
    QPushButton *size_b;
    QPushButton *size_r_add;
    QPushButton *size_r_del;
    QPushButton *size_c_add;
    QPushButton *size_c_del;
    QLabel *error;
    QPushButton *remove_duplicates;
    QSpinBox *search;
    QPushButton *search_b;
    QPlainTextEdit *search_output;
    QLabel *sort_status;
    QComboBox *search_set;
    QLabel *remove_duplicates_error;

    void setupUi(QMainWindow *excel_lite)
    {
        if (excel_lite->objectName().isEmpty())
            excel_lite->setObjectName(QString::fromUtf8("excel_lite"));
        excel_lite->resize(1000, 520);
        centralwidget = new QWidget(excel_lite);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        table = new QTableWidget(centralwidget);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(0, 90, 801, 400));
        find = new QComboBox(centralwidget);
        find->addItem(QString());
        find->addItem(QString());
        find->addItem(QString());
        find->addItem(QString());
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(0, 0, 100, 30));
        sort = new QComboBox(centralwidget);
        sort->addItem(QString());
        sort->addItem(QString());
        sort->addItem(QString());
        sort->addItem(QString());
        sort->addItem(QString());
        sort->setObjectName(QString::fromUtf8("sort"));
        sort->setGeometry(QRect(0, 60, 100, 30));
        fill = new QComboBox(centralwidget);
        fill->addItem(QString());
        fill->addItem(QString());
        fill->setObjectName(QString::fromUtf8("fill"));
        fill->setGeometry(QRect(0, 30, 100, 30));
        sort_b = new QPushButton(centralwidget);
        sort_b->setObjectName(QString::fromUtf8("sort_b"));
        sort_b->setGeometry(QRect(100, 60, 50, 30));
        find_b = new QPushButton(centralwidget);
        find_b->setObjectName(QString::fromUtf8("find_b"));
        find_b->setGeometry(QRect(100, 0, 50, 30));
        fill_b = new QPushButton(centralwidget);
        fill_b->setObjectName(QString::fromUtf8("fill_b"));
        fill_b->setGeometry(QRect(100, 30, 50, 30));
        find_output = new QLabel(centralwidget);
        find_output->setObjectName(QString::fromUtf8("find_output"));
        find_output->setGeometry(QRect(150, 0, 100, 30));
        find_output->setAlignment(Qt::AlignCenter);
        size_r = new QSpinBox(centralwidget);
        size_r->setObjectName(QString::fromUtf8("size_r"));
        size_r->setGeometry(QRect(250, 0, 50, 30));
        size_c = new QSpinBox(centralwidget);
        size_c->setObjectName(QString::fromUtf8("size_c"));
        size_c->setGeometry(QRect(300, 0, 50, 30));
        size_b = new QPushButton(centralwidget);
        size_b->setObjectName(QString::fromUtf8("size_b"));
        size_b->setGeometry(QRect(250, 30, 100, 30));
        size_r_add = new QPushButton(centralwidget);
        size_r_add->setObjectName(QString::fromUtf8("size_r_add"));
        size_r_add->setGeometry(QRect(250, 60, 25, 30));
        size_r_del = new QPushButton(centralwidget);
        size_r_del->setObjectName(QString::fromUtf8("size_r_del"));
        size_r_del->setGeometry(QRect(275, 60, 25, 30));
        size_c_add = new QPushButton(centralwidget);
        size_c_add->setObjectName(QString::fromUtf8("size_c_add"));
        size_c_add->setGeometry(QRect(300, 60, 25, 30));
        size_c_del = new QPushButton(centralwidget);
        size_c_del->setObjectName(QString::fromUtf8("size_c_del"));
        size_c_del->setGeometry(QRect(325, 60, 25, 30));
        error = new QLabel(centralwidget);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(150, 60, 100, 30));
        error->setAlignment(Qt::AlignCenter);
        remove_duplicates = new QPushButton(centralwidget);
        remove_duplicates->setObjectName(QString::fromUtf8("remove_duplicates"));
        remove_duplicates->setGeometry(QRect(900, 0, 100, 30));
        search = new QSpinBox(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(800, 0, 101, 32));
        search_b = new QPushButton(centralwidget);
        search_b->setObjectName(QString::fromUtf8("search_b"));
        search_b->setGeometry(QRect(800, 60, 100, 30));
        search_output = new QPlainTextEdit(centralwidget);
        search_output->setObjectName(QString::fromUtf8("search_output"));
        search_output->setGeometry(QRect(799, 90, 201, 401));
        sort_status = new QLabel(centralwidget);
        sort_status->setObjectName(QString::fromUtf8("sort_status"));
        sort_status->setGeometry(QRect(0, 490, 71, 30));
        sort_status->setAlignment(Qt::AlignCenter);
        search_set = new QComboBox(centralwidget);
        search_set->addItem(QString());
        search_set->addItem(QString());
        search_set->setObjectName(QString::fromUtf8("search_set"));
        search_set->setGeometry(QRect(800, 30, 100, 30));
        remove_duplicates_error = new QLabel(centralwidget);
        remove_duplicates_error->setObjectName(QString::fromUtf8("remove_duplicates_error"));
        remove_duplicates_error->setGeometry(QRect(900, 30, 100, 30));
        remove_duplicates_error->setAlignment(Qt::AlignCenter);
        excel_lite->setCentralWidget(centralwidget);

        retranslateUi(excel_lite);

        QMetaObject::connectSlotsByName(excel_lite);
    } // setupUi

    void retranslateUi(QMainWindow *excel_lite)
    {
        excel_lite->setWindowTitle(QCoreApplication::translate("excel_lite", "excel_lite", nullptr));
        find->setItemText(0, QCoreApplication::translate("excel_lite", "MIN", nullptr));
        find->setItemText(1, QCoreApplication::translate("excel_lite", "MAX", nullptr));
        find->setItemText(2, QCoreApplication::translate("excel_lite", "ARITH", nullptr));
        find->setItemText(3, QCoreApplication::translate("excel_lite", "SUM", nullptr));

        sort->setItemText(0, QCoreApplication::translate("excel_lite", "QSORT", nullptr));
        sort->setItemText(1, QCoreApplication::translate("excel_lite", "MONKEY", nullptr));
        sort->setItemText(2, QCoreApplication::translate("excel_lite", "COMB", nullptr));
        sort->setItemText(3, QCoreApplication::translate("excel_lite", "BUBBLE", nullptr));
        sort->setItemText(4, QCoreApplication::translate("excel_lite", "GNOME", nullptr));

        fill->setItemText(0, QCoreApplication::translate("excel_lite", "ZERO", nullptr));
        fill->setItemText(1, QCoreApplication::translate("excel_lite", "RANDOM", nullptr));

        sort_b->setText(QCoreApplication::translate("excel_lite", "SORT", nullptr));
        find_b->setText(QCoreApplication::translate("excel_lite", "FIND", nullptr));
        fill_b->setText(QCoreApplication::translate("excel_lite", "FILL", nullptr));
        find_output->setText(QString());
        size_b->setText(QCoreApplication::translate("excel_lite", "SET", nullptr));
        size_r_add->setText(QCoreApplication::translate("excel_lite", "+", nullptr));
        size_r_del->setText(QCoreApplication::translate("excel_lite", "-", nullptr));
        size_c_add->setText(QCoreApplication::translate("excel_lite", "+", nullptr));
        size_c_del->setText(QCoreApplication::translate("excel_lite", "-", nullptr));
        error->setText(QString());
        remove_duplicates->setText(QCoreApplication::translate("excel_lite", "DEL DBLCT", nullptr));
        search_b->setText(QCoreApplication::translate("excel_lite", "search", nullptr));
        sort_status->setText(QCoreApplication::translate("excel_lite", "unsorted", nullptr));
        search_set->setItemText(0, QCoreApplication::translate("excel_lite", "LINE", nullptr));
        search_set->setItemText(1, QCoreApplication::translate("excel_lite", "BINARY", nullptr));

        remove_duplicates_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class excel_lite: public Ui_excel_lite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCEL_LITE_H
