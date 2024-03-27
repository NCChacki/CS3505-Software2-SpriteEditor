#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "json.h"
#include <QDebug>


MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);

    // this one is a waste
    connect(ui->canvasWidget,
            &CanvasWidget::canvasClicked,
            this,
            &MainWindow::pixelChanged);

    connect(ui->newFrameButton,
            &QPushButton::clicked,
            &model,
            &Model::addNewFrame);

    // this is the one that actually does stuff
    connect(ui->canvasWidget,
            &CanvasWidget::canvasClicked,
            &model,
            &Model::imageChanged);

    connect(&model,
            &Model::imageUpdated,
            this,
            &MainWindow::updateLabelImage);

    connect(&model,
            &Model::previewUpdated,
            this,
            &MainWindow::updatePreviewImage);

    //connections for Save/create/load
    connect(ui->saveProjectButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onSaveClicked);

    connect(ui->loadProjectButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onLoadClicked);

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
    JSON::save(model, "/Users/victoriayong/Projects/Examples/cs3505Assignment8/Foorge/blah");
}

void MainWindow::updateLabelImage(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->canvasLabel->setPixmap(pixmap.scaledToHeight(500,Qt::FastTransformation));
}

void MainWindow::updatePreviewImage(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->previewLabel->setPixmap(pixmap.scaledToHeight(100,Qt::FastTransformation));
}
void MainWindow::onLoadClicked()
{
    //will have to change to have a pop up window
    model.resetModel();
    JSON::load(model, "/Users/victoriayong/Projects/Examples/cs3505Assignment8/Foorge/blah");
}

// MainWindow::onCreateClicked()
// {

// }
