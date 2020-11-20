#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <ctime>
#include <QDebug>
#include <QTableWidgetItem>
#include <algorithm>
#include <qmessagebox.h>
#include <dialog.h>

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

    void on_deleteDublicatesButton_clicked();

private:

    Ui::Widget *ui;
    bool tableIsOk = false;
    float sum = 0;
    int numOfElements = 0;
    int minRand = 0;
    int maxRand = 200;
    float searchValue=0;
    std::vector<float> arr;

    QPalette defPal = QPalette();
    QPalette redPal;

    void bubbleSort();
    void fastSort();
    void combSort();
    void gnomeSort();
    void monkeySort();
    void fromTableToArrey();
    void fromArreyToTable();
    void search();
    void binarySearch();
    void linearSearch();
    bool initializeArrey();
    bool isTableOK();
    void bogoSort();
    void shuffle();
    bool isSortCorrect();
    void comb();
    void gnome();
    void quickSort(int low, int high);


};


#endif // WIDGET_H
