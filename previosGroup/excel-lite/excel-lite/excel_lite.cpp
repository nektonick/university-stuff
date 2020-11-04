 #include "excel_lite.h"
#include "ui_excel_lite.h"

excel_lite::excel_lite(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::excel_lite)
{
    ui->setupUi(this);

    ui->size_r->setMinimum(1);
    ui->size_r->setMaximum(200);
    ui->size_c->setMinimum(1);
    ui->size_c->setMaximum(200);

    ui->search->setMinimum(-999);
    ui->search_output->setReadOnly(true);
}

excel_lite::~excel_lite()
{
    delete ui;
}

void excel_lite::on_size_b_clicked()
{
    ui->table->setRowCount(ui->size_r->value());
    ui->table->setColumnCount(ui->size_c->value());
    ui->find_output->clear();
}

void excel_lite::on_size_r_add_clicked()
{
    ui->table->setRowCount(ui->table->rowCount()+1);
    ui->find_output->clear();
}

void excel_lite::on_size_r_del_clicked()
{
    if(ui->table->rowCount()) ui->table->setRowCount(ui->table->rowCount()-1);
    ui->find_output->clear();
}

void excel_lite::on_size_c_add_clicked()
{
    ui->table->setColumnCount(ui->table->columnCount()+1);
    ui->find_output->clear();
}

void excel_lite::on_size_c_del_clicked()
{
    if(ui->table->columnCount()) ui->table->setColumnCount(ui->table->columnCount()-1);
    ui->find_output->clear();
}

void excel_lite::on_find_b_clicked()
{
    int r = ui->table->rowCount();
    int c = ui->table->columnCount();
    int m = ui->find->currentIndex()? INT_MIN: INT_MAX;
    int sum = 0, counter = 0;

    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
           if(ui->table->item(i,j)!=nullptr)
           {
               QString tmp;
               tmp = ui->table->item(i,j)->text();
               bool flag;
               int number = tmp.toInt(&flag);
               if(flag)
               {
                   switch(ui->find->currentIndex())
                   {
                        case 0:
                            if(m>number) m = number;
                            break;
                        case 1:
                            if(m<number) m = number;
                            break;
                        case 3:
                        case 2:
                            counter++;
                            sum+=number;
                            break;
                   }
               }
               else
               {
                   ui->find_output->setText("NON NUM");
                   return;
               }
           }
           else
           {
               ui->find_output->setText("EMPTY CELL");
               return;
           }
        }
    }

    switch(ui->find->currentIndex())
    {
        case 0:
        case 1:
            if(m!=INT_MAX && m!=INT_MIN) ui->find_output->setText(QString::number(m));
            break;
        case 3:
            if(counter) ui->find_output->setText(QString::number(sum));
            break;
        case 2:
             if(counter) ui->find_output->setText(QString::number((double)sum/counter));
            break;

    }
}

void excel_lite::on_fill_b_clicked()
{
    ui->find_output->clear();

    int r = ui->table->rowCount();
    int c = ui->table->columnCount();

    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            if(ui->table->item(i,j)==nullptr)
            {
                QTableWidgetItem *pitem;
                pitem = new QTableWidgetItem;
                ui->table->setItem(i,j,pitem);
            }
            srand((unsigned int)clock());
            int value = ui->fill->currentIndex()?((rand()%201-100)):0;
            ui->table->item(i,j)->setText(QString::number(value));
        }
    }
}

void excel_lite::on_table_cellChanged(int row, int column)
{
    QString tmp = ui->table->item(row,column)->text();
    bool flag;
    tmp.toInt(&flag);
    if(flag)
    {
        ui->table->item(row,column)->setBackground(QBrush(QColor(Qt::white)));
        ui->error->clear();

        ui->size_c_add->setEnabled(true);
        ui->size_c_del->setEnabled(true);

        ui->size_r_add->setEnabled(true);
        ui->size_r_del->setEnabled(true);

        ui->size_r->setEnabled(true);
        ui->size_c->setEnabled(true);
        ui->size_b->setEnabled(true);

        ui->sort->setEnabled(true);
        ui->sort_b->setEnabled(true);

        ui->find->setEnabled(true);
        ui->find_b->setEnabled(true);

        ui->remove_duplicates->setEnabled(true);
        ui->search->setEnabled(true);
        ui->search_b->setEnabled(true);

    }
    else
    {
        ui->table->item(row,column)->setBackground(QBrush(QColor(Qt::red)));

        ui->size_c_add->setEnabled(false);
        ui->size_c_del->setEnabled(false);

        ui->size_r_add->setEnabled(false);
        ui->size_r_del->setEnabled(false);

        ui->size_r->setEnabled(false);
        ui->size_c->setEnabled(false);
        ui->size_b->setEnabled(false);

        ui->sort->setEnabled(false);
        ui->sort_b->setEnabled(false);

        ui->find->setEnabled(false);
        ui->find_b->setEnabled(false);

        ui->remove_duplicates->setEnabled(false);
        ui->search->setEnabled(false);
        ui->search_b->setEnabled(false);

        ui->error->setText("FIX NON NUM");
        ui->table->item(row,column)->setSelected(true);
    }
    ui->sort_status->setText("unsorted");
}

