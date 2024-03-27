#include "canvaswidget.h"

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget{parent}
{}


void CanvasWidget::mouseMoveEvent(QMouseEvent * event)
{
    QPointF pos = event->position();

    std::cout << pos.rx() << ", " << pos.ry() << std::endl;
    std::cout << "emitting this position ^ " << std::endl;

    emit canvasClicked(pos);

}

void CanvasWidget::mousePressEvent(QMouseEvent * event)
{
    QPointF pos = event->position();

    std::cout << pos.rx() << ", " << pos.ry() << std::endl;
    std::cout << "emitting this position ^ " << std::endl;

    emit canvasClicked(pos);
}
