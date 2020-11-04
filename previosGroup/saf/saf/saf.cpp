#include "saf.h"
#include "ui_saf.h"

saf::saf(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::saf)
{
    ui->setupUi(this);
    ui->size_n->setMinimum(0);
    ui->size_n->setMaximum(200);
    ui->find_n->setMinimum(-1000);
    ui->find_o->setReadOnly(true);
    ui->kostil->setVisible(false);
}

saf::~saf()
{
    delete ui;
}

//---Элементы изменения размера таблицы---
void saf::on_size_b_clicked()
{
    //Обработка числового значения при нажатии кнопки
    ui->sort_status->setText("Не сорт");
    ui->sort_error->clear();
    ui->find_o->clear();
    ui->table->setRowCount(ui->size_n->value());
    int r = ui->table->rowCount();
    for(int i = 0;i<r;i++)
    {
        if(ui->table->item(i,0)==nullptr)
        {
            QTableWidgetItem *pitem;
            pitem = new QTableWidgetItem;
            ui->table->setItem(i,0,pitem);
        }
    }

}

void saf::on_size_del_clicked()
{
    //Кнопка минус
    ui->sort_status->setText("Не сорт");
    ui->sort_error->clear();
    ui->find_o->clear();
    ui->table->setRowCount(ui->table->rowCount()-1);
    ui->size_n->setValue(ui->size_n->value()-1);

}

void saf::on_size_add_clicked()
{
    //Кнопка плюс
    ui->sort_status->setText("Не сорт");
    ui->sort_error->clear();
    ui->find_o->clear();
    ui->table->setRowCount(ui->table->rowCount()+1);
    if(ui->table->item(ui->table->rowCount()-1,0)==nullptr)
    {
        QTableWidgetItem *pitem;
        pitem = new QTableWidgetItem;
        ui->table->setItem(ui->table->rowCount()-1,0,pitem);
    }
    ui->size_n->setValue(ui->size_n->value()+1);
}
//---Элементы изменения размера таблицы---

//---Заполнение таблицы---
void saf::on_fill_b_clicked()
{
    if(!ui->table->rowCount())
    {
        ui->fill_error->setText("Пустой массив");
        return;
    }

    ui->sort_status->setText("Не сорт");
    ui->sort_error->clear();
    ui->fill_error->clear();
    int r = ui->table->rowCount();
    for(int i = 0;i<r;i++)
    {
        if(ui->table->item(i,0)==nullptr)
        {
            QTableWidgetItem *pitem;
            pitem = new QTableWidgetItem;
            ui->table->setItem(i,0,pitem);
        }
        srand((unsigned int)clock());
        int value = ui->fill_s->currentIndex()?((rand()%201-100)):0;
        ui->table->item(i,0)->setText(QString::number(value));
    }

}
//---Заполнение таблицы---

//---Быстрая сортировка---
int saf::qs_partition(int a[], int low, int high)
{
    int pivot = a[(low+high)/2];
    int i = low;
    int j = high;
    while (i <= j)
    {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
        if (low < j)

                   qs_partition(a, low, j);

             if (i < high)

                   qs_partition(a, i, high);
    }

    /*
    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    int t = a[i+1];
    a[i+1] = a[high];
    a[high] = t;
    return (i+1);
    */
}

void saf::qs(int a[], int low, int high)
{
    if(low < high)
    {
        int p = qs_partition(a,low,high);
        qs(a,low,p-1);
        qs(a,p+1,high);
    }
}
//---Быстрая сортировка---

//---Случайная сортировка---
bool saf::is_sorted(int a[], int n)
{
    for(int i = 1; i < n; i++)
        if(a[i-1] > a[i])
            return false;
    return true;
}

void saf::monkey_sort(int a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        srand((unsigned int)clock());
        int random = abs(rand()%n);

        int t = a[i];
        a[i] = a[random];
        a[random] = t;
    }
}
//---Случайная сортировка---