void excel_lite::bubble_sort()
{
    for(int r = 0; r < ui->table->rowCount(); r++)
        for(int i = ui->table->columnCount() - 1;i>0;i--)
          for(int j = 0; j < i; j++)
          {
              int a = ui->table->item(r,j)->text().toInt();
              int b = ui->table->item(r,j+1)->text().toInt();
              if (a > b)
              {
                  ui->table->item(r,j)->setText(QString::number(b));
                  ui->table->item(r,j+1)->setText(QString::number(a));
              }

          }
}

void excel_lite::comb_sort()
{
    double fakt = 1.2473309; // фактор уменьшения
    double step = ui->table->columnCount() - 1;

    while (step >= 1)
    {
        for(int r = 0; r < ui->table->rowCount(); r++)
            for (int i = 0; i + step < ui->table->columnCount(); i++)
            {
                int a = ui->table->item(r,i)->text().toInt();
                int b = ui->table->item(r,i+step)->text().toInt();

                if (a > b)
                {
                    ui->table->item(r,i)->setText(QString::number(b));
                    ui->table->item(r,i+step)->setText(QString::number(a));
                }
            }
            step /= fakt;
    }
}

bool excel_lite::is_sorted()
{
    int r = ui->table->rowCount();
    int c = ui->table->columnCount();

    for(int i = 0;i<r;i++)
        for(int j = 0;j<c-1;j++)
        {
            int a = ui->table->item(i,j)->text().toInt();
            int b = ui->table->item(i,j+1)->text().toInt();
            if(a>b) return false;

        }
    return true;
}

void excel_lite::monkey_sort()
{
    int r = ui->table->rowCount();
    int c = ui->table->columnCount();

    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
        {
            srand((unsigned int)clock());
            int random = abs(rand()%c);

            int a = ui->table->item(i,j)->text().toInt();
            int b = ui->table->item(i,random)->text().toInt();

            ui->table->item(i,j)->setText(QString::number(b));
            ui->table->item(i,random)->setText(QString::number(a));

        }
}

int excel_lite::qs_partition(int row, int low, int high)
{
    int pivot = ui->table->item(row, high)->text().toInt();
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (ui->table->item(row, j)->text().toInt() < pivot)
        {
            i++;
            int tmp = ui->table->item(row, i)->text().toInt();
            ui->table->item(row, i)->setText(ui->table->item(row, j)->text());
            ui->table->item(row, j)->setText(QString::number(tmp));
        }
    }

    int tmp = ui->table->item(row, i+1)->text().toInt();
    ui->table->item(row, i+1)->setText(ui->table->item(row, high)->text());
    ui->table->item(row, high)->setText(QString::number(tmp));

    return (i + 1);
}

void excel_lite::qs(int row, int low, int high)
{

    if (low < high)
    {
        int pi = qs_partition(row, low, high);
        qs(row, low, pi - 1);
        qs(row, pi + 1, high);
    }

}

void excel_lite::on_sort_b_clicked()
{
    int r = ui->table->rowCount();
    int c = ui->table->columnCount();

    if(ui->sort_status->text()=="unsorted")
    {
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                if(ui->table->item(i,j)==nullptr)
                {
                    ui->error->setText("FILL CELLS");
                    return;
                }

        switch (ui->sort->currentIndex())
        {
        case 0:
            for(int i = 0; i < (ui->table->rowCount());i++)
                qs(i,0,ui->table->columnCount()-1);
            break;
        case 1:
            while(!is_sorted())
                monkey_sort();
            break;

        case 2:
            comb_sort();
        case 3:
            bubble_sort();
            break;

        case 4:
            for(int r = 0; r < (ui->table->rowCount()); r++)
                for(int i = 1; i < (ui->table->columnCount());)
                {
                    if(!i) i++;
                    int a = ui->table->item(r,i)->text().toInt();
                    int j = i-1;
                    int b = ui->table->item(r,j)->text().toInt();

                    if (b<=a) i++;
                    else
                    {
                        ui->table->item(r,i)->setText(QString::number(b));
                        ui->table->item(r,j)->setText(QString::number(a));
                        i--;
                    }
                }
            break;
        }
        ui->sort_status->setText("sorted");
    }
}

