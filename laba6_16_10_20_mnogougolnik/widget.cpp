#include "widget.h"
#include "ui_widget.h"


typedef std::pair<float, float> pt;
inline int area (pt a, pt b, pt c) {
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

inline bool intersect_1 (int a, int b, int c, int d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) < min(b,d);
}

bool intersect (pt a, pt b, pt c, pt d) {
    return intersect_1 (a.first, b.first, c.first, d.first)
        && intersect_1 (a.second, b.second, c.second, d.second)
        && area(a,b,c) * area(a,b,d) < 0
        && area(c,d,a) * area(c,d,b) < 0;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()/2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_calculateSButton_clicked()
{
    readTableAndShowAnswer("Площадь");
}

void Widget::on_calculatePButton_clicked()
{
    readTableAndShowAnswer("Периметр");
}

void Widget::on_plusRowButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Widget::on_minusRowButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

float Widget::getS()
{
    float localAns=0;
    for(size_t i = 0; i < polygon.size(); ++i)
    {
        if(i != polygon.size() - 1)
            localAns += (polygon[i].first * polygon[i + 1].second - polygon[i].second * polygon[i + 1].first);
        else
            localAns += (polygon[i].first * polygon[0].second - polygon[i].second * polygon[0].first);
    }

    return abs(localAns)/2;
}

float Widget::getP()
{
    float localAns=0;
    for (int i=1; i <= polygon.size(); ++i){
        localAns += sqrt( pow(polygon[i%polygon.size()].first - polygon[(i-1)%polygon.size()].first, 2) + pow(polygon[i%polygon.size()].second - polygon[(i-1)%polygon.size()].second, 2));
    }
    return localAns;
}

void Widget::readTableAndShowAnswer(QString name)
{
    polygon.clear();
    isEverythingOk = true;
    numOfPoints = ui->tableWidget->rowCount();

    for (int i=0; i<numOfPoints; ++i){
        bool ok1 = false, ok2 = false;
        float x,y;
        if (ui->tableWidget->item(i,0) != nullptr && ui->tableWidget->item(i,1) != nullptr){
            ok1= true; ok2=true;
            x = ui->tableWidget->item(i,0)->text().toFloat(&ok1);
            y = ui->tableWidget->item(i,1)->text().toFloat(&ok2);
        }

        if (!(ok1 && ok2))
            isEverythingOk = false;
        else{
            polygon.push_back(std::pair<float, float>(x, y));
        }
    }
    for (int i=0; i<=polygon.size(); ++i){
        for (int j=i; j<=polygon.size(); ++j){
            if (intersect(polygon[i%polygon.size()], polygon[(i+1)%polygon.size()], polygon[j%polygon.size()], polygon[(j+1)%polygon.size()])){
                isIntersect = true;
                drawPhigure();
                if (name == "Площадь"){
                    answer = "Обноружено самопересечение фигуры";
                    ui->answer->setText(answer);
                }
                else{
                    ui->answer->setText("Периметр = " + QString::number(getP()));
                }
                return;
            }
        }
    }
    if (isEverythingOk){
        if (numOfPoints <3 ){
            answer= "Вырожденный случай";
        }
        else{
            drawPhigure();
            answer = (name == "Периметр") ? QString::number(getP()) :  QString::number(getS());
        }
    }
    else {
        answer="Некорректный ввод";
    }
    ui->answer->setText(name+ "=" + answer);
}

void Widget::drawPhigure()
{
    //ui->graphicsView->centerOn(QPoint(ui->graphicsView->width()/2, ui->graphicsView->height()/2));
    scene = new QGraphicsScene(0, 0, ui->graphicsView->viewport()->width(), ui->graphicsView->viewport()->height() );
    for (int i=1; i <= polygon.size(); ++i){
        scene->addLine(QLine(polygon[(i-1)%polygon.size()].first, polygon[(i-1)%polygon.size()].second, polygon[i%polygon.size()].first, polygon[i%polygon.size()].second));
    }
    QRectF rect = scene->itemsBoundingRect();
    //ui->graphicsView->centerOn(ui->tableWidget->width()/2, ui->tableWidget->height()/2);
    ui->graphicsView->fitInView(rect, Qt::KeepAspectRatio);
    ui->graphicsView->setScene(scene);
}

void Widget::on_tableWidget_itemChanged(QTableWidgetItem *item)
{

    if (item != nullptr){
        bool ok;
        item->text().toFloat(&ok);
        if (!ok){
            item->setBackground(QBrush(Qt::red));
        }
        else {
            item->setBackground(QBrush(Qt::white));
        }
    }
}
