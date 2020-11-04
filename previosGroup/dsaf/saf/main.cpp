#include "saf.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    saf w;
    w.show();
    return a.exec();
}
