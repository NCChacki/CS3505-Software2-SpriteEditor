#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "json.h"


MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);


    connect(ui->canvasWidget,
            &CanvasWidget::canvasClicked,
            this,
            &MainWindow::pixelChanged);


    //connections for Save/create/load
    connect(ui->saveProjectButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onSaveClicked);

    connect(&model,
            &Model::imageUpdated,
            this,
            &MainWindow::updateLabelImage);

    // connect(ui->loadProjectButton,
    //         &QPushButton::clicked,
    //         this,
    //         &MainWindow::onLoadClicked);

    // connect(ui->createProjectButton,
    //         &QPushButton::clicked,
    //         this,
    //         &MainWindow::onCreateClicked);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pixelChanged(QPointF point)
{
    std::cout<< point.rx() << " , " << point.ry() << std::endl;
    std::cout << "receiving coords in mainwindow ^" << std::endl;
    // How will we alert the model of this change?
    return; // stub


}

void MainWindow::onSaveClicked()
{
    //we can get rid of the hard coded path...i was just using it to test for now hehe
    //JSON::save(model, "/Users/victoriayong/Projects/Examples/cs3505Assignment8/Foorge/blah");
}

void MainWindow::updateLabelImage(QImage image)
{
    ui->canvasLabel->setPixmap(QPixmap::fromImage(image));
}
// MainWindow::onLoadClicked()
// {

// }

// MainWindow::onCreateClicked()
// {

// }
