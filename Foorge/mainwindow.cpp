#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) //Model& model,  // first parameter for when model is unbroken
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // connect(ui->canvasWidget,
    //         &CanvasWidget::canvasClicked,
    //         this,
    //         &MainWindow::pixelChanged);

}


MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::pixelChanged(int canvasX, int canvasY)
// {
//     std::cout<< canvasX << " , " << canvasY << std::endl;
//     // How will we alert the model of this change?
//     return; // stub


// }
