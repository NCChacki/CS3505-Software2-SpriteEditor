#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
}

Model::Model(QObject *parent) : QObject(parent)
{

    Frame firstFrame(16);
    animationFrames.push_back(firstFrame);
}

void Model::pixelChanged(QPointF point)
{
    animationFrames.at(currentFrame).setPixel(point,pen);
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
}



