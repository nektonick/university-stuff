#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plus->setChecked(true);
    on_plus_toggled(true);
    clearErrorMessageAndStyleShhets();
    defStyle = "font-size: 16pt;";
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_plus_toggled(bool checked)
{
    if (checked){
        setPlaceHoldersText("слагаемое 1", "слагаемое 2", "сумма");
        operation = '+';
    }
}

void Widget::on_minus_toggled(bool checked)
{
    if (checked){
        setPlaceHoldersText("уменьшаемое", "вычитыаемое", "разность");
        operation = '-';
    }
}

void Widget::on_multiply_toggled(bool checked)
{
    if (checked){
        setPlaceHoldersText("множитель 1", "множитель 2", "произведение");
        operation = '*';
    }
}

void Widget::on_devide_toggled(bool checked)
{
    if (checked){
        setPlaceHoldersText("делимое", "делитель", "разность");
        operation = '/';
    }
}

void Widget::setPlaceHoldersText(QString text1, QString text2, QString text3)
{
    ui->operand1->setPlaceholderText(text1);
    ui->operand2->setPlaceholderText(text2);
    ui->result->setPlaceholderText(text3);
}

void Widget::setRedStylesheet(QWidget *widget)
{
    widget->setStyleSheet(defStyle +
                          "background-color: red;"
                          );
}

QString Widget::generateAnswer()
{
    QString answer;
    if (operation == '+'){
        answer=QString::number(a1+a2);
    }
    else if(operation == '-'){
        answer=QString::number(a1-a2);
    }
    else if(operation == '*'){
        answer=QString::number(a1*a2);
    }
    else if(operation == '/'){
        answer=QString::number(a1/a2);
    }
    else{
        answer="error";
    }
    return answer;

}

void Widget::on_showResult_clicked()
{

    bool ok1,ok2;
    a1 = ui->operand1->text().toLongLong(&ok1);
    a2 = ui->operand2->text().toLongLong(&ok2);
    clearErrorMessageAndStyleShhets(1);
    clearErrorMessageAndStyleShhets(2);
    QString errorMessage = "";
    if (a2 == 0 && ui->devide->isChecked()){
        ok2 = false;
        errorMessage += ("Деление на ноль! ");
    }

    if (!ok1 && !ok2){
        setRedStylesheet(ui->operand1);
        setRedStylesheet(ui->operand2);
        setRedStylesheet(ui->errorMessage);
        errorMessage += ("Неверный ввод в поле 1. ");
        errorMessage += ("Неверный ввод в поле 2. ");
    }
    else if(!ok1){
        setRedStylesheet(ui->operand1);
        setRedStylesheet(ui->errorMessage);
        errorMessage += ("Неверный ввод в поле 1. ");
    }
    else if(!ok2){
        setRedStylesheet(ui->operand2);
        setRedStylesheet(ui->errorMessage);
        errorMessage += ("Неверный ввод в поле 2. ");
    }
    else{
        ui->result->setText(generateAnswer());

    }
    ui->errorMessage->setText(errorMessage);
}

void Widget::clearErrorMessageAndStyleShhets(int operandNum)
{

    ui->errorMessage->setText("");
    if (operandNum == 1)
        ui->operand1->setStyleSheet(defStyle);
    if (operandNum == 2)
        ui->operand2->setStyleSheet(defStyle);
    ui->result->setStyleSheet(defStyle);
    ui->errorMessage->setStyleSheet(defStyle);
}

void Widget::on_operand1_textChanged(const QString &arg1)
{
    clearErrorMessageAndStyleShhets(1);
}

void Widget::on_operand2_textChanged(const QString &arg1)
{
    clearErrorMessageAndStyleShhets(2);
}

void Widget::on_rainbowBackCheckBox_clicked()
{
    if(ui->rainbowBackCheckBox->isChecked()){
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
        timer->start(rand()%1000 + 1);
    }
    else{
        this->setStyleSheet(defStyle);
        timer->stop();
    }
}

void Widget::slotTimerAlarm()
{
    timer->setInterval(rand()%100 + 1);
    timerOffset = (timerOffset + 1) % 1000000;

    this->setStyleSheet(defStyle +
                        "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, "
                        "stop: 0 " + generateGradient(timerOffset%7) + "stop: 0.14 " + generateGradient((timerOffset+1) %7 ) + "stop: 0.28"
                        + generateGradient((timerOffset+2) %7 ) + "stop: 0.40 "+ generateGradient((timerOffset+3) %7 ) + "stop: 0.60"
                        + generateGradient((timerOffset+4) %7 ) + "stop: 0.76 " +  generateGradient((timerOffset +5) %7 ) +
                        "stop:1 " + generateGradient((timerOffset+6) %7 ) + ");"
                        );
    //qDebug()<<this->styleSheet()<<endl<<endl;
}

QString Widget::generateGradient(int stop)
{
// странная, почти рандомная смена цветов:
//    int a = 36 * stop;
//    QString answer = " rgba(" + QString::number(a * timerOffset % 255) + ","
//            + QString::number((255/ 3 + a * timerOffset) % 255) + ","
//            + QString::number((255 / 3 * 2 +a * timerOffset) % 255) + ",255" +"),";

    //придумать, как инвертировать направление
    QString answer="";
    switch (stop) {
    case 0:
        answer = " rgba(255, 0, 0,255)";
        break;
    case 1:
        answer = " rgba(255, 128, 0, 255)";
        break;
    case 2:
        answer = " rgba(255, 255, 0, 255)";
        break;
    case 3:
        answer = " rgba(0, 255, 0, 255)";
        break;
    case 4:
        answer = " rgba(128, 166, 255, 255)";
        break;
    case 5:
        answer = " rgba(0, 0, 255, 255)";
        break;
    case 6:
        answer = " rgba(139, 0, 255, 255)";
        break;
    default:
        answer = " rgba(0, 0, 0, 255)";
        break;
    }
    answer+=",";
    return answer;
}
