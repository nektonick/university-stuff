#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
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
    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_calculateButton_clicked();

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

private:
    Ui::Widget *ui;
    void func1();
    int b1,b2;
};
#endif // WIDGET_H
