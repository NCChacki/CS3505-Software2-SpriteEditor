#ifndef FRAME_H
#define FRAME_H

#include <QImage>
#include <QPainter>
#include <QColor>

/**
 * @brief Frame class header
 *
 * @authors: Victoria Yong, Norman Canning, Evan Blanchard, Jaibir Singh Sandhu
 * @date: 4/1/2024
 */
class Frame
{
public:

    /**
     * @brief Default constructor for frame
     */
    Frame();

    /**
     * @brief Frame - Constructor for frame
     * @param size - size of frame
     */
    Frame(int size);

    /**
     * @brief Destructor for frame. Deletes backing pixel array.
     */
    ~Frame();

    /**
     * @brief setPixel - Frame method for setting the pixel at the specified FRAME location
       to the specified color.
     * @param point - (frameX, frameY) coordinate within frame. (0,0) in top left corner
     * @param pen - QPen object
     * @param mousePressed - true is mouse press event occurs, false otherwise
     * @param paintCall - true if pixel color is not transparent, false otherwise. Default set to true.
     */
    void setPixel(QPointF point,  QPen pen, bool mousePressed, bool paintCall = true);

    /**
     * @brief undo - undoes the last action performed on this frame.
     * Undo action only allowed if an action has been done on the canvas.
     * Otherwise, this method has no effect.
     */
    void undo();

    /**
     * @brief redo - redoes the last undone action of this frame
     * Redo action only allowed if there is an "undone" action that occured prior.
     * Otherwise, the method has no effect.
     */
    void redo();

    /**
     * @brief size - frame size
     */
    int size;

    /**
     * @brief imageData - contains information (pixel coordinates, RGBA vals, etc) about this current frame
     */
    QImage imageData;

    /**
     * @brief pastFrameHistory - a vector containing frames that are created before the most current frame
     */
    std::vector<QImage>pastFrameHistory;

    /**
     * @brief futureFrameHistory - a vector containing frames that are created after the current frame
     */
    std::vector<QImage>futureFrameHistory;

};

#endif // FRAME_H
