#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    srand(time(0));
    ui->setupUi(this);
    redPal.setColor(QPalette::Base, Qt::red);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_numOfColumns_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toInt(&ok);
    if (ok){
        ui->numOfColumns->setPalette(defPal);
        ui->mainTable->clear();
        while(ui->mainTable->columnCount()){
            ui->mainTable->removeColumn(0);
        }
        for (int i=0; i<arg1.toInt()%201; ++i){
            ui->mainTable->insertColumn(0);
        }
    }
    else{
        ui->numOfColumns->setPalette(redPal);
    }
    ui->textOut->clear();
}

void Widget::on_numOfRows_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toInt(&ok);
    if (ok){
        ui->numOfRows->setPalette(defPal);
        ui->mainTable->clear();
        while(ui->mainTable->rowCount()){
            ui->mainTable->removeRow(0);
        }
        for (int i=0; i<arg1.toInt()%201; ++i){
            ui->mainTable->insertRow(0);
        }
    }
    else{
        ui->numOfRows->setPalette(redPal);
    }
    ui->textOut->clear();
}

void Widget::on_randomFill_clicked()
{
    bool ok3,ok4;
    int x = ui->numOfColumns->text().toInt(&ok3);
    int y = ui->numOfRows->text().toInt(&ok4);
    bool ok1,ok2;
    ui->minInt->text().toInt(&ok1);
    ui->maxInt->text().toInt(&ok2);

    if (ok1){
        minRand = ui->minInt->text().toInt();
        ui->minInt->setPalette(defPal);
    }
    else{
        //используем значение по умолчанию
        minRand = 0;

        ui->minInt->setPalette(redPal);
    }

    if (ok2){
        maxRand = ui->maxInt->text().toInt();
        ui->maxInt->setPalette(defPal);
    }
    else{
        //используем значение по умолчанию
        maxRand = 200;

        ui->maxInt->setPalette(redPal);
    }
    if (ok3 && ok4 && x >0 && y>0){
        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                ui->mainTable->setItem(i,j, new QTableWidgetItem(QString::number(rand()%(maxRand - minRand + 1) + minRand)));
            }
        }
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }

}

void Widget::on_getMinButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        float min = ui->mainTable->item(0,0)->text().toFloat();

        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                if (ui->mainTable->item(i,j)->text().toFloat() < min){
                    min = ui->mainTable->item(i,j)->text().toFloat();
                }
            }
        }
        ui->textOut->setText("Минимум = " + QString::number(min));
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }

}

void Widget::on_getMaxButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        float max = ui->mainTable->item(0,0)->text().toFloat();

        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                if (ui->mainTable->item(i,j)->text().toFloat() > max){
                    max = ui->mainTable->item(i,j)->text().toFloat();
                }
            }
        }
        ui->textOut->setText("Максимум = " + QString::number(max));
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

void Widget::on_meanInt_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        sum = 0;
        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                sum+=ui->mainTable->item(i,j)->text().toFloat();
            }
        }
        ui->textOut->setText("Среднее значение = " + QString::number(sum /
                                                                     (ui->mainTable->rowCount() * ui->mainTable->columnCount()) ) );
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

void Widget::on_sortButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        isSortingNow = true;
        int type = ui->typeOfSorting->currentIndex();

        ui->textOut->clear();
        ui->textOut->setText("Начата сортировка " + ui->typeOfSorting->currentText());

        switch (type) {
        case 0:
            bubbleSort();
            break;
        case 1:
            fastSort();
            break;
        case 2:
            combSort();
            break;
        case 3:
            gnomeSort();
            break;
        case 4:
            monkeySort();
            break;
        default:
            ui->textOut->setText("sort type error");
        }
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

bool Widget::isTableOK()
{
    bool ans=true;
    for (int i = 0; i< ui->mainTable->rowCount(); ++i){
        for (int j=0; j< ui->mainTable->columnCount(); ++j){
            bool castIsOk;
            if (ui->mainTable->item(i,j) != nullptr){
                ui->mainTable->item(i,j)->text().toFloat(&castIsOk);
                if (!castIsOk){
                    ans = false;
                    ui->mainTable->scrollToItem(ui->mainTable->item(i,j));
                    ui->mainTable->editItem(ui->mainTable->item(i,j));
                    break;
                }
            }
            else{
                ui->mainTable->scrollToItem(ui->mainTable->item(i,j));
                ui->mainTable->editItem(ui->mainTable->item(i,j));
                ans = false;
                break;
            }

        }
    }
    if (ui->mainTable->rowCount() <= 0 || ui->mainTable->columnCount() <= 0){
        ans = false;
    }
    return ans;
}


void Widget::on_mainTable_itemChanged(QTableWidgetItem *item)
{
    if (item != nullptr){
        bool ok;
        item->text().toFloat(&ok);
        if (!ok){
            item->setBackground(Qt::red);
        }
        else{
            if (!isSortingNow)
                item->setBackground(Qt::white);
        }
    }
}


