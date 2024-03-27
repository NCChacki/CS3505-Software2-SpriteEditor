#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
}

Model::Model(QObject *parent) : QObject(parent)
{

    Frame firstFrame(16);
    animationFrames.push_back(firstFrame);
    currentFrame=0;
    QColor color(255,0,0,255);
    pen.setColor(color);
    pen.setWidth(1);
}

void Model::imageChanged(QPointF point)
{

    QPointF transformedPoint(point.rx()/(windowSize/16), point.ry()/(windowSize/16));

    animationFrames.at(currentFrame).setPixel(transformedPoint,pen);
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
}

void Model::resetModel()
{
    animationFrames.clear();
    currentFrame = 0;
}



