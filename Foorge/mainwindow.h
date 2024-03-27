#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "model.h"
#include <QPointF>

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


    ///
    /// \brief updates image in label
    /// \param image
    ///
    void updateLabelImage(QImage image);
    void onLoadClicked();
    // void onCreateClicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
