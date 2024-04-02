#include "frame.h"
#include <QPen>
#include <iostream>
#include <ostream>
#include <QDebug>

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

void Frame::setPixel(QPointF point, QPen pen, bool mousePressed, bool paintCall)
{
    if(mousePressed) //version 2 -> mouse drags instead of single pixel color
    {
        pastFrameHistory.push_back(imageData.copy());
        futureFrameHistory.clear();
    }

    QPainter painter(&imageData);
    painter.setPen(pen);

    if(paintCall)
    {


        painter.drawPoint(point);
    }
    else
    {
        QRect pointRectForm(point.toPoint().rx(),point.toPoint().ry(),pen.width(),pen.width());
        QColor e(0,0,0,0);
        const QRgb erase = e.rgb();
        // pen.setColor(erase);
        // painter.setPen(pen);


        for(int i= point.toPoint().rx(); i<pen.width()+point.toPoint().rx();i++ )
            for(int j = point.toPoint().ry(); j<point.toPoint().ry()+pen.width();j++)
            {
                QPoint pix((int)i,(int)j);
                // imageData.setPixel(pix,erase);
                imageData.setPixelColor(pix,e);
            }

        // painter.eraseRect(pointRectForm);
        // painter.drawRect(pointRectForm);
    }
}

void Frame::undo()
{
    if(pastFrameHistory.size() > 0)
    {
        futureFrameHistory.push_back(imageData.copy());
        imageData = pastFrameHistory.back().copy();
        pastFrameHistory.pop_back();
    }
}

void Frame::redo()
{
    if(futureFrameHistory.size() > 0)
    {
        pastFrameHistory.push_back(imageData.copy());
        imageData = futureFrameHistory.back().copy();
        futureFrameHistory.pop_back();
    }
}

