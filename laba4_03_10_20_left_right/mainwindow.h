#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_NoChoice_currentIndexChanged(int index);

    void on_WhiteSheet_currentRowChanged(int currentRow);

    void on_right_clicked();

    void on_left_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
