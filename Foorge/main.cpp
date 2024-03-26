#include "mainwindow.h"
#include "model.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    ///TODO: Take a look at default frame size!!

    Model model;
    MainWindow w(model);
    w.show();
    return a.exec();
}
