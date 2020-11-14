#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <ctime>
#include <QDebug>
#include <QTableWidgetItem>
#include <algorithm>

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

    void on_numOfColumns_textChanged(const QString &arg1);

    void on_numOfRows_textChanged(const QString &arg1);

    void on_randomFill_clicked();

    void on_getMinButton_clicked();

    void on_getMaxButton_clicked();

    void on_meanInt_clicked(); //среднее значение

    void on_sortButton_clicked();

    void on_mainTable_itemChanged(QTableWidgetItem *item);

    void on_searchButton_clicked();

private:

    Ui::Widget *ui;
    bool isSortingNow=false;
    bool tableIsOk = true;
    float sum = 0;
    int numOfElements = 0;
    int minRand = 0;
    int maxRand = 200;
    float searchValue=0;

    QPalette defPal = QPalette();
    QPalette redPal;

    void bubbleSort();
    void fastSort();
    void combSort();
    void gnomeSort();
    void monkeySort();
    void fromTableToArrey(float arr[]);
    void fromArreyToTable(float arr[]);
    void search();
    void binarySearch(float *arr, int size);
    void linearSearch(float *arr, int size);
    bool isTableOK();


};

//вспомогательные функции, не являющиеся членами класса:
void bogoSort(float *arr, int size);
void shuffle(float *arr, int size);
bool isSortCorrect(float *arr, int size);
void comb(float *arr, int size);
void gnome(float *arr, int size);
void qsortRecursive(float *arr, int size);

#endif // WIDGET_H
