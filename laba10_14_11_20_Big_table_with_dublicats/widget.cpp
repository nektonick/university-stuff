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
        for (int i=0; i<arg1.toInt(); ++i){
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
        for (int i=0; i<arg1.toInt(); ++i){
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
        Dialog d;
        if (ui->mainTable->rowCount() * ui->mainTable->columnCount() > 40000){ // > 200*200
            if (d.exec() != 1){
                return;
            }
        }
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

    fromTableToArrey();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }

    fromArreyToTable();
}

void Widget::quickSort(int low, int high)
{
    int i = low;
    int j = high;
    float pivot = arr[(i + j) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(low, j);
    if (i < high)
        quickSort(i, high);
}

void Widget::fastSort()
{
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();

    fromTableToArrey();

    quickSort(0, size-1);

    fromArreyToTable();
}

void Widget::comb(){
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
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();


    fromTableToArrey();

    comb();

    fromArreyToTable();
}

void Widget::gnome(){
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
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();

    fromTableToArrey();

    gnome();

    fromArreyToTable();
}

bool Widget::isSortCorrect() {

    for (size_t i=1; i< arr.size(); ++i){
        if (arr[i]<arr[i-1])
            return false;
    }
    return true;

}

void Widget::shuffle() {
    for (int i = 0; i < size; ++i){
        srand((unsigned int)clock());
        std::swap(arr[i], arr[(rand() % size)]);
    }
}

void Widget::bogoSort() {
    while (!isSortCorrect())
        shuffle();
}

void Widget::monkeySort()
{
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();

    fromTableToArrey();

    bogoSort();

    fromArreyToTable();
}

void Widget::fromTableToArrey()
{
    if (initializeArrey()){

        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }
        ui->mainTable->setDisabled(true);
    }
    else{
        ui->textOut->setText("Ошибка при создании массива для сортировки");
    }

}

void Widget::fromArreyToTable()
{
    for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
        for(int j = 0; j < ui->mainTable->columnCount(); ++j)
            ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));

    ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
    ui->mainTable->setDisabled(false);

}

void Widget::search()
{
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();

    if(initializeArrey()){
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        if (isSortCorrect()){
            binarySearch();
        }
        else{
            linearSearch();
        }
    }
    else{
        ui->textOut->setText("Ошибка при создании массива для сортировки");
    }


}


void Widget::binarySearch()
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
                try {
                    indexes.push_back(m);
                    ++m;
                } catch (...) {
                    ui->textOut->setText("операция произошла с ошибкой из-за нехватка помяти");
                    return;
                }

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

void Widget::linearSearch()
{
    ui->textOut->setText("Выполняется линейный поиск числа "+ QString::number(searchValue) + "\n");

    std::vector<int> indexes;

    for(int i=0; i<size; ++i){
        if (arr[i] == searchValue){
            try {
                indexes.push_back(i);
            } catch (...) {
                ui->textOut->setText("операция произошла с ошибкой из-за нехватка помяти");
                return;
            }

        }
    }

    ui->textOut->setText(ui->textOut->toPlainText() + "Найдено элементов: " +QString::number(indexes.size()) +"\n");
    for (size_t i=0; i< indexes.size(); ++i) {
        ui->textOut->setText(ui->textOut->toPlainText() +
                             QString::number(i+1) + " вхождение: строка "
                             +QString::number( (indexes[i])/ui->mainTable->columnCount() +1) + ", столбец " + QString::number( (indexes[i])%ui->mainTable->columnCount() +1) + "\n");
    }
}

bool Widget::initializeArrey()
{
    size = ui->mainTable->rowCount() * ui->mainTable->columnCount();

    try {
        arr.resize(size);

    } catch (...) {

        return false;
    }
    return true;
}

void Widget::on_searchButton_clicked()
{

    bool ok;
    searchValue = ui->searchValue->text().toFloat(&ok);
    if(ok){
        if (isTableOK()){
            Dialog d;
            if (ui->mainTable->rowCount() * ui->mainTable->columnCount() > 40000){ // > 200*200
                if (d.exec() != 1){
                    return;
                }
            }
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

void Widget::on_deleteDublicatesButton_clicked()
{
    initializeArrey();

    if (isSortCorrect() && isTableOK()){

        ui->textOut->setText("Начато удаление дубликатов");
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        arr.resize(unique(arr.begin(),arr.end())-arr.begin());

        for(size_t i =0; i<arr.size(); ++i){
            ui->mainTable->item(i/ui->mainTable->columnCount(), i%ui->mainTable->columnCount())->setText(QString::number(arr[i]));
        }
        for (int i =arr.size(); i< ui->mainTable->columnCount() * ui->mainTable->rowCount(); ++i){
            delete ui->mainTable->item(i/ui->mainTable->columnCount(), i%ui->mainTable->columnCount());
        }
        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Дубликаты удалены");

    }
    else{
        ui->textOut->setText("Сначала отсортируйте таблицу");
    }
    tableIsOk = isTableOK();
}
