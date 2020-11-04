#include "buttonswithscore.h"
#include "ui_buttonswithscore.h"

buttonsWithScore::buttonsWithScore(QWidget *parent) :
    QWidget(parent),
    buttonsUi(new Ui::buttonsWithScore)
{
    buttonsUi->setupUi(this);
    buttonsUi->minus->setDisabled(true);
    QObject::connect(buttonsUi->plus, SIGNAL(clicked()),
               this, SLOT(plus()));
    QObject::connect(buttonsUi->minus, SIGNAL(clicked()),
               this, SLOT(minus()));
}

buttonsWithScore::~buttonsWithScore()
{
    delete buttonsUi;
}

void buttonsWithScore::blockPlus()
{
    buttonsUi->plus->setDisabled(true);
}

void buttonsWithScore::unblockPlus()
{
    buttonsUi->plus->setDisabled(false);
}

void buttonsWithScore::setScore(int inputScore)
{
    score = inputScore;
    buttonsUi->score->setText(QString::number(score));
}

void buttonsWithScore::setName(QString name)
{
    buttonsUi->characteristic->setText(name);
}

void buttonsWithScore::plus()
{
    //some logic
    score = buttonsUi->score->text().toUInt();
    ++score;
    buttonsUi->score->setText(QString::number(score));

    if (score > 0){
        buttonsUi->minus->setDisabled(false);
    }
    emit plusPressed(score);

}

void buttonsWithScore::minus()
{
    //some logic
    score = buttonsUi->score->text().toUInt();
    --score;
    buttonsUi->score->setText(QString::number(score));
    if (score<= 0){
        buttonsUi->minus->setDisabled(true);
    }
    emit minusPressed(score);
}

