#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <ctime>
#include <QDebug>
#include <QTableWidgetItem>
#include <algorithm>
#include <QTimer>

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
    void updateTime();

    void on_numOfColumns_textChanged(const QString &arg1);

    void on_numOfRows_textChanged(const QString &arg1);

    void on_randomFill_clicked();

    void on_getMinButton_clicked();

    void on_getMaxButton_clicked();

    void on_meanInt_clicked();

    void on_sortButton_clicked();

    void on_mainTable_itemChanged(QTableWidgetItem *item);

    void on_visualCheck_stateChanged(int arg1);

private:

    Ui::Widget *ui;
    void bubbleSort();
    void fastSort();
    void combSort();
    void gnomeSort();
    void monkeySort();
    bool isSortingNow=false;
    bool tableIsOk = true;
    bool isTableOK();
    bool isVisualize;
    float sum = 0;
    int numOfElements = 0;
    int minRand = 0;
    int maxRand = 200;
    QPalette defPal = QPalette();
    QPalette redPal;

    //---
    //нужно для визуализации сортировки
    int ii=0, jj=0;
    int prev =0;
    int ssize;
    QTimer *tmr;
    std::vector<float> aarr;
    //---

};
#endif // WIDGET_H
