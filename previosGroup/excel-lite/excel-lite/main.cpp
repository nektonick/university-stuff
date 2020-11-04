#include "excel_lite.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    excel_lite w;
    w.show();
    return a.exec();
}
