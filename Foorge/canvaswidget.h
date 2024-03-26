#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <iostream>


class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget *parent = nullptr);

     void mouseMoveEvent(QMouseEvent * event);

signals:
     void canvasClicked(int canvasX, int canvasY);
};

#endif // CANVASWIDGET_H
