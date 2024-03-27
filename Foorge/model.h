#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>
#include <QPen>
#include <QColor>

class Model : public QObject
{

    Q_OBJECT

public:

    ~Model();

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





public slots:
    void imageChanged(QPointF point);

signals:
    void imageUpdated(QImage image);



};

#endif // MODEL_H
