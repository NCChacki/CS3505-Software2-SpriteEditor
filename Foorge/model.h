#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>

class Model : public QObject
{

    Q_OBJECT

public:

    ~Model();

    explicit Model(QObject *parent = nullptr);
    std::vector<Frame> animationFrames;



private:
    int* currentColor;
    int brushSize;
    int frameSize;
    //std::vector<Frame> animationFrames;



public slots:
    void pixelChanged(int canvasX, int canvasY);

signals:



};

#endif // MODEL_H
