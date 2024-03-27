#include "frame.h"
#include <QPen>
#include <ostream>

Frame::Frame() {}

Frame::Frame(int size) : size(size)
{
   imageData = QImage(size, size, QImage::Format_ARGB32);
}

Frame::~Frame()
{
}


void Frame::setPixel(QPointF point, QPen pen)
{
    //int pixelArrayIndex = (frameY * size + frameX) * 4;

    imageData.setPixelColor(point.toPoint(), pen.color());

}