//---Пузырьковые сортировки---
void saf::comb_sort(int a[],int n)
{
    int gap = n;
    bool swapped = true;

    while(gap != 1 || swapped)
    {
        if(gap >= 1) gap = (gap*10)/13;
        else gap = 1;

        swapped = false;

        for(int i = 0; i<n-gap; i++)
        {
            if(a[i]>a[i+gap])
            {
                int t = a[i];
                a[i] = a[i+gap];
                a[i+gap] = t;

                swapped = true;
            }
        }
    }
}

void saf::bubble_sort(int a[],int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < (n-i-1); j++)
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}
//---Пузырьковые сортировки---

//---Гномья сортировка---
void saf::gnome_sort(int a[], int n)
{
    int index = 0;

    while(index < n)
    {
        if(!index)
            index++;
        if(a[index] >= a[index-1])
            index++;
        else
        {
            int t = a[index];
            a[index] = a[index-1];
            a[index-1] = t;
            index--;
        }
    }
}
//---Гномья сортировка---

//---Обработка выбора сортировка---
void saf::on_sort_b_clicked()
{
    if(!ui->table->rowCount())
    {
        ui->sort_error->setText("Пустой массив");
        return;
    }
    if(ui->sort_status->text()=="Не сорт")
    {
        int a[200];

        int r = ui->table->rowCount();
        for(int i = 0;i<r;i++)
        {
            if(ui->table->item(i,0)!=nullptr)
            {
              a[i] = ui->table->item(i,0)->text().toInt();
            }
            else
            {
                ui->sort_error->setText("Заполни все ячейки");
                return;
            }
        }

        switch(ui->sort_s->currentIndex())
        {
            case 0:
                qs_partition(a,0,r-1);
            break;

            case 1:
                while(!is_sorted(a,r))
                    monkey_sort(a,r);
            break;

            case 2:
                comb_sort(a,r);
            break;

            case 3:
                bubble_sort(a,r);
            break;

            case 4:
                gnome_sort(a,r);
            break;
        }

        for(int i = 0;i<r;i++)
        {
            if(ui->table->item(i,0)!=nullptr)
            {
                ui->table->item(i,0)->setText(QString::number(a[i]));
            }
        }
        ui->sort_status->setText("сорт");
    }
    else ui->sort_error->setText("Уже.");
}
//---Обработка выбора сортировка---

//---Действия при изменении ячейки---
void saf::on_table_cellChanged(int row, int column)
{
    QString tmp;

    bool okay = true, flag;
    for(int i = 0; i < (ui->table->rowCount()); i++)
    {
        if(ui->table->item(i,0)!=nullptr)
        {
            tmp = ui->table->item(i,0)->text();
            tmp.toInt(&okay);
            if(!okay) break;
        }
    }

    if(okay)
        ui->value_status->setText("Норм");
    else
        ui->value_status->setText("Не норм");

    if(ui->kostil->text()!="+") ui->sort_status->setText("Не сорт");
    ui->sort_error->clear();
    ui->find_o->clear();

    ui->sort_b->setEnabled(okay);
    ui->sort_s->setEnabled(okay);

    ui->size_b->setEnabled(okay);
    ui->size_n->setEnabled(okay);
    ui->size_add->setEnabled(okay);
    ui->size_del->setEnabled(okay);

    ui->del_dub->setEnabled(okay);

    ui->find_b->setEnabled(okay);
    ui->find_n->setEnabled(okay);
    ui->find_s->setEnabled(okay);

    tmp = ui->table->item(row,column)->text();
    tmp.toInt(&flag);
    if(flag)
        ui->table->item(row,column)->setBackground(QBrush(QColor(Qt::white)));
    else
        ui->table->item(row,column)->setBackground(QBrush(QColor(Qt::red)));
   }
//---Действия при изменении ячейки---

