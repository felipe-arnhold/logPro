#include "gscreen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gScreen w;
    w.show();
    return a.exec();
}
