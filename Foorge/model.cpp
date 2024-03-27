#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
    //clean up dynamically allocated timer
    delete previewTimer;
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
    
    // initialize default framerate of 30fps
    timerFrameRate = 2;
    //create timer
    previewTimer = new QTimer(this);
    //connect timer to slot that will emit update signal
    connect(previewTimer, &QTimer::timeout, this, &Model::timeToUpdatePreview);
    //start the timer on its way
    previewTimer->start(1000/timerFrameRate);
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

void Model::timeToUpdatePreview()
{
    emit previewUpdated(animationFrames.at(currentPreviewFrame).imageData);

    currentPreviewFrame++;

    if(currentPreviewFrame == animationFrames.size())
        currentPreviewFrame=0;
}

void Model::addNewFrame()
{
    Frame newFrame(frameSize);
    animationFrames.push_back(newFrame);
}



