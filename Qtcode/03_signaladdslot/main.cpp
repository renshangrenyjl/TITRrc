#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;//执行mainWidget的构造函数
    w.show();
    return a.exec();
}
