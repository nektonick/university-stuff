#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QValidator>
#include <buttonswithscore.h>

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
    void on_maleButton_clicked();

    void on_femaleButton_clicked();

    void on_age_textChanged(const QString &arg1);

    void on_name_textChanged(const QString &arg1);

    void on_plusButton1_clicked();

    void on_plusButton2_clicked();

    void on_plusButton3_clicked();

    void on_plusButton4_clicked();

    void on_minusButton1_clicked();

    void on_minusButton2_clicked();

    void on_minusButton3_clicked();

    void on_minusButton4_clicked();

    void on_creataButton_clicked();

    void onPlusButtonClicked(int score);
    void onMinusButtonClicked(int score);

private:
    Ui::Widget *ui;
    QString name = "";
    QString getHeroClass();
    bool isMale = true;
    int age=18;

    int availableScores = 1;
    int maxScores = 1;
    int calculateMaxScores();
    void blockPlusButtons(bool blockOrUnblock);
    void blockMinusButtons(bool blockOrUnblock);

    QString className="";
    const QString maleClasses[4] = {"Воин", "Чародей", "Разбойник", "Монах"};
    const QString femaleClasses[4] = {"Амазонка", "Чародейка", "Гарпия", "Монахиня"};
    QString getClassName();
    int characteristics[7]={0};
    int scores[4]={0};
    QLineEdit *scoresEdits[4] = {nullptr};
    QLineEdit *characteristicsEdits[7] = {nullptr};
    QPushButton *plusButtons[4]={nullptr};
    QPushButton *minusButtons[4]={nullptr};
    QColor getPaletteBycharacteristic(int value);
    void resetScores();
    void resetCharacteristics();
    void updateStats();
    void updateCharacteristics();

    buttonsWithScore inputWidget[4];


};
#endif // WIDGET_H