void excel_lite::on_remove_duplicates_clicked()
{
    if(ui->sort_status->text()=="sorted" && (ui->table->rowCount() == 1) )
    {
        ui->remove_duplicates_error->clear();

        //int r = ui->table->rowCount();
        int i = 0;
        int c = ui->table->columnCount();
        //for(int i = 0;i<r;i++)
        {
            int a[200];
            int counter = 0;
            for(int j = 0;j<c-1;j++)
            {
                while((j<c-1) && (ui->table->item(i,j)->text().toInt() == ui->table->item(i,j+1)->text().toInt()))
                {
                    counter++;
                    j++;
                }
                if(counter)
                {
                    for(int x = j-counter+1; x<((c-counter)); x++)
                    {

                        QString tmp = ui->table->item(i,x+counter)->text();
                        ui->table->item(i,x+counter)->setText(ui->table->item(i,x)->text());
                        ui->table->item(i,x)->setText(tmp);

                    }

                    for(int z = 0; z < c-counter; z++)
                       a[z] = ui->table->item(i,z)->text().toInt();

                    ui->table->clear();
                    //ui->table->setRowCount(c-counter);
                    //ui->table->setColumnCount(1);

                    for(int z = 0; z < c-counter; z++)
                    {
                        if(ui->table->item(i,z)==nullptr)
                        {
                            QTableWidgetItem *pitem;
                            pitem = new QTableWidgetItem;
                            ui->table->setItem(i,j,pitem);
                        }
                        ui->table->item(i,z)->setText(QString::number(a[z]));
                    }
                    counter = 0;

                }

            }

        }
    }
    else ui->remove_duplicates_error->setText("ERROR");
}

int excel_lite::binary_search(int row, int l, int r)
{ 
   if(r >= l)
   {
       int middle = l+(r-l)/2;
       if((ui->table->item(row,middle)->text().toInt()) == ui->search->value()) return middle;
       if((ui->table->item(row,middle)->text().toInt()) > ui->search->value()) return binary_search(row,l,middle-1);
       return binary_search(row,middle+1,r);
   }
   return -1;
}

void excel_lite::on_search_b_clicked()
{
    int r = ui->table->rowCount();
    int c = ui->table->columnCount();
    int counter = 0;

    ui->search_output->clear();

    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
            if(ui->table->item(i,j)==nullptr)
            {
                ui->search_output->insertPlainText("Need fill all cells for binary search\n");
                return;
            }

    switch(ui->search_set->currentIndex())
    {
        case 0:
        {
            for(int i = 0;i<r;i++)
                for(int j = 0;j<c;j++)
                {
                    if(ui->table->item(i,j)->text().toInt() == ui->search->value())
                    {
                        counter++;
                        ui->search_output->insertPlainText("(" + QString::number(i+1) + ";" + QString::number(j+1) + ")\n");
                    }
                    else if( (ui->sort_status->text()=="sorted") && (ui->search->value() < ui->table->item(i,j)->text().toInt())) break;

                }
        }
        break;

        case 1:
        {
            if( (ui->sort_status->text()=="sorted"))
            {

                for(int i = 0;i<r;i++)
                {
                    int found = binary_search(i,0,c-1);
                    if(found != -1)
                    {
                        counter++;
                        ui->search_output->insertPlainText("(" + QString::number(i+1) + ";" + QString::number(found+1) + ")\n");
                        if(found+1 < c)
                            for(int j = found+1;j<c;j++)
                            {
                                if((ui->table->item(i,j)->text().toInt()) == ui->search->value())
                                {
                                    counter++;
                                    ui->search_output->insertPlainText("(" + QString::number(i+1) + ";" + QString::number(j+1) + ")\n");
                                }
                                else break;
                            }

                        if((found-1) >= 0)
                            for(int j = found-1; j>-1; j--)
                            {
                                if((ui->table->item(i,j)->text().toInt()) == ui->search->value())
                                {
                                    counter++;
                                    ui->search_output->insertPlainText("(" + QString::number(i+1) + ";" + QString::number(j+1) + ")\n");
                                }
                                else break;
                            }
                    }

                }

            }
            else
            {
                ui->search_output->insertPlainText("Need sorted array for binary search\n");
                return;
            }
        }
        break;
    }

    if(counter) ui->search_output->insertPlainText("Найдено соотвествий: " + QString::number(counter) + "\n");
    else ui->search_output->insertPlainText("Не найдено\n");

}

/*
 * ДЗ 9
 * Сохранить работу 8 и сделать ее копию, увеличить до 100к, переведя все массивы в динам.
 * После удаления дубликатов, массив надо уменьшать, если что-то удалилось
 * Особое внимание на утечку памяти.
 * Ограничение на выбор сортировок для больших массивов, предупреждение
 */
