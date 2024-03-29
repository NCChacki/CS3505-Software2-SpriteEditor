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


void Frame::setPixel(QPointF point, QPen pen, bool paintCall)
{

    QPainter painter(&imageData);
    painter.setPen(pen);

    if(paintCall)
    {

        std::cout<< painter.pen().color().alpha()<<std::endl;
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
                QPoint pix(i,j);
                // imageData.setPixel(pix,erase);
                imageData.setPixelColor(pix,e);

            }


        // painter.eraseRect(pointRectForm);
        // painter.drawRect(pointRectForm);
    }


}
