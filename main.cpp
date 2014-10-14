#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(0, Qt::WindowStaysOnTopHint);
    w.show();

    return a.exec();
}
