#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "model.h"
#include <QPointF>
#include <QMessageBox>
#include <QCloseEvent>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 *  @brief MainWindow header class
 *
 *  @authors: Victoria Yong, Norman Canning, Evan Blanchard, Jaibir Singh Sandhu
 *  @date: 4/1/2024
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow - constructs main window and its corresponding features and connections
     * @param model - model reference
     * @param parent
     */
    MainWindow(Model& model, QWidget *parent = nullptr);

    /**
     * @brief ~MainWindow - deconstructor
     */
    ~MainWindow();

    /**
     * @brief model - model reference
     */
    Model& model;

    /**
     * @brief msgBox - message box to display warning messages and file options for loading and saving
     */
    QMessageBox msgBox;

    /**
     * @brief canvasChanged - boolean to represent any changes to the current canvas
     */
    bool canvasChanged = false;

    QColorDialog *colorPicker;

signals:

    /**
     * @brief fileLoadedSignal - signal to emit when user has selected a file to load to current project
     * @param image - QImage object to be loaded into the current project.
     */
    void fileLoadedSignal(QImage image);

    /**
     * @brief undoClickedSignal - signal to emit when the undo button has been clicked
     */
    void undoClickedSignal();

    /**
     * @brief redoClickedSignal - signal to emit when the redo button has been clicked
     */
    void redoClickedSignal();

public slots:

    /**
     * @brief pixelChanged -  slot to be subscribed to mouse events within CanvasWidget.
       This is where the logic for converting from Canvas coordinatees to
       frame coordinates needs to happen. Otherwise, the model would need
       to know the dimensions of the canvas widget.

     * @param point - coordinated of the changed pixel
     */
    void pixelChanged(QPointF point);

    /**
     * @brief onSaveClicked - slot to be subscribed to when save project button has been clicked
     */
    void onSaveClicked();

    /**
     * @brief onLoadClicked - slot to be subscribed to when load project button has been clicked
     */
    void onLoadClicked();

    /**
     * @brief onCreateClicked - slot to be subscribed to when create project button has been clicked
     */
    void onCreateClicked();

    /**
     * @brief onUndoClicked - slot to be subscribed to when undo button has been clicked
     */
    void onUndoClicked();

    /**
     * @brief onRedoClicked - slot to be subscribed to when redo button has been clicked
     */
    void onRedoClicked();

    /**
     * @brief enableUndoRedo - slot to be subscribed to when current canvas has enough actions for the undo
     * and redo buttons to be enabled
     */
    void enableUndoRedo();

    /**
     * @brief updateLabelImage - updates image in canvas
     * @param image - image to be dispalyed
     */
    void updateLabelImage(QImage image);

    /**
     * @brief updatePreviewImage - updates image in the preview
     * @param image - image to be displayed
     */
    void updatePreviewImage(QImage image);

    /**
     * @brief updateFramePreview - slot for updating the frame preview window
     * @param previewImages - vector of preview images, selected image is at index 3
     */
    void updateFramePreview(std::vector<QImage> previewImages);

    /**
     * @brief receiveOnionFrame
     * @param onionImage
     */
    void receiveOnionFrame(QImage onionImage);

    /**
     * @brief disableOnionFrame
     * @param onionImage
     */
    void disableOnionFrame(QImage onionImage);


    void colorButtonClicked();

    void colorButtonClosed();



    //void frameSelectorUpdated(QImage image);

protected:

    /**
     * @brief closeEvent - handles the event of closing the main window
     * @param event - close event pointer to QCloseEvent object
     */
    void closeEvent(QCloseEvent *event);

private:
    /**
     * @brief ui - pointer to the MainWindow's ui
     */
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
