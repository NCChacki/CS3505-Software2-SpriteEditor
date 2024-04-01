#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <iostream>
#include <QPointF>

/**
 * @brief CanvasWidget class header, inherits QWidget
 *
 * @authors: Victoria Yong, Norman Canning, Evan Blanchard, Jaibir Singh Sandhu
 * @date: 4/1/2024
 */
class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CanvasWidget - default contructor
     * @param parent - pointer to QWidget set to nullptr
     */
    explicit CanvasWidget(QWidget *parent = nullptr);

    /**
      * @brief mouseMoveEvent - Handles mouse movement events on the canvas widget.
      * @param event - pointer to the QMouseEvent
      */
     void mouseMoveEvent(QMouseEvent * event);

    /**
      * @brief mousePressEvent - Handles mouse press events on the canvas widget.
      * @param event - pointer to the QMouseEvent
      */
     void mousePressEvent(QMouseEvent * event);

signals:
     /**
      * @brief canvasClicked - signal to emit when
      * @param point - QPointF representing where the click event occurred
      * @param mousePressed - true is mouse press event occurs, false otherwise
      */
     void canvasClicked(QPointF point, bool mousePressed);

};

#endif // CANVASWIDGET_H
