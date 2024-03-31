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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model& model, QWidget *parent = nullptr); //
    ~MainWindow();
    Model& model;
    QMessageBox msgBox;
    bool canvasChanged = false;
    QColorDialog *colorPicker;

signals:
    void fileLoadedSignal(QImage image);
    void undoClickedSignal();
    void redoClickedSignal();

public slots:
    ///
    /// \brief slot to be subscribed to mouse events within CanvasWidget.
    /// This is where the logic for converting from Canvas coordinatees to
    /// frame coordinates needs to happen. Otherwise, the model would need
    /// to know the dimensions of the canvas widget.
    /// \param canvasX
    /// \param canvasY
    ///
    void pixelChanged(QPointF point);

    void onSaveClicked();
    void onLoadClicked();
    void onCreateClicked();

    void onUndoClicked();
    void onRedoClicked();

    void enableUndoRedo();

    ///
    /// \brief updates image in label
    /// \param image
    ///
    void updateLabelImage(QImage image);
    void updatePreviewImage(QImage image);

    ///
    /// \brief slot for updating the frame preview window
    /// \param previewImages vector of preview images, selected image
    /// is at index 3
    ///
    void updateFramePreview(std::vector<QImage> previewImages);

    void receiveOnionFrame(QImage onionImage);
    void disableOnionFrame(QImage onionImage);



    //void frameSelectorUpdated(QImage image);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
