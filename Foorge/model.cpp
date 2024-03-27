#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
}

Model::Model(QObject *parent) : QObject(parent)
{

    frameSize = 16;
    Frame firstFrame(frameSize);
    animationFrames.push_back(firstFrame);
    currentFrame=0;
    QColor color(255,0,0,255);
    pen.setColor(color);
    pen.setWidth(1);
}

void Model::imageChanged(QPointF point)
{
    QWidget* canvasWidget = qobject_cast<QWidget*>(sender());


    QPointF transformedPoint(point.rx()/(canvasWidget->height()/frameSize), point.ry()/(canvasWidget->height()/frameSize));

    animationFrames.at(currentFrame).setPixel(transformedPoint,pen);
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
}

void Model::resetModel()
{
    animationFrames.clear();
    currentFrame = 0;
}



