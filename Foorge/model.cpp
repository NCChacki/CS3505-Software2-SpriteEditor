#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
    //clean up dynamically allocated timer
    delete previewTimer;
}

Model::Model(QObject *parent, int size) : QObject(parent)
{

    //setup first frame
    frameSize = size;
    Frame firstFrame(frameSize);
    animationFrames.push_back(firstFrame);
    currentFrame=0;
    paintEnabled=true;


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

    // jai onion stuff
    onionState=false;
    QImage blank(frameSize,frameSize,QImage::Format_ARGB32);
    blank.fill(QColor(0,0,0,0));
    // alert the view of initialized framepreview
    // emit sendPreviewFrames(getPreviewFrames());
}

void Model::frameRateChanged(int newFrameRate)
{
    timerFrameRate = newFrameRate;
    previewTimer->stop();
    connect(previewTimer, &QTimer::timeout, this, &Model::timeToUpdatePreview);
    previewTimer->start(1000/newFrameRate);
    //std::cout << "calling frameRateChanged with framerate: ##################3" << newFrameRate << std::endl;
}

void Model::imageChanged(QPointF point, bool mousePressed)
{
    QWidget* canvasWidget = qobject_cast<QWidget*>(sender());

    QPointF transformedPoint((point.rx()/canvasWidget->height())*frameSize, (point.ry()/canvasWidget->height())*frameSize);


    std::cout <<"Canvas:" << std::endl;
    std::cout << " x: " << point.rx() << " y: " << point.ry() << std::endl;

    std::cout << "Frame" << std::endl;

    std::cout << "FrameSize = " << frameSize << std::endl;
    std::cout << "CanvasWidget Size = " << canvasWidget->height() << std::endl;
    std::cout << " x: " << (point.rx()/canvasWidget->height())*frameSize << " y: " << (point.ry()/canvasWidget->height())*frameSize << std::endl;


    animationFrames.at(currentFrame).setPixel(transformedPoint, pen, mousePressed, paintEnabled);

    emit imageUpdated(animationFrames.at(currentFrame).imageData);

    //emit sendPreviewFrames(getPreviewFrames());
    //This is temporary just to ensure that signal is being emitted.
    //emit addFrameToPreview(animationFrames.at(currentFrame).imageData);

}

void Model::resetModel(int size)
{
    currentFrame=0;
    animationFrames.clear();
    frameSize = size;
    Frame firstFrame(frameSize);
    animationFrames.push_back(firstFrame);

    emit imageUpdated(animationFrames.at(currentFrame).imageData);
    emit sendPreviewFrames(getPreviewFrames());
}

void Model::timeToUpdatePreview()
{
    if(currentPreviewFrame >= animationFrames.size())
        currentPreviewFrame=0;

    emit previewUpdated(animationFrames.at(currentPreviewFrame).imageData);

    currentPreviewFrame++;
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
            //std::cout << "finding 1 frame to the left " <<std::endl;
            previewFrames.push_back(blankImage);
            previewFrames.push_back(animationFrames.at(currentFrame-1).imageData);
            previewFrames.push_back(animationFrames.at(currentFrame).imageData);
        }
        if(currentFrame == 0)
        {
            //std::cout <<"finding no frames to the left" << std::endl;
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
       // std::cout << "finding 2 frames to the left" <<std::endl;
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
           // std::cout <<"finding 1 frame to right" << std::endl;
            previewFrames.push_back(animationFrames.at(currentFrame+1).imageData);
            previewFrames.push_back(blankImage);
        }
        // if there are no frames to the right
        // the same as the selected frame being the last frame
        if(currentFrame == animationFrames.size()-1)
        {
            // push back two empty frames
            //std::cout <<"No frames to the right" << std::endl;
            previewFrames.push_back(blankImage);
            previewFrames.push_back(blankImage);
        }
    }
    // if there are at least two frames to the right
    else
    {
        //std::cout << "finding at least two frames to the right" << std::endl;
        //push back the two frames to the right
        previewFrames.push_back(animationFrames.at(currentFrame+1).imageData);
        previewFrames.push_back(animationFrames.at(currentFrame+2).imageData);
    }

    return previewFrames;
}

