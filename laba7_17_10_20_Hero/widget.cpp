#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i=0; i<4; ++i){

        ui->inputLayout->addWidget(&inputWidget[i]);
        QObject::connect(&inputWidget[i], SIGNAL(plusPressed(int)),
                   this, SLOT(onPlusButtonClicked(int)));
        QObject::connect(&inputWidget[i], SIGNAL(minusPressed(int)),
                   this, SLOT(onMinusButtonClicked(int)));

    }
    inputWidget[0].setName("Силовые тренировки");
    inputWidget[1].setName("Чтение книг");
    inputWidget[2].setName("Взаимодействие с людьми");
    inputWidget[3].setName("Молитвы");

    scoresEdits[0] = ui->physScore;
    scoresEdits[1] = ui->intellectScore;
    scoresEdits[2] = ui->socialScore;
    scoresEdits[3] = ui->luckyScore;
    characteristicsEdits[0] = ui->HP;
    characteristicsEdits[1] = ui->physDamage;
    characteristicsEdits[2] = ui->magicDamage;
    characteristicsEdits[3] = ui->physResist;
    characteristicsEdits[4] = ui->magicResist;
    characteristicsEdits[5] = ui->traiding;
    characteristicsEdits[6] = ui->lucky;
    plusButtons[0] = ui->plusButton1;
    plusButtons[1] = ui->plusButton2;
    plusButtons[2] = ui->plusButton3;
    plusButtons[3] = ui->plusButton4;
    minusButtons[0] = ui->minusButton1;
    minusButtons[1] = ui->minusButton2;
    minusButtons[2] = ui->minusButton3;
    minusButtons[3] = ui->minusButton4;
    age = 18;
    maxScores = calculateMaxScores();
    availableScores = maxScores;
    ui->age->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    blockMinusButtons(true);
    updateStats();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_maleButton_clicked()
{
    isMale=true;
    updateStats();
}

void Widget::on_femaleButton_clicked()
{
    isMale = false;
    updateStats();
}

void Widget::on_age_textChanged(const QString &arg1)
{
    bool isOk;
    arg1.toInt(&isOk);
    if (isOk){
        age = arg1.toInt();
    }
    maxScores = calculateMaxScores();
    resetScores();
    blockMinusButtons(true);
    updateStats();
}

void Widget::on_name_textChanged(const QString &arg1)
{
    name = arg1;
}

void Widget::on_plusButton1_clicked()
{
    //onPlusButtonClicked(0);
}

void Widget::on_plusButton2_clicked()
{
    //onPlusButtonClicked(1);
}

void Widget::on_plusButton3_clicked()
{
    //onPlusButtonClicked(2);
}

void Widget::on_plusButton4_clicked()
{
    //onPlusButtonClicked(3);
}

void Widget::on_minusButton1_clicked()
{
    //onMinusButtonClicked(0);
}

void Widget::on_minusButton2_clicked()
{
    //onMinusButtonClicked(1);
}

void Widget::on_minusButton3_clicked()
{
    //onMinusButtonClicked(2);
}

void Widget::on_minusButton4_clicked()
{
    //onMinusButtonClicked(3);
}

QString Widget::getHeroClass()
{
    QString heroClass = "warrior";
    //logic
    return heroClass;
}

int Widget::calculateMaxScores()
{
    int ans;
    if (age < 25){
        ans = age/3.5;
    }
    else{
        if (age <50){
            ans = age / 5;
        }
        else{
            ans = 10;
        }
    }

    return ans;
}

void Widget::blockPlusButtons(bool blockOrUnblock)
{
    if (blockOrUnblock){
        for (int i =0; i< 4; ++i){
            inputWidget[i].blockPlus();
        }
    }
    else{
        for (int i =0; i< 4; ++i){
            inputWidget[i].unblockPlus();
        }
    }
}

void Widget::blockMinusButtons(bool blockOrUnblock)
{

}

QString Widget::getClassName()
{
    QString className="";
    int ans=0;
    for (unsigned int i=0; i<sizeof(scoresEdits)/sizeof(*scoresEdits); ++i){
        if (scores[i] > scores[ans]){
            ans = i;
        }
    }
    className = (isMale) ? maleClasses[ans] : femaleClasses[ans];
    return className;
}

