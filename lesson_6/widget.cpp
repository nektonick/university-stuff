#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->tableWidget->setColumnWidth(0, 300);
    ui->tableWidget->setRowCount(5);
    //func1();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::func1()
{
    //QTableWidgetItem * item = new QTableWidgetItem("Sazonov");
    //ui->tableWidget->setItem(0,0, item);
    //а можно и так:
    //ui->tableWidget->setItem(0,0, new QTableWidgetItem("Sazonov"));

    for (int i=0; i <ui->tableWidget->rowCount(); ++i){
        for (int j=0; j< ui->tableWidget->columnCount(); ++j){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem("" + QString::number(rand()%100000000)));
        }
    }
}


void Widget::on_plusButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Widget::on_minusButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void Widget::on_calculateButton_clicked()
{
    for (int row=0; row <ui->tableWidget->rowCount(); ++row){
        QTableWidgetItem *it1 = ui->tableWidget->item(row,1);
        QTableWidgetItem *it2 = ui->tableWidget->item(row,2);

        if(it1 != nullptr && it2 != nullptr){
            QString val1 = it1->text();
            QString val2 = it2->text();
            bool ok1,ok2;
            int a1 = val1.toDouble(&ok1);
            int a2 = val2.toDouble(&ok2);

            if (ok1 && ok2){
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(a1*a2)));
                continue;
            }
            if (!ok1){
                it1->setBackground(Qt::magenta);
                it1->setForeground(Qt::white);
            }
        }


    }
}

void Widget::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    //вызывает крах программы
    /*bool ok1;
    bool ok2;

    if (item != nullptr && item->column()<ui->tableWidget->columnCount()){
        b1= item->text().toFloat(&ok1);
        if (item->column() == 1 &&ok1){
            b2 = ui->tableWidget->item(item->row(), item->column()+1)->text().toFloat(&ok2);
        }
        else{
            if (item->column() == 2 &&ok1){
                b2 = ui->tableWidget->item(item->row(), item->column()-1) ->text().toFloat(&ok2);
            }
            else{
                ok1=false; ok2=false;
                b2=0;
            }
        }



        if (ok2 && ok1){
                    QTableWidgetItem * item2 = new QTableWidgetItem(QString::number(b1*b2));
            ui->tableWidget->setItem(item->row(), 3, item2);
        }
    }
    */
}