// <<<<<<< Updated upstream
// void Model::initializeSelector()
// {
//     emit sendPreviewFrames(getPreviewFrames());
// }

void Model::deleteFrame()
{

    // if the selected frame is the only frame
    if(animationFrames.size() == 1)
        return;

    // otherwise, stop the previewTimer briefly to allow deletion.

    //previewTimer->stop();
    //std::cout << "deleting frame at : " << currentFrame << std::endl;
    animationFrames.erase(animationFrames.begin()+currentFrame);
    // select the previous frame
    //std::cout << "Changes the size to: " << animationFrames.size() << std::endl;
    if(currentFrame != 0)
        currentFrame--;

    //previewTimer->start(1000/timerFrameRate);
    //std::cout << "updating the image so the new selected frame is at : " << currentFrame << std::endl;
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
    emit sendPreviewFrames(getPreviewFrames());

}

void Model::toggleOnion()
{
    if (onionState==true)
    {
        onionState=false;
        emit disableOnion(blank);
    }
    else
    {
        onionState=true;
        if (currentFrame!=0)
        {
            QImage onioned(animationFrames[currentFrame-1].imageData);
            for (int x=0;x<onioned.width();x++)
                for (int y=0;y<onioned.height();y++)
                {
                    QColor onionedPixel(onioned.pixelColor(x,y));
                    onionedPixel.setAlpha(onionedPixel.alpha()/2);
                    onioned.setPixelColor(x,y,onionedPixel);
                }
            emit enableOnion(onioned);
            //emit enableOnion(animationFrames[currentFrame-1].imageData);
        }
        else emit enableOnion(blank);
    }
}

void Model::updateOnion()
{
    if (onionState && currentFrame!=0)
    {
        QImage onioned(animationFrames[currentFrame-1].imageData);
        for (int x=0;x<onioned.width();x++)
        for (int y=0;y<onioned.height();y++)
        {
            QColor onionedPixel(onioned.pixelColor(x,y));
            onionedPixel.setAlpha(onionedPixel.alpha()/2);
            onioned.setPixelColor(x,y,onionedPixel);
        }
        emit enableOnion(onioned);
    }
    else emit enableOnion(blank);
}

void Model::colorChanged(QColor newColor)
{
    paintEnabled=true;
    pen.setColor(newColor);
}

void Model::eraseClicked()
{
    // QColor erase(0,0,0,0);
    // pen.setColor(erase);
    paintEnabled=false;

}

void Model::eraseScreen()
{
    QColor erase(0,0,0,0);
    animationFrames.at(currentFrame).imageData.fill(erase);
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
}

void Model::brushSizeChanged(QString newSize)
{
    pen.setWidth(newSize.toInt());
}

void Model::pushSelectedFrame()
{
    // if they're at the last frame, do nothing
    if(currentFrame == animationFrames.size()-1)
        return;

    // if they're not at the last frame
    // swap the current frame with the next one
    std::swap(animationFrames.at(currentFrame), animationFrames.at(currentFrame+1));
    // update the current frame to keep the frame you're moving selected
    currentFrame++;

    // alert the view of these changes
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
    emit sendPreviewFrames(getPreviewFrames());
    updateOnion();
}

void Model::pullSelectedFrame()
{
    if(currentFrame==0)
        return;

    std::swap(animationFrames.at(currentFrame), animationFrames.at(currentFrame-1));
    currentFrame--;

    // alert the view of these changes
    emit imageUpdated(animationFrames.at(currentFrame).imageData);
    emit sendPreviewFrames(getPreviewFrames());
    updateOnion();
}

void Model::undoFrame()
{
    animationFrames[currentFrame].undo();
    emit imageUpdated(animationFrames[currentFrame].imageData);
}

void Model::redoFrame()
{
    animationFrames[currentFrame].redo();
    emit imageUpdated(animationFrames[currentFrame].imageData);
}

void Model::bringBackFramesAfterLoad()
{
    emit imageUpdated(animationFrames[currentFrame].imageData);
    emit sendPreviewFrames(getPreviewFrames());
}

