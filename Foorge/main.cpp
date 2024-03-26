#include "mainwindow.h"
//#include "model.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ///TODO: Take a look at default frame size!!
    //Model model;
    MainWindow w;
    w.show();
    return a.exec();
}
