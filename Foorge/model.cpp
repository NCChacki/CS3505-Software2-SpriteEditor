#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
    //clean up dynamically allocated timer
    delete previewTimer;
}

Model::Model(QObject *parent) : QObject(parent)
{

    //setup first frame
    frameSize = 32;
    Frame firstFrame(frameSize);
    animationFrames.push_back(firstFrame);
    currentFrame=0;



    //prepare pen
    QColor color(255,0,0,255);
    pen.setColor(color);
    pen.setWidth(1);
    
    // initalize preview updating stuff

    // let the view know that the first frame is ready to be added to preview
//emit addFrameToPreview(animationFrames.at(0).imageData);

    // initialize default framerate of 30fps
    timerFrameRate = 2;
    //create timer
    previewTimer = new QTimer(this);
    //connect timer to slot that will emit update signal
    connect(previewTimer, &QTimer::timeout, this, &Model::timeToUpdatePreview);
    //start the timer on its way
    previewTimer->start(1000/timerFrameRate);


    // alert the view of initialized framepreview
    emit sendPreviewFrames(getPreviewFrames());
}

void Model::imageChanged(QPointF point)
{
    QWidget* canvasWidget = qobject_cast<QWidget*>(sender());

    QPointF transformedPoint(point.rx()/(canvasWidget->height()/frameSize), point.ry()/(canvasWidget->height()/frameSize));

    animationFrames.at(currentFrame).setPixel(transformedPoint,pen);

    emit imageUpdated(animationFrames.at(currentFrame).imageData);

    //This is temporary just to ensure that signal is being emitted.
    //emit addFrameToPreview(animationFrames.at(currentFrame).imageData);
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
    currentFrame = animationFrames.size()-1;

    emit imageUpdated(animationFrames.at(currentFrame).imageData);
    emit sendPreviewFrames(getPreviewFrames());
}

void Model::nextFrame()
{
    // if the currently selected frame is already the last frame
    if(currentFrame == animationFrames.size()-1)
        return;

    // otherwise, select the next frame
    currentFrame++;
    // alert the canvas
    emit imageUpdated(animationFrames.at(currentFrame).imageData);

    // alert the view that the frame preview window needs to be updated
    emit sendPreviewFrames(getPreviewFrames());
}


void Model::previousFrame()
{
    // if the currently selected frame is the first frame
    if(currentFrame == 0)
        return;

    // otherwise, select the previous frame
    currentFrame--;

    // alert the canvas
    emit imageUpdated(animationFrames.at(currentFrame).imageData);

    // alert the view that the frame preview window needs to be updated
    emit sendPreviewFrames(getPreviewFrames());


}

std::vector<QImage> Model::getPreviewFrames()
{
    std::vector<QImage> previewFrames;

    // create a blank image to fill empty frame preview slots
    QImage blankImage;
    QColor transparent(255,255,255,255);
    blankImage.fill(transparent);

    // handles selected frame and frames to the left
    // if there are less than 2 frames to the left
    if(currentFrame < 2)
    {
        // if there is 1 frame to the left
        if(currentFrame == 1)
        {
            // push back a blank Qimage, then the image at 0, then the preview frame
            std::cout << "finding 1 frame to the left " <<std::endl;
            previewFrames.push_back(blankImage);
            previewFrames.push_back(animationFrames.at(currentFrame-1).imageData);
            previewFrames.push_back(animationFrames.at(currentFrame).imageData);
        }
        if(currentFrame == 0)
        {
            std::cout <<"finding no frames to the left" << std::endl;
            // push back 2 blank Qimages, then the selected frame
            previewFrames.push_back(blankImage);
            previewFrames.push_back(blankImage);
            previewFrames.push_back(animationFrames.at(currentFrame).imageData);
        }
    }
    // if there are at least two frames to the left
    else
    {
        // push the 2 frames before and the current frame
        std::cout << "finding 2 frames to the left" <<std::endl;
        previewFrames.push_back(animationFrames.at(currentFrame-2).imageData);
        previewFrames.push_back(animationFrames.at(currentFrame-1).imageData);
        previewFrames.push_back(animationFrames.at(currentFrame).imageData);
    }

    // handles frames to the right
    // if there are less than two frames to the right
    if(animationFrames.size() - currentFrame < 3)
    {
        // there is only 1 frame to the right
        if(animationFrames.size()-currentFrame == 2)
        {
            // push back the next frame then 1 empty frame
            std::cout <<"finding 1 frame to right" << std::endl;
            previewFrames.push_back(animationFrames.at(currentFrame+1).imageData);
            previewFrames.push_back(blankImage);
        }
        // if there are no frames to the right
        // the same as the selected frame being the last frame
        if(currentFrame == animationFrames.size()-1)
        {
            // push back two empty frames
            std::cout <<"No frames to the right" << std::endl;
            previewFrames.push_back(blankImage);
            previewFrames.push_back(blankImage);
        }
    }
    // if there are at least two frames to the right
    else
    {
        std::cout << "finding at least two frames to the right" << std::endl;
        //push back the two frames to the right
        previewFrames.push_back(animationFrames.at(currentFrame+1).imageData);
        previewFrames.push_back(animationFrames.at(currentFrame+2).imageData);
    }

    return previewFrames;
}



