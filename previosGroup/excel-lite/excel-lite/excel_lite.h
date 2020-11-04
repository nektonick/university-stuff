#ifndef EXCEL_LITE_H
#define EXCEL_LITE_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class excel_lite; }
QT_END_NAMESPACE

class excel_lite : public QMainWindow
{
    Q_OBJECT

public:
    excel_lite(QWidget *parent = nullptr);
    ~excel_lite();

private slots:
    void on_size_b_clicked();

    void on_size_r_add_clicked();

    void on_size_r_del_clicked();

    void on_size_c_add_clicked();

    void on_size_c_del_clicked();

    void on_find_b_clicked();

    void on_fill_b_clicked();

    void on_table_cellChanged(int row, int column);

    void on_sort_b_clicked();

    void bubble_sort();

    void comb_sort();

    bool is_sorted();

    void monkey_sort();

    int qs_partition(int row, int low, int high);

    void qs(int row, int low, int high);

    void on_remove_duplicates_clicked();

    void on_search_b_clicked();

    int binary_search(int row, int l, int r);

private:
    Ui::excel_lite *ui;
};
#endif // EXCEL_LITE_H
