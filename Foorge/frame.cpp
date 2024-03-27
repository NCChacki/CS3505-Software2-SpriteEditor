#include "frame.h"
#include <QPen>
#include <ostream>

Frame::Frame() {}

Frame::Frame(int size) : size(size)
{
    pixels = QImage(size, size, QImage::Format_Indexed8);
}

Frame::~Frame()
{
}


void Frame::setPixel(QPointF point, QPen pen)
{
    //int pixelArrayIndex = (frameY * size + frameX) * 4;

    pixels.setPixelColor(point.toPoint(), pen.color());

}
