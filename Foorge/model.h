#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>

class Model : public QObject
{

    Q_OBJECT

public:
    //Model();

    // Model(int frameSize);

    explicit Model(QObject *parent = nullptr);

    ~Model();

private:
    int* currentColor;
    int brushSize;
    int frameSize;
    std::vector<Frame> animationFrames;

public slots:
    void pixelChanged(int canvasX, int canvasY);

signals:



};

#endif // MODEL_H
