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

private:
    Ui::Widget *ui;
    qreal a1 = 0;
    qreal a2 = 0;
    void clearErrorMessageAndStyleShhets(int operandNum=0);
    void setPlaceHoldersText(QString text1, QString text2, QString text3);
    void setRedStylesheet(QWidget* widget);
    QString generateAnswer();
    QChar operation ='+';
    QString defStyle;
};

#endif // WIDGET_H
