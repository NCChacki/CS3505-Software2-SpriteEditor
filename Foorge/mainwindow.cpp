#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->canvasWidget,
            &CanvasWidget::canvasClicked,
            this,
            &MainWindow::pixelChanged);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pixelChanged(int canvasX, int canvasY)
{
    std::cout<< canvasX << " , " << canvasY << std::endl;
    std::cout << "receiving coords in mainwindow ^" << std::endl;
    // How will we alert the model of this change?
    return; // stub


}
