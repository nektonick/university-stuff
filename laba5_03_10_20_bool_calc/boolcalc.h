#ifndef BOOLCALC_H
#define BOOLCALC_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QComboBox>

namespace Ui {
class boolcalc;
}

class boolcalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit boolcalc(QWidget *parent = nullptr);
    ~boolcalc();

private slots:
    void updateWindow();
    void on_operation_activated(int index);
    void on_op1_activated(int index);
    void on_op2_activated(int index);
    void on_demonstration_button_clicked();
    void updateDemoState();

private:
    Ui::boolcalc *ui;
    QTimer *timerForDemonstration;
    int timerState = 0;
    bool  isNextOperation = false;
};

#endif // BOOLCALC_H
