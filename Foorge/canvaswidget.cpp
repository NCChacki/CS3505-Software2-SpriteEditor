#include "canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}
{}


void CanvasWidget::mouseMoveEvent(QMouseEvent * event)
{
    QPointF pos = event->position();

    //std::cout << pos.rx() << ", " << pos.ry() << std::endl;

    emit canvasClicked(pos.rx(), pos.ry());

}
