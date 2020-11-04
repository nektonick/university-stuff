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
    widget->setStyleSheet(defStyle + "background-color: red;");
}

QString Widget::generateAnswer()
{
    QString answer;
    if (operation == '+'){
        if(a1+a2 == qInf())
            answer = "мы ограничены бесконечностью";
        else
            answer=QString::number(a1+a2);
    }
    else if(operation == '-'){
        if(a1-a2 == qInf())
            answer = "мы ограничены бесконечностью";
        else
            answer=QString::number(a1-a2);
    }
    else if(operation == '*'){
        if(a1*a2 == qInf())
            answer = "мы ограничены бесконечностью";
        else
            answer=QString::number(a1*a2);
    }
    else if(operation == '/'){
        if(a1/a2 == qInf())
            answer = "мы ограничены бесконечностью";
        else
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
    a1 = ui->operand1->text().toDouble(&ok1);
    a2 = ui->operand2->text().toDouble(&ok2);
    QString errorMessage = "";
    if (a2 == 0 && ui->devide->isChecked()){
        ok2 = false;
        errorMessage += ("Деление на ноль! ");
    }
    if (!ok1 && !ok2){
        setRedStylesheet(ui->operand1); setRedStylesheet(ui->operand2); setRedStylesheet(ui->errorMessage);
        errorMessage += ("Неверный ввод в поле 1. "); errorMessage += ("Неверный ввод в поле 2. ");
    }
    else if(!ok1){
        setRedStylesheet(ui->operand1); setRedStylesheet(ui->errorMessage);
        errorMessage += ("Неверный ввод в поле 1. ");
    }
    else if(!ok2){
        setRedStylesheet(ui->operand2); setRedStylesheet(ui->errorMessage);
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
