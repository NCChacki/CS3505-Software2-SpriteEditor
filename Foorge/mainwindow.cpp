#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "json.h"
#include <QDebug>
#include <QCloseEvent>
#include <QFileDialog>




MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);

    //set up warning msg box
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    // this one is a waste
    connect(ui->canvasWidget,
            &CanvasWidget::canvasClicked,
            this,
            &MainWindow::pixelChanged);


    connect(ui->newFrameButton,
            &QPushButton::clicked,
            &model,
            &Model::addNewFrame);

    connect(ui->nextFrameButton,
            &QPushButton::clicked,
            &model,
            &Model::nextFrame);

    connect(ui->previousFrameButton,
            &QPushButton::clicked,
            &model,
            &Model::previousFrame);

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

    connect(this,
            &MainWindow::fileLoadedSignal,
            this,
            &MainWindow::updateLabelImage);

    connect(&model,
            &Model::sendPreviewFrames,
            this,
            &MainWindow::updateFramePreview);

    connect(ui->frameRateSlider,
            &QAbstractSlider::sliderMoved,
            &model,
            &Model::frameRateChanged);

    connect(ui->deleteFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::deleteFrame);

    // connect(&model,
    //         &Model::addFrameToPreview,
    //         this,
    //         &MainWindow::frameSelectorUpdated);

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
   // std::cout<< point.rx() << " , " << point.ry() << std::endl;
   // std::cout << "receiving coords in mainwindow ^" << std::endl;
    // How will we alert the model of this change?
    canvasChanged = true;
    return; // stub
}

void MainWindow::onSaveClicked()
{
    QString saveAsFileName = QFileDialog::getSaveFileName(this, tr("Save File"), "./",  "Any files (*)");

    if (saveAsFileName == "")
    {
        QMessageBox::warning(this, tr("Warning"), tr("File name not given, please provide a file name to save as"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }

    JSON::save(model, saveAsFileName);
    canvasChanged = false;
}

void MainWindow::updateLabelImage(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->canvasLabel->setPixmap(pixmap.scaledToHeight(500,Qt::FastTransformation));
    ui->frameLabel3->setPixmap(pixmap.scaledToHeight(100,Qt::FastTransformation));
}

void MainWindow::updatePreviewImage(QImage image)
{
    QPixmap pixmap = QPixmap::fromImage(image);


    ui->previewLabel->setPixmap(pixmap.scaledToHeight(100,Qt::FastTransformation));
}

void MainWindow::onLoadClicked()
{
    if (canvasChanged)
    {
        int ret = QMessageBox::warning(this, tr("Warning"), tr("Do you want to load a new file without saving?"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);

        switch (ret) {
        case QMessageBox::Ok:
            // Save was clicked
            break;
        default:
            return;
        }
    }
    QString selectedFileName = QFileDialog::getOpenFileName(this, tr("Select File"), "./", "Any files (*)");
    if (selectedFileName == "")
    {
        QMessageBox::warning(this, tr("Warning"), tr("File name not given, please provide a file name to open"), QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    model.resetModel();
    JSON::load(model, selectedFileName);
    emit fileLoadedSignal(model.animationFrames[0].imageData);


}


// void MainWindow::frameSelectorUpdated(QImage image)
// {
//     //Turn QImage to Qpixmap
//     QPixmap pixmap = QPixmap::fromImage(image);

//     std::cout << "calling frame selector update##########################" <<std::endl;
//     //create a framelabel with the desired pixmap


//     ui->frameLabel1->setPixmap(pixmap.scaledToHeight(80,Qt::FastTransformation));
//     // ui->frameLabel2->setPixmap(pixmap.scaledToHeight(80,Qt::FastTransformation));
//     // ui->frameLabel3->setPixmap(pixmap.scaledToHeight(80,Qt::FastTransformation));
//     // ui->frameLabel4->setPixmap(pixmap.scaledToHeight(80,Qt::FastTransformation));


//     //put the framelabel you created into the horizontal layout
//     //ui->previewScrollArea->setWidget(frameLabel);

//     //clean up the dynamically allocated QLabel
//     //delete frameLabel;
// }

// MainWindow::onCreateClicked()
// {

// }

void MainWindow::closeEvent(QCloseEvent* closeEvent)
{
    if(canvasChanged)
    {
        closeEvent -> ignore();
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            onSaveClicked();
            closeEvent -> accept();
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            closeEvent -> accept();
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
            // should never be reached
            break;
        }
    }
}

void MainWindow::updateFramePreview(std::vector<QImage> previewImages)
{
    //std::cout << "calling mainwindow update frame preview" << std::endl;
    ui->frameLabel1->setPixmap(QPixmap::fromImage(previewImages.at(0)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel2->setPixmap(QPixmap::fromImage(previewImages.at(1)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel3->setPixmap(QPixmap::fromImage(previewImages.at(2)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel4->setPixmap(QPixmap::fromImage(previewImages.at(3)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel5->setPixmap(QPixmap::fromImage(previewImages.at(4)).scaledToHeight(100,Qt::FastTransformation));
}


