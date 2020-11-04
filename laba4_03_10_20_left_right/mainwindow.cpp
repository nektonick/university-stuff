#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NoChoice_currentIndexChanged(int index)
{

}

void MainWindow::on_WhiteSheet_currentRowChanged(int currentRow)
{

}

void MainWindow::on_right_clicked()
{
    int index=ui->NoChoice->currentIndex();
    QString item=ui->NoChoice->currentText();
    ui->WhiteSheet->addItem(item);
    ui->NoChoice->removeItem(index);
}

void MainWindow::on_left_clicked()
{
    int index1=ui->WhiteSheet->currentRow();
    if (index1<0){
        return;
    }
    QString item= ui->WhiteSheet->item(index1)->text();
    int index2=ui->NoChoice->currentIndex();
    ui->NoChoice->insertItem(index1,item);
    QListWidgetItem *item1=ui->WhiteSheet->takeItem(index1);
    delete item1;
}
