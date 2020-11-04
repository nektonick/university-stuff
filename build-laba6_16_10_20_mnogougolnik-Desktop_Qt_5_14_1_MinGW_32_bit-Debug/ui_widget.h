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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *plusRowButton;
    QPushButton *minusRowButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *calculateSButton;
    QPushButton *calculatePButton;
    QTableWidget *tableWidget;
    QGraphicsView *graphicsView;
    QLabel *answer;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        QFont font;
        font.setPointSize(16);
        Widget->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 701, 31));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(680, 210, 96, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plusRowButton = new QPushButton(layoutWidget);
        plusRowButton->setObjectName(QString::fromUtf8("plusRowButton"));

        verticalLayout->addWidget(plusRowButton);

        minusRowButton = new QPushButton(layoutWidget);
        minusRowButton->setObjectName(QString::fromUtf8("minusRowButton"));

        verticalLayout->addWidget(minusRowButton);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(670, 300, 115, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        calculateSButton = new QPushButton(layoutWidget1);
        calculateSButton->setObjectName(QString::fromUtf8("calculateSButton"));

        verticalLayout_2->addWidget(calculateSButton);

        calculatePButton = new QPushButton(layoutWidget1);
        calculatePButton->setObjectName(QString::fromUtf8("calculatePButton"));

        verticalLayout_2->addWidget(calculatePButton);

        tableWidget = new QTableWidget(Widget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(41, 91, 611, 231));
        tableWidget->setFont(font);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(240, 400, 301, 181));
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        answer = new QLabel(Widget);
        answer->setObjectName(QString::fromUtf8("answer"));
        answer->setGeometry(QRect(80, 350, 451, 41));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 420, 141, 111));
        label_2->setWordWrap(true);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\222\320\262\320\276\320\264\320\270\321\202\320\265 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\202\320\276\321\207\320\265\320\272. \320\242\320\276\321\207\320\272\320\270 \320\264\320\260\320\275\321\213 \320\277\320\276 \320\276\320\261\321\205\320\276\320\264\321\203 \320\274\320\275\320\276\320\263\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260", nullptr));
        plusRowButton->setText(QCoreApplication::translate("Widget", "+ \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        minusRowButton->setText(QCoreApplication::translate("Widget", "- \321\201\321\202\321\200\320\276\320\272\320\260", nullptr));
        calculateSButton->setText(QCoreApplication::translate("Widget", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214", nullptr));
        calculatePButton->setText(QCoreApplication::translate("Widget", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 Y", nullptr));
        answer->setText(QCoreApplication::translate("Widget", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\275\320\265 \320\262\320\262\320\265\320\264\320\265\320\275\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217 \321\204\320\270\320\263\321\203\321\200\321\213:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
