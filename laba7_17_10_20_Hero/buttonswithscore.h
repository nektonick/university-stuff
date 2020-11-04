#ifndef BUTTONSWITHSCORE_H
#define BUTTONSWITHSCORE_H

#include <QWidget>

namespace Ui {
class buttonsWithScore;
}

class buttonsWithScore : public QWidget
{
    Q_OBJECT

public:
    explicit buttonsWithScore(QWidget *parent = nullptr);
    ~buttonsWithScore();
    Ui::buttonsWithScore *buttonsUi;
    int score=0;
    void blockPlus();
    void unblockPlus();
    void setScore(int inputScore);
    void setName(QString name);
signals:
    void plusPressed(int score);
    void minusPressed(int score);

private slots:
    void plus();
    void minus();

private:

};

#endif // BUTTONSWITHSCORE_H
