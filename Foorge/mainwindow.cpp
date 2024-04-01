#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
#include "json.h"
#include <QDebug>
#include <QCloseEvent>
#include <QFileDialog>
#include <QInputDialog>


MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);

    this->setWindowTitle("Foorge");

    //set up the color dialog box, for chosing colors
    colorPicker= new QColorDialog(parent);



    //set up warning msg box
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    //set up brush size box
    QList<QString> brushSizes;
    brushSizes.append({"1", "2", "3","4","5"});
    ui->brushSizeBox->addItems(brushSizes);


    // connect(ui->brushSizeBox,
    //         &QComboBox,
    //         &model,
    //         &Model::)

    //connect the erase buttons
    connect(ui->eraseButton,
            &QPushButton::clicked,
            &model,
            &Model::eraseClicked);

    connect(ui->colorButton,
            &QPushButton::clicked,
            this,
            &MainWindow::colorButtonClicked);

    connect(colorPicker,
            &QDialog::finished,
            this,
            &MainWindow::colorButtonClosed);

    connect(ui->eraseScreen,
            &QPushButton::clicked,
            &model,
            &Model::eraseScreen);

    //conections for rcolor picker
    connect( colorPicker,
            &QColorDialog::currentColorChanged,
            &model,
            &Model::colorChanged
            );

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

    //save/load/create connections
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

    connect(ui->createProjectButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onCreateClicked);

    //undo/redo connections
    connect(ui->undoButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onUndoClicked);

    connect(ui->redoButton,
            &QPushButton::clicked,
            this,
            &MainWindow::onRedoClicked);

    connect(this,
            &MainWindow::undoClickedSignal,
            &model,
            &Model::undoFrame);

    connect(this,
            &MainWindow::redoClickedSignal,
            &model,
            &Model::redoFrame);

    connect(&model,
            &Model::imageUpdated,
            this,
            &MainWindow::enableUndoRedo);

    connect(&model,
            &Model::sendPreviewFrames,
            this,
            &MainWindow::updateFrameSelector);

    connect(ui->frameRateSlider,
            &QAbstractSlider::sliderMoved,
            &model,
            &Model::frameRateChanged);

    connect(ui->deleteFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::deleteFrame);

    connect(ui->brushSizeBox,
            &QComboBox::currentTextChanged,
            &model,
            &Model::brushSizeChanged);

    /// jai's onion skin business
    QImage transparent(500,500,QImage::Format_ARGB32);
    for(int x=0; x<500;x++)
    {
        for (int y=0; y<500;y++)
        {
            if (((x/10)+(y/10))%2 ==0)
                transparent.setPixelColor(x,y,QColorConstants::Gray);
            else transparent.setPixelColor(x,y,QColorConstants::White);
        }
    }

    QPixmap tPixmap = QPixmap::fromImage(transparent);
    ui->transparentLabel->setPixmap(tPixmap);
    ui->canvasLabel->raise();

    connect(&model,
            &Model::enableOnion,
            this,
            &MainWindow::receiveOnionFrame);
    connect(&model,
            &Model::disableOnion,
            this,
            &MainWindow::disableOnionFrame);
    connect(ui->onionButton,
            &QAbstractButton::clicked,
            &model,
            &Model::toggleOnion);
    connect(ui->nextFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::updateOnion);

    connect(ui->newFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::updateOnion);
    connect(ui->previousFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::updateOnion);
    connect(ui->deleteFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::updateOnion);

    connect(ui->pushFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::pushSelectedFrame);

    connect(ui->pullFrameButton,
            &QAbstractButton::clicked,
            &model,
            &Model::pullSelectedFrame);
    // connect(&model,
    //         &Model::addFrameToPreview,
    //         this,
    //         &MainWindow::frameSelectorUpdated);

    connect(ui->actualSizePreview,
            &QAbstractButton::toggled,
            this,
            &MainWindow::toggleActualPreview);

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
    ui->undoButton->setEnabled(true);
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


    ui->previewLabel->setPixmap(pixmap.scaledToHeight(ui->previewLabel->geometry().height(),Qt::FastTransformation));
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

    JSON::load(model, selectedFileName);
    emit fileLoadedSignal(model.animationFrames[0].imageData);
    canvasChanged = false;
}

void MainWindow::onCreateClicked()
{
    if(canvasChanged)
    {
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            onSaveClicked();
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return;
        default:
            // should never be reached
            break;
        }
    }

    //we can change the max val to something else
    int input = QInputDialog::getInt(this, tr("QInputDialog::getInt()"), tr("Please enter canvas size: "), 32, 4, 128, 1);
    model.resetModel(input);
    canvasChanged = false;
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


void MainWindow::onUndoClicked()
{
    emit undoClickedSignal();
}

void MainWindow::onRedoClicked()
{
    emit redoClickedSignal();
}

void MainWindow::enableUndoRedo()
{
    //checks the pastFrame and futureFrame sizes to enable redo/undo
    ui->undoButton->setEnabled(model.animationFrames[model.currentFrame].pastFrameHistory.size() > 0);
    ui->redoButton->setEnabled(model.animationFrames[model.currentFrame].futureFrameHistory.size() > 0);
}

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

void MainWindow::updateFrameSelector(std::vector<QImage> previewImages)
{
    //std::cout << "calling mainwindow update frame preview" << std::endl;
    ui->frameLabel1->setPixmap(QPixmap::fromImage(previewImages.at(0)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel2->setPixmap(QPixmap::fromImage(previewImages.at(1)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel3->setPixmap(QPixmap::fromImage(previewImages.at(2)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel4->setPixmap(QPixmap::fromImage(previewImages.at(3)).scaledToHeight(100,Qt::FastTransformation));
    ui->frameLabel5->setPixmap(QPixmap::fromImage(previewImages.at(4)).scaledToHeight(100,Qt::FastTransformation));
}

// Jai's onion stuff
void MainWindow::receiveOnionFrame(QImage onionImage)
{
    QPixmap onionPixmap = QPixmap::fromImage(onionImage);
    ui->onionLabel->setPixmap(onionPixmap.scaledToHeight(500,Qt::FastTransformation));


    ui->onionButton->setStyleSheet(QString("QPushButton {background-color: rgb(100,100,100);}"));
}

void MainWindow::disableOnionFrame(QImage onionImage)
{
    QPixmap onionPixmap = QPixmap::fromImage(onionImage);
    ui->onionLabel->setPixmap(onionPixmap.scaledToHeight(500,Qt::FastTransformation));

    ui->onionButton->setStyleSheet(QString("QPushButton {background-color: rgb(150,255,150);}"));
}

void MainWindow::toggleActualPreview(bool checked)
{

    QRect currentGeometry = ui->previewLabel->geometry();

    if(checked)
    {
        currentGeometry.setHeight(model.frameSize);
        currentGeometry.setWidth(model.frameSize);


    }
    else
    {
        currentGeometry.setHeight(100);
        currentGeometry.setWidth(100);
    }

    ui->previewLabel->setGeometry(currentGeometry);
}
void MainWindow::colorButtonClicked()
{
    colorPicker->open();
    ui->colorButton->setEnabled(false);
}

void MainWindow::colorButtonClosed()
{
    ui->colorButton->setEnabled(true);
}




