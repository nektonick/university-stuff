#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <vector>
#include <cmath>
#include <QTableWidgetItem>
#include <QGraphicsScene>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_calculateSButton_clicked();

    void on_calculatePButton_clicked();

    void on_plusRowButton_clicked();

    void on_minusRowButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    bool isEverythingOk;
    int numOfPoints;
    float s;
    float p;
    bool isIntersect;
    Ui::Widget *ui;
    QString answer;
    std::vector<std::pair<float, float>> polygon;

    float getS();
    float getP();
    void readTableAndShowAnswer(QString name);
    void drawPhigure();
    QGraphicsScene * scene;
};
#endif // WIDGET_H
