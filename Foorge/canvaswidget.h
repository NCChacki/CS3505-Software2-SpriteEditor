#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include <QPointF>


class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget *parent = nullptr);

     void mouseMoveEvent(QMouseEvent * event);
     void mousePressEvent(QMouseEvent * event);

signals:
     void canvasClicked(QPointF point, bool mousePressed);

};

#endif // CANVASWIDGET_H
