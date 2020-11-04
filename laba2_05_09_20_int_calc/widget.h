#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_plus_toggled(bool checked);
    void on_minus_toggled(bool checked);
    void on_multiply_toggled(bool checked);
    void on_devide_toggled(bool checked);
    void on_showResult_clicked();
    void on_operand1_textChanged(const QString &arg1);
    void on_operand2_textChanged(const QString &arg1);
    void on_rainbowBackCheckBox_clicked();
    void slotTimerAlarm();

private:
    Ui::Widget *ui;
    qlonglong a1 = -1;
    qlonglong a2 = -1;
    void clearErrorMessageAndStyleShhets(int operandNum=0);
    void setPlaceHoldersText(QString text1, QString text2, QString text3);
    void setRedStylesheet(QWidget* widget);
    QString generateAnswer();
    QTimer *timer;
    int timerOffset=1;
    QChar operation ='+';
    QString defStyle;
    QString generateGradient(int stop);
};

#endif // WIDGET_H
