#include "boolcalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    boolcalc w;
    w.show();

    return a.exec();
}