void Widget::bubbleSort()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];
    fromTableToArrey(arr);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }

    fromArreyToTable(arr);
}

void qsortRecursive(float *arr, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    float mid = arr[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(arr[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(arr[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            std::swap(arr[i],arr[j]);

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(arr, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&arr[i], size - i);
    }
}

void Widget::fastSort()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];

    fromTableToArrey(arr);

    qsortRecursive(arr, size);

    fromArreyToTable(arr);
}

void comb(float *arr, int size){
    float factor = 1.2473309; // фактор уменьшения
    float step = size - 1; // шаг сортировки

    while (step >= 1)
    {
        for (int i = 0; i + step < size; i++)
        {
            if (arr[i] > arr[int(i + step)])
            {
                std::swap(arr[i], arr[int(i + step)]);
            }
        }
        step /= factor;
    }
}

void Widget::combSort()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];

    fromTableToArrey(arr);

    comb(arr, size);

    fromArreyToTable(arr);
}

void gnome(float *arr, int size){
    int index = 0;
    while (index < size) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

void Widget::gnomeSort()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];

    fromTableToArrey(arr);

    gnome(arr, size);

    fromArreyToTable(arr);
}

bool isSortCorrect(float *arr, int size) {
    while (size-- > 0)
        if (arr[size - 1] > arr[size])
            return false;
    return true;
}

void shuffle(float *arr, int size) {
    for (int i = 0; i < size; ++i){
        srand((unsigned int)clock());
        std::swap(arr[i], arr[(rand() % size)]);
    }
}

void bogoSort(float *arr, int size) {
    while (!isSortCorrect(arr, size))
        shuffle(arr, size);
}

void Widget::monkeySort()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];

    fromTableToArrey(arr);

    bogoSort(arr, size);

    fromArreyToTable(arr);
}

void Widget::fromTableToArrey(float arr[])
{
    for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
        for (int j=0; j < ui->mainTable->columnCount() ; ++j)
            arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
    }
    ui->mainTable->setDisabled(true);
}

void Widget::fromArreyToTable(float arr[])
{
    for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
        for(int j = 0; j < ui->mainTable->columnCount(); ++j)
            ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));

    ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
    ui->mainTable->setDisabled(false);
}

void Widget::search()
{
    int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
    float arr[size];

    for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
        for (int j=0; j < ui->mainTable->columnCount() ; ++j)
            arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
    }

    if (isSortCorrect(arr,size)){
        binarySearch(arr,size);
    }
    else{
        linearSearch(arr,size);
    }

}


void Widget::binarySearch(float *arr, int size)
{
    ui->textOut->setText("Выполняется бинарный поиск числа "+ QString::number(searchValue) + "\n");

    std::vector<int> indexes;
    int l=0, r = size;

    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == searchValue){
            //переходим к самому первому элементу с таким значением
            while (arr[m-1] == searchValue && (m-1) >=0){
                --m;
            }
            while ( m < r && arr[m] == searchValue){
                indexes.push_back(m);
                ++m;
            }
            break;
        }

        if (arr[m] < searchValue)
            l = m + 1;

        else
            r = m - 1;
    }

    ui->textOut->setText(ui->textOut->toPlainText() + "Найдено элементов: " +QString::number(indexes.size()) +"\n");
    for (size_t i=0; i< indexes.size(); ++i) {
        ui->textOut->setText(ui->textOut->toPlainText() +
                             QString::number(i+1) + " вхождение: строка "
                             +QString::number( (indexes[i])/ui->mainTable->columnCount() +1) + ", столбец " + QString::number( (indexes[i])%ui->mainTable->columnCount() +1) + "\n");
    }
}

void Widget::linearSearch(float *arr, int size)
{
    ui->textOut->setText("Выполняется линейный поиск числа "+ QString::number(searchValue) + "\n");

    std::vector<int> indexes;

    for(int i=0; i<size; ++i){
        if (arr[i]==searchValue){
            indexes.push_back(i);
        }
    }

    ui->textOut->setText(ui->textOut->toPlainText() + "Найдено элементов: " +QString::number(indexes.size()) +"\n");
    for (size_t i=0; i< indexes.size(); ++i) {
        ui->textOut->setText(ui->textOut->toPlainText() +
                             QString::number(i+1) + " вхождение: строка "
                             +QString::number( (indexes[i])/ui->mainTable->columnCount() +1) + ", столбец " + QString::number( (indexes[i])%ui->mainTable->columnCount() +1) + "\n");
    }
}

void Widget::on_searchButton_clicked()
{
    bool ok;
    searchValue = ui->searchValue->text().toFloat(&ok);
    if(ok){
        if (isTableOK()){
            search();
        }
        else{
            ui->textOut->setText("Сначала корректно заполните таблицу");
        }

    }
    else{
        ui->textOut->setText("Сначала корректно введите значение для поиска");
    }
}
