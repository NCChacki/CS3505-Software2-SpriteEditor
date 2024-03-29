#ifndef FRAME_H
#define FRAME_H

#include <QImage>
#include <QPainter>
class Frame
{
public:
    ///
    /// \brief Default constructor for frame
    ///
    Frame();

    ///
    /// \brief Constructor for frame
    /// \param size of frame
    ///
    ///
    Frame(int size);

    ///
    /// \brief Destructor for frame. Deletes backing pixel array.
    ///
    ~Frame();


    ///
    /// \brief Frame method for setting the pixel at the specified FRAME location
    /// to the specified color.
    /// \param frameY Y coordinate within frame.
    /// \param frameX X coordinate within frame. coordinate is O, O in top left corner
    /// \param rgba
    ///
    void setPixel(QPointF point,  QPen pen);


    int size;

    QImage imageData;




private:
    //int size;
    //int* pixels;
};

#endif // FRAME_H
