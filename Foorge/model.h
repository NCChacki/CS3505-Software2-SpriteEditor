#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>
#include <QPen>
#include <QColor>
#include <QWidget>
#include <QTimer>
#include <iostream>

class Model : public QObject
{

    Q_OBJECT

public:

    ~Model();
    ///
    /// \brief resetModel - clears the Model object but doesn't destroy it
    ///
    void resetModel();

    explicit Model(QObject *parent = nullptr);
    std::vector<Frame> animationFrames;
    int currentFrame;



private:
    // int* currentColor;
    // int brushSize;
    int frameSize;
    bool onionState;
    //std::vector<Frame> animationFrames;

    // current color and brush size
    QPen pen;

    //Temporary variable for window size
    // not sure if this is where we will want to keep this,
    // or if we want to pass this to the model somewhere
    int windowSize = 500;

    // preview variables
    int currentPreviewFrame = 0;
    QTimer* previewTimer;
    int timerFrameRate;

    ///
    /// \brief helper method for deterimining what 5 frames should be sent to view
    /// to be shown in frame preview window
    /// \return a vector of 5 images with the image at index 2 being the selected frame
    ///
    std::vector<QImage> getPreviewFrames();





public slots:
    void imageChanged(QPointF point);
<<<<<<< Updated upstream
    void timeToUpdatePreview();
    void addNewFrame();
    void nextFrame();
    void previousFrame();

signals:
    void imageUpdated(QImage image);
    void previewUpdated(QImage image);
    ///
    /// \brief signal for alerting the view of what frames should be displayed within
    /// the frame preview.
    /// The third image is the currently selected image
    /// \param imageArray is an array of the 5 QImages that need to be displayed
    ///
    void sendPreviewFrames(std::vector<QImage> imageVector);
    //void addFrameToPreview(QImage image);

=======
    void toggleOnion();

signals:
    void imageUpdated(QImage image);
    void enableOnion(QImage image);
    void disableOnion(QImage image);
>>>>>>> Stashed changes


};

#endif // MODEL_H
