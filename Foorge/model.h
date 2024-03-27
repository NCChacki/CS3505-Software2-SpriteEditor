#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>
#include <QPen>
#include <QColor>
#include <QWidget>
#include <QTimer>

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





public slots:
    void imageChanged(QPointF point);
    void timeToUpdatePreview();
    void addNewFrame();

signals:
    void imageUpdated(QImage image);
    void previewUpdated(QImage image);



};

#endif // MODEL_H
