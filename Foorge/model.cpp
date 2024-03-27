#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
}

Model::Model(QObject *parent) : QObject(parent)
{

    Frame firstFrame(64);
    animationFrames.push_back(firstFrame);
    currentFrame=0;
    QColor color(255,0,0,255);
    pen.setColor(color);
    pen.setWidth(1000);
}

void Model::imageChanged(QPointF point)
{
    animationFrames.at(currentFrame).setPixel(point,pen);
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
}

void Model::resetModel()
{
    animationFrames.clear();
    currentFrame = 0;
}



