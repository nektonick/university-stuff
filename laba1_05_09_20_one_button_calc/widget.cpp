#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//отображение введённого текста
void Widget::on_pushMeButton_clicked()
{
    ui->label->setText(ui->lineEdit->text());
    int a;
    a = ui->lineEdit->text().toInt();
    ui->label->setText(QString::number(a*a));
}