//---Удаление дубликатов---
void saf::on_del_dub_clicked()
{
    if(!ui->table->rowCount())
    {
        ui->db_error->setText("Пустой массив");
        return;
    }
    if(ui->sort_status->text()=="сорт")
    {
        ui->kostil->setText("+");
        ui->db_error->clear();

        int r = ui->table->rowCount();
        int a[200];

        int j = 0;
        for(int i = 0;i<r-1;i++)
        {
            if(ui->table->item(i,0)!=nullptr)
            {
              if(ui->table->item(i,0)->text().toInt()!=ui->table->item(i+1,0)->text().toInt())
              {
                  a[j++] = ui->table->item(i,0)->text().toInt();
              }

            }
            else
            {
                ui->sort_error->setText("Заполни все ячейки");
                return;
            }
        }
        a[j++]=ui->table->item(r-1,0)->text().toInt();
        ui->table->setRowCount(0);
        ui->table->setRowCount(j);
        ui->size_n->setValue(j);
        for(int i = 0;i<j;i++)
        {
            if(ui->table->item(i,0)==nullptr)
            {
                QTableWidgetItem *pitem;
                pitem = new QTableWidgetItem;
                ui->table->setItem(i,0,pitem);
            }
            ui->table->item(i,0)->setText(QString::number(a[i]));
        }

        ui->kostil->clear();

    }
    else ui->db_error->setText("Нужен отсорт.массив");
}
//---Удаление дубликатов---

//---Бинарный поиск---
int saf::binary_search(int l, int r)
{
   if(r >= l)
   {
       int middle = l+(r-l)/2;
       if((ui->table->item(middle,0)->text().toInt()) == ui->find_n->value()) return middle;
       if((ui->table->item(middle,0)->text().toInt()) > ui->find_n->value()) return binary_search(l,middle-1);
       return binary_search(middle+1,r);
   }
   return -1;
}
//---Бинарный поиск---

//---Обработка выбора поиска---
void saf::on_find_b_clicked()
{
    int r = ui->table->rowCount();
    int counter = 0;

    ui->find_o->clear();

    if(!ui->table->rowCount())
    {
        ui->find_o->insertPlainText("Пустой массив\n");
        return;
    }
    for(int i = 0;i<r;i++)
        if(ui->table->item(i,0)==nullptr)
        {
            ui->find_o->insertPlainText("Для бин.поиска нужен отсорт.мас.\n");
            return;
        }

    switch(ui->find_s->currentIndex())
    {
        case 0:
        {
            for(int i = 0;i<r;i++)
            {
                if(ui->table->item(i,0)->text().toInt() == ui->find_n->value())
                {
                    counter++;
                    ui->find_o->insertPlainText("(" + QString::number(i+1) + ";" + QString::number(1) + ")\n");
                }
                else if( (ui->sort_status->text()=="сорт") && (ui->find_n->value() < ui->table->item(i,0)->text().toInt())) break;
            }
        }
        break;

        case 1:
        {
            if(ui->sort_status->text()=="сорт")
            {
                int found = binary_search(0,r-1);
                if(found != -1)
                {
                    counter++;
                    ui->find_o->insertPlainText("(" + QString::number(found+1) + ";" + QString::number(1) + ")\n");
                    if(found+1 < r)
                        for(int j = found+1;j<r;j++)
                        {
                            if((ui->table->item(j,0)->text().toInt()) == ui->find_n->value())
                            {
                                counter++;
                                ui->find_o->insertPlainText("(" + QString::number(j+1) + ";" + QString::number(1) + ")\n");
                            }
                            else break;
                        }

                    if((found-1) >= 0)
                        for(int j = found-1; j>-1; j--)
                        {
                            if((ui->table->item(j,0)->text().toInt()) == ui->find_n->value())
                            {
                                counter++;
                                ui->find_o->insertPlainText("(" + QString::number(j+1) + ";" + QString::number(1) + ")\n");
                            }
                            else break;
                        }
                }

            }
            else
            {
                ui->find_o->insertPlainText("Для бин.поиска нужен отсорт.мас.\n");
                return;
            }
        }
        break;

    }
    if(counter) ui->find_o->insertPlainText("Найдено соотвествий: " + QString::number(counter) + "\n");
    else ui->find_o->insertPlainText("Не найдено\n");

}
//---Обработка выбора поиска---
