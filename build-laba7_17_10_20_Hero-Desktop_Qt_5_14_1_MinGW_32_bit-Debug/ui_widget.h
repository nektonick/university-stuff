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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *informationLabel1;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *informationLabel3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *classLabel;
    QLineEdit *heroClass;
    QHBoxLayout *horizontalLayout_5;
    QLabel *HPLabel;
    QLineEdit *HP;
    QHBoxLayout *horizontalLayout_6;
    QLabel *physDamageLabel;
    QLineEdit *physDamage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *magicDamageLabel;
    QLineEdit *magicDamage;
    QHBoxLayout *horizontalLayout_8;
    QLabel *physResistLabel;
    QLineEdit *physResist;
    QHBoxLayout *horizontalLayout_9;
    QLabel *magicResistLabel;
    QLineEdit *magicResist;
    QHBoxLayout *horizontalLayout_10;
    QLabel *traidingLabel;
    QLineEdit *traiding;
    QHBoxLayout *horizontalLayout_11;
    QLabel *luckyLabel;
    QLineEdit *lucky;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_12;
    QLabel *nameLabel;
    QLineEdit *name;
    QHBoxLayout *horizontalLayout_13;
    QLabel *totalScoresLabel;
    QLineEdit *totalScores;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *sexLabel;
    QHBoxLayout *horizontalLayout;
    QRadioButton *maleButton;
    QRadioButton *femaleButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ageLabel;
    QLineEdit *age;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *inputLayout;
    QLabel *informationLabel2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *phys;
    QPushButton *minusButton1;
    QLineEdit *physScore;
    QPushButton *plusButton1;
    QHBoxLayout *horizontalLayout_16;
    QLabel *intellect;
    QPushButton *minusButton2;
    QLineEdit *intellectScore;
    QPushButton *plusButton2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *social;
    QPushButton *minusButton3;
    QLineEdit *socialScore;
    QPushButton *plusButton3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *godsLabel;
    QPushButton *minusButton4;
    QLineEdit *luckyScore;
    QPushButton *plusButton4;
    QPushButton *creataButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(950, 452);
        Widget->setMinimumSize(QSize(950, 0));
        QFont font;
        font.setPointSize(16);
        Widget->setFont(font);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        informationLabel1 = new QLabel(Widget);
        informationLabel1->setObjectName(QString::fromUtf8("informationLabel1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(informationLabel1->sizePolicy().hasHeightForWidth());
        informationLabel1->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(24);
        informationLabel1->setFont(font1);

        gridLayout->addWidget(informationLabel1, 0, 0, 1, 1, Qt::AlignHCenter);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        informationLabel3 = new QLabel(Widget);
        informationLabel3->setObjectName(QString::fromUtf8("informationLabel3"));

        verticalLayout_2->addWidget(informationLabel3, 0, Qt::AlignHCenter);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        classLabel = new QLabel(Widget);
        classLabel->setObjectName(QString::fromUtf8("classLabel"));
        classLabel->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(classLabel);

        heroClass = new QLineEdit(Widget);
        heroClass->setObjectName(QString::fromUtf8("heroClass"));
        heroClass->setMinimumSize(QSize(0, 0));
        heroClass->setMaximumSize(QSize(230, 16777215));
        heroClass->setReadOnly(true);

        horizontalLayout_4->addWidget(heroClass);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        HPLabel = new QLabel(Widget);
        HPLabel->setObjectName(QString::fromUtf8("HPLabel"));
        HPLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_5->addWidget(HPLabel);

        HP = new QLineEdit(Widget);
        HP->setObjectName(QString::fromUtf8("HP"));
        HP->setMaximumSize(QSize(60, 16777215));
        HP->setReadOnly(true);

        horizontalLayout_5->addWidget(HP);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        physDamageLabel = new QLabel(Widget);
        physDamageLabel->setObjectName(QString::fromUtf8("physDamageLabel"));
        physDamageLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_6->addWidget(physDamageLabel);

        physDamage = new QLineEdit(Widget);
        physDamage->setObjectName(QString::fromUtf8("physDamage"));
        physDamage->setMaximumSize(QSize(60, 16777215));
        physDamage->setReadOnly(true);

        horizontalLayout_6->addWidget(physDamage);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        magicDamageLabel = new QLabel(Widget);
        magicDamageLabel->setObjectName(QString::fromUtf8("magicDamageLabel"));
        magicDamageLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_7->addWidget(magicDamageLabel);

        magicDamage = new QLineEdit(Widget);
        magicDamage->setObjectName(QString::fromUtf8("magicDamage"));
        magicDamage->setMaximumSize(QSize(60, 16777215));
        magicDamage->setReadOnly(true);

        horizontalLayout_7->addWidget(magicDamage);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        physResistLabel = new QLabel(Widget);
        physResistLabel->setObjectName(QString::fromUtf8("physResistLabel"));
        physResistLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_8->addWidget(physResistLabel);

        physResist = new QLineEdit(Widget);
        physResist->setObjectName(QString::fromUtf8("physResist"));
        physResist->setMaximumSize(QSize(60, 16777215));
        physResist->setReadOnly(true);

        horizontalLayout_8->addWidget(physResist);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        magicResistLabel = new QLabel(Widget);
        magicResistLabel->setObjectName(QString::fromUtf8("magicResistLabel"));
        magicResistLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_9->addWidget(magicResistLabel);

        magicResist = new QLineEdit(Widget);
        magicResist->setObjectName(QString::fromUtf8("magicResist"));
        magicResist->setMaximumSize(QSize(60, 16777215));
        magicResist->setReadOnly(true);

        horizontalLayout_9->addWidget(magicResist);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        traidingLabel = new QLabel(Widget);
        traidingLabel->setObjectName(QString::fromUtf8("traidingLabel"));
        traidingLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_10->addWidget(traidingLabel);

        traiding = new QLineEdit(Widget);
        traiding->setObjectName(QString::fromUtf8("traiding"));
        traiding->setMaximumSize(QSize(60, 16777215));
        traiding->setReadOnly(true);

        horizontalLayout_10->addWidget(traiding);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        luckyLabel = new QLabel(Widget);
        luckyLabel->setObjectName(QString::fromUtf8("luckyLabel"));
        luckyLabel->setMinimumSize(QSize(180, 0));

        horizontalLayout_11->addWidget(luckyLabel);

        lucky = new QLineEdit(Widget);
        lucky->setObjectName(QString::fromUtf8("lucky"));
        lucky->setMaximumSize(QSize(60, 16777215));
        lucky->setReadOnly(true);

        horizontalLayout_11->addWidget(lucky);


        verticalLayout_2->addLayout(horizontalLayout_11);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, verticalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setContentsMargins(-1, -1, 20, -1);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        nameLabel = new QLabel(Widget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout_12->addWidget(nameLabel);

        name = new QLineEdit(Widget);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_12->addWidget(name);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        totalScoresLabel = new QLabel(Widget);
        totalScoresLabel->setObjectName(QString::fromUtf8("totalScoresLabel"));

        horizontalLayout_13->addWidget(totalScoresLabel);

        totalScores = new QLineEdit(Widget);
        totalScores->setObjectName(QString::fromUtf8("totalScores"));
        totalScores->setMaximumSize(QSize(90, 16777215));
        totalScores->setReadOnly(true);

        horizontalLayout_13->addWidget(totalScores);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_13);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(2, QFormLayout::LabelRole, verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sexLabel = new QLabel(Widget);
        sexLabel->setObjectName(QString::fromUtf8("sexLabel"));

        horizontalLayout_2->addWidget(sexLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        maleButton = new QRadioButton(Widget);
        maleButton->setObjectName(QString::fromUtf8("maleButton"));
        maleButton->setChecked(true);

        horizontalLayout->addWidget(maleButton);

        femaleButton = new QRadioButton(Widget);
        femaleButton->setObjectName(QString::fromUtf8("femaleButton"));

        horizontalLayout->addWidget(femaleButton);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout);


        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ageLabel = new QLabel(Widget);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setWordWrap(true);

        horizontalLayout_3->addWidget(ageLabel);

        age = new QLineEdit(Widget);
        age->setObjectName(QString::fromUtf8("age"));
        age->setMaximumSize(QSize(40, 16777215));
        age->setMaxLength(3);

        horizontalLayout_3->addWidget(age);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(4, QFormLayout::LabelRole, verticalSpacer);

        inputLayout = new QVBoxLayout();
        inputLayout->setObjectName(QString::fromUtf8("inputLayout"));
        informationLabel2 = new QLabel(Widget);
        informationLabel2->setObjectName(QString::fromUtf8("informationLabel2"));

        inputLayout->addWidget(informationLabel2, 0, Qt::AlignHCenter);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        phys = new QLabel(Widget);
        phys->setObjectName(QString::fromUtf8("phys"));

        horizontalLayout_17->addWidget(phys);

        minusButton1 = new QPushButton(Widget);
        minusButton1->setObjectName(QString::fromUtf8("minusButton1"));
        minusButton1->setEnabled(false);
        minusButton1->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_17->addWidget(minusButton1);

        physScore = new QLineEdit(Widget);
        physScore->setObjectName(QString::fromUtf8("physScore"));
        physScore->setEnabled(false);
        physScore->setMaximumSize(QSize(50, 16777215));
        physScore->setReadOnly(true);

        horizontalLayout_17->addWidget(physScore);

        plusButton1 = new QPushButton(Widget);
        plusButton1->setObjectName(QString::fromUtf8("plusButton1"));
        plusButton1->setEnabled(false);
        plusButton1->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_17->addWidget(plusButton1);


        inputLayout->addLayout(horizontalLayout_17);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        intellect = new QLabel(Widget);
        intellect->setObjectName(QString::fromUtf8("intellect"));

        horizontalLayout_16->addWidget(intellect);

        minusButton2 = new QPushButton(Widget);
        minusButton2->setObjectName(QString::fromUtf8("minusButton2"));
        minusButton2->setEnabled(false);
        minusButton2->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_16->addWidget(minusButton2);

        intellectScore = new QLineEdit(Widget);
        intellectScore->setObjectName(QString::fromUtf8("intellectScore"));
        intellectScore->setEnabled(false);
        intellectScore->setMaximumSize(QSize(50, 16777215));
        intellectScore->setReadOnly(true);

        horizontalLayout_16->addWidget(intellectScore);

        plusButton2 = new QPushButton(Widget);
        plusButton2->setObjectName(QString::fromUtf8("plusButton2"));
        plusButton2->setEnabled(false);
        plusButton2->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_16->addWidget(plusButton2);


        inputLayout->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        social = new QLabel(Widget);
        social->setObjectName(QString::fromUtf8("social"));

        horizontalLayout_15->addWidget(social);

        minusButton3 = new QPushButton(Widget);
        minusButton3->setObjectName(QString::fromUtf8("minusButton3"));
        minusButton3->setEnabled(false);
        minusButton3->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_15->addWidget(minusButton3);

        socialScore = new QLineEdit(Widget);
        socialScore->setObjectName(QString::fromUtf8("socialScore"));
        socialScore->setEnabled(false);
        socialScore->setMaximumSize(QSize(50, 16777215));
        socialScore->setReadOnly(true);

        horizontalLayout_15->addWidget(socialScore);

        plusButton3 = new QPushButton(Widget);
        plusButton3->setObjectName(QString::fromUtf8("plusButton3"));
        plusButton3->setEnabled(false);
        plusButton3->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_15->addWidget(plusButton3);


        inputLayout->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        godsLabel = new QLabel(Widget);
        godsLabel->setObjectName(QString::fromUtf8("godsLabel"));

        horizontalLayout_14->addWidget(godsLabel);

        minusButton4 = new QPushButton(Widget);
        minusButton4->setObjectName(QString::fromUtf8("minusButton4"));
        minusButton4->setEnabled(false);
        minusButton4->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_14->addWidget(minusButton4);

        luckyScore = new QLineEdit(Widget);
        luckyScore->setObjectName(QString::fromUtf8("luckyScore"));
        luckyScore->setEnabled(false);
        luckyScore->setMaximumSize(QSize(50, 16777215));
        luckyScore->setReadOnly(true);

        horizontalLayout_14->addWidget(luckyScore);

        plusButton4 = new QPushButton(Widget);
        plusButton4->setObjectName(QString::fromUtf8("plusButton4"));
        plusButton4->setEnabled(false);
        plusButton4->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_14->addWidget(plusButton4);


        inputLayout->addLayout(horizontalLayout_14);


        formLayout->setLayout(5, QFormLayout::SpanningRole, inputLayout);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        creataButton = new QPushButton(Widget);
        creataButton->setObjectName(QString::fromUtf8("creataButton"));
        QFont font2;
        font2.setPointSize(18);
        creataButton->setFont(font2);

        gridLayout_2->addWidget(creataButton, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\223\320\265\321\200\320\276\320\270 \320\270 \320\223\320\265\321\200\320\276\320\270\320\275\320\270", nullptr));
        informationLabel1->setText(QCoreApplication::translate("Widget", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260", nullptr));
        informationLabel3->setText(QCoreApplication::translate("Widget", "\320\245\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270", nullptr));
        classLabel->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\273\320\260\321\201\321\201\320\260", nullptr));
        HPLabel->setText(QCoreApplication::translate("Widget", "\320\227\320\264\320\276\321\200\320\276\320\262\321\214\320\265", nullptr));
        physDamageLabel->setText(QCoreApplication::translate("Widget", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr));
        magicDamageLabel->setText(QCoreApplication::translate("Widget", "\320\234\320\260\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\203\321\200\320\276\320\275", nullptr));
        physResistLabel->setText(QCoreApplication::translate("Widget", "\320\244\320\270\320\267. \320\267\320\260\321\211\320\270\321\202\320\260", nullptr));
        magicResistLabel->setText(QCoreApplication::translate("Widget", "\320\241\321\202\320\270\321\205\320\270\320\271\320\275\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260", nullptr));
        traidingLabel->setText(QCoreApplication::translate("Widget", "\320\221\320\260\321\200\321\202\320\265\321\200", nullptr));
        luckyLabel->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\321\207\320\260", nullptr));
        nameLabel->setText(QCoreApplication::translate("Widget", "\320\230\320\274\321\217 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260:", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("Widget", "\320\234\321\203\320\266\320\270\320\272 \321\201\320\276 \321\201\320\272\320\260\320\273\321\213", nullptr));
        totalScoresLabel->setText(QCoreApplication::translate("Widget", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276 \320\265\320\264\320\270\320\275\320\270\321\206 \320\275\320\260\320\262\321\213\320\272\320\276\320\262:", nullptr));
        totalScores->setPlaceholderText(QString());
        sexLabel->setText(QCoreApplication::translate("Widget", "\320\237\320\276\320\273", nullptr));
        maleButton->setText(QCoreApplication::translate("Widget", "\320\234", nullptr));
        femaleButton->setText(QCoreApplication::translate("Widget", "\320\226", nullptr));
        ageLabel->setText(QCoreApplication::translate("Widget", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        age->setText(QString());
        age->setPlaceholderText(QCoreApplication::translate("Widget", "18", nullptr));
        informationLabel2->setText(QCoreApplication::translate("Widget", "\320\235\320\260 \321\207\321\202\320\276 \320\262\321\213 \321\202\321\200\320\260\321\202\320\270\320\273\320\270 \320\262\321\200\320\265\320\274\321\217?", nullptr));
        phys->setText(QCoreApplication::translate("Widget", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\202\321\200\320\265\320\275\320\270\321\200\320\276\320\262\320\272\320\270", nullptr));
        minusButton1->setText(QCoreApplication::translate("Widget", "-", nullptr));
        physScore->setText(QCoreApplication::translate("Widget", "0", nullptr));
        plusButton1->setText(QCoreApplication::translate("Widget", "+", nullptr));
        intellect->setText(QCoreApplication::translate("Widget", "\320\247\321\202\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263", nullptr));
        minusButton2->setText(QCoreApplication::translate("Widget", "-", nullptr));
        intellectScore->setText(QCoreApplication::translate("Widget", "11", nullptr));
        plusButton2->setText(QCoreApplication::translate("Widget", "+", nullptr));
        social->setText(QCoreApplication::translate("Widget", "\320\236\320\261\321\211\320\265\320\275\320\270\320\265 \321\201 \320\273\321\216\320\264\321\214\320\274\320\270", nullptr));
        minusButton3->setText(QCoreApplication::translate("Widget", "-", nullptr));
        socialScore->setText(QCoreApplication::translate("Widget", "1", nullptr));
        plusButton3->setText(QCoreApplication::translate("Widget", "+", nullptr));
        godsLabel->setText(QCoreApplication::translate("Widget", "\320\234\320\276\320\273\320\270\321\202\320\262\321\213 \320\261\320\276\320\263\320\260\320\274", nullptr));
        minusButton4->setText(QCoreApplication::translate("Widget", "-", nullptr));
        luckyScore->setText(QCoreApplication::translate("Widget", "1", nullptr));
        plusButton4->setText(QCoreApplication::translate("Widget", "+", nullptr));
        creataButton->setText(QCoreApplication::translate("Widget", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
