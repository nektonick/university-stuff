#include "boolcalc.h"
#include "ui_boolcalc.h"

boolcalc::boolcalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::boolcalc)
{
    ui->setupUi(this);


    ui->op1->setLayoutDirection(Qt::RightToLeft);

    ui->op2->setStyleSheet("QComboBox::drop-down:!editable { background: transparent; border: none;}"
                           "QComboBox::down-arrow {image: url(arrow.png); left: -140;}"
                           "QComboBox{padding-left: 35px};"
                           "font-size: 20px;"
                           );
    updateWindow();
    timerForDemonstration = new QTimer(this);
    timerForDemonstration->setInterval(1200);
    connect(timerForDemonstration, SIGNAL(timeout()), this, SLOT(updateDemoState()));
}

boolcalc::~boolcalc()
{
    delete ui;
}

void boolcalc::updateWindow()
{
    bool o1 = (ui->op1->currentText()=="True"); // то же что и bool o1 = ui->op1->currentIndex();
    bool o2 = (ui->op2->currentText()=="True"); // то же что и bool o2 = ui->op2->currentIndex();
    bool result = true;
    QPalette true_pallete, false_pallete;
    true_pallete.setColor(QPalette::Window, QColor(0,255,0));
    false_pallete.setColor(QPalette::Window, QColor(255,0,0));

    ui->op1->setVisible(true);

    switch(ui->operation->currentIndex())
    {
    case 0: //&&
        result = o1&&o2;
        break;
    case 1: //||
        result = o1||o2;
        break;
    case 2: //XOR
        result = (o1^o2);
        break;
    case 3:   //=>
        result = ((!o1) || o2);
        break;
    case 4: // ==
        result = (o1 == o2);
        break;
    case 5: // !=
        result = (o1 != o2);
        break;
    case 6: //(!o2)
        ui->op1->setVisible(false);
        result = !o2;
        break;
    case 7: // |
        result = (!o1 || !o2);
        break;
    case 8: // ↓
        result = (!o1 && !o2);
        break;
    }
    (result == true)? qApp->setPalette(true_pallete) : qApp->setPalette(false_pallete);
}

void boolcalc::on_operation_activated(int)
{
    updateWindow();
}
void boolcalc::on_op1_activated(int)
{
    updateWindow();
}
void boolcalc::on_op2_activated(int)
{
    updateWindow();
}


// код ниже отвечает за "режим демонстрации"
void boolcalc::on_demonstration_button_clicked()
{
    if (timerForDemonstration->isActive()){
        timerForDemonstration->stop();
    }
    else{
        timerForDemonstration->start();
    }
}

void boolcalc::updateDemoState()
{
    switch (timerState) {
    case 0:
        ui->op1->setCurrentIndex(0);
        ui->op2->setCurrentIndex(0);
        timerState++;
        if (isNextOperation){
            ui->operation->setCurrentIndex((ui->operation->currentIndex()+1)%ui->operation->count());
            isNextOperation = false;
        }
        break;
    case 1:
        ui->op1->setCurrentIndex(0);
        ui->op2->setCurrentIndex(1);
        timerState++;
        break;
    case 2:
        ui->op1->setCurrentIndex(1);
        ui->op2->setCurrentIndex(0);
        timerState++;
        break;
    case 3:
        ui->op1->setCurrentIndex(1);
        ui->op2->setCurrentIndex(1);
        timerState = 0;
        isNextOperation = true;
        break;

    default:
        qDebug()<<"что-то пошло не так";
        break;
    }

    updateWindow();
}
