#ifndef SAF_H
#define SAF_H

#include <QWidget>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class saf; }
QT_END_NAMESPACE

class saf : public QMainWindow
{
    Q_OBJECT

public:
    saf(QWidget *parent = nullptr);
    ~saf();

private slots:
    void on_size_b_clicked();

    void on_size_del_clicked();

    void on_size_add_clicked();

    void on_fill_b_clicked();

    void on_sort_b_clicked();

    int qs_partition(int a[], int low, int high);

    void qs(int a[], int low, int high);

    bool is_sorted(int a[], int n);

    void monkey_sort(int a[],int n);

    void bubble_sort(int a[],int n);

    void comb_sort(int a[],int n);

    void gnome_sort(int a[], int n);

    void on_table_cellChanged(int row, int column);

    void on_del_dub_clicked();

    int binary_search(int l, int r);

    void on_find_b_clicked();

private:
    Ui::saf *ui;
};
#endif // SAF_H
