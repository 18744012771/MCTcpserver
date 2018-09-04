#include "mainwindow.h"
#include <QApplication>
#include <QNetworkInterface>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto addlist=QNetworkInterface::allAddresses();
    qDebug()<<addlist;
    w.show();

    return a.exec();
}
