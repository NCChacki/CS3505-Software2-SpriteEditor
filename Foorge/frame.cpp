#include "frame.h"
#include <QPen>
#include <iostream>

Frame::Frame() {}

Frame::Frame(int size) : size(size)
{
   imageData = QImage(size, size, QImage::Format_ARGB32);
   QColor transparent(255,255,255,0);
   imageData.fill(transparent);
}

Frame::~Frame()
{
}


void Frame::setPixel(QPointF point, QPen pen)
{
    QPainter painter(&imageData);
    painter.setPen(pen);
    std::cout<< painter.pen().color().alpha()<<std::endl;
    painter.drawPoint(point);


}