QColor Widget::getPaletteBycharacteristic(int value)
{
    QColor ans;
    if (value <= 0){
        ans=(Qt::red);
    }
    else{
        if (value <= 3){
            ans=(Qt::yellow);
        }
        else{
                ans=(Qt::green);
        }
    }
    return ans;
}

void Widget::onPlusButtonClicked(int score)
{
    --availableScores;
    qDebug()<<score<<endl;
    if (availableScores <= 0){
        blockPlusButtons(true);
    }
    blockMinusButtons(false);
    updateStats();

    qDebug()<<"on plus clicked logic"<<endl;
}

void Widget::onMinusButtonClicked(int score)
{
    ++availableScores;
    qDebug()<<score<<endl;
    //--scores[buttonNumber];
    if (score<=0)
        blockMinusButtons(true);

    blockPlusButtons(false);
    updateStats();
    qDebug()<<"on minus clicked logic"<<endl;
}

void Widget::resetScores()
{
    for (int i =0 ; i<4; ++i){
        inputWidget[i].setScore(0);
    }
    blockPlusButtons(false);
    availableScores = calculateMaxScores();
}

void Widget::resetCharacteristics()
{
    for (unsigned int i=0; i < sizeof(characteristics)/sizeof(*characteristics); ++i){
        characteristics[i]=0;
    }
    updateCharacteristics();
}

void Widget::updateStats()
{
    //qDebug()<<"updating..."<<endl;

    (isMale)? ui->maleButton->setChecked(true) : ui->femaleButton->setChecked(true);

    for (unsigned int i=0; i<sizeof(scoresEdits)/sizeof(*scoresEdits); ++i){
        scores[i] = inputWidget[i].score;
        if (scoresEdits[i] != nullptr){
            scoresEdits[i]->setText(QString::number(inputWidget[i].score));
        }
        else{
            qDebug()<<i<<endl;
        }
    }
    for (unsigned int i=0; i<sizeof(characteristicsEdits)/sizeof(*characteristicsEdits); ++i){
        if (characteristicsEdits[i] != nullptr){
            characteristicsEdits[i]->setText(QString::number(characteristics[i]));
        }
        else{
            qDebug()<<i<<endl;
        }
    }
    ui->heroClass->setText(getHeroClass());
    ui->totalScores->setText(QString::number(availableScores));

    ui->age->setText(QString::number(age));

    updateCharacteristics();
}

void Widget::updateCharacteristics()
{
    className = getClassName();
    ui->heroClass->setText(className);
    characteristics[0] = 15 * scores[0] - 2 * scores[1] - 3 * scores[2] - scores[3]; //HP
    characteristics[1] = 1.5 * scores[0]; // p dmg
    characteristics[2] = 1.5 * scores[1] + 2 * scores[3]; // m dmg
    characteristics[3] = scores[0]; //p res
    characteristics[4] = scores[1] + scores[3];  //m res
    characteristics[5] =5 * scores[2];  //trade
    characteristics[6] =3 * scores[3];   //lucky

    for (unsigned int i=0; i < sizeof(characteristicsEdits)/sizeof(*characteristicsEdits); ++i){
        characteristicsEdits[i]->setText(QString::number(characteristics[i]));
        QPalette pal;
        pal.setColor(QPalette::Base, getPaletteBycharacteristic(characteristics[i]));
        characteristicsEdits[i]->setPalette(pal);
    }

}

void Widget::on_creataButton_clicked()
{
    bool isOk=true;
    QString message="";
    if (name == ""){
        isOk = false;
        message = "Введите имя";
    }
    for (unsigned int i =0 ; i < sizeof(characteristics)/sizeof(*characteristics); ++i){
        if (characteristics[i]<=0){
            isOk = false;
            message = "Неверные характеристики";
        }
    }
    if (age <14){
        isOk=false;
        message = "Ваш персонаж слишком юн для путешествия";
    }

    if(isOk){
        QMessageBox::information(this, "Создание персонажа", "Персонаж успешно создан");
    }
    else{
        QMessageBox::warning(this, "Создание персонажа", "Ошибка создания персонажа \n" + message);
    }
}
