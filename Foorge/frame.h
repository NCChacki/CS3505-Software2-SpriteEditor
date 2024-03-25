#ifndef FRAME_H
#define FRAME_H

class Frame
{
public:
    ///
    /// \brief Default constructor for frame
    ///
    Frame();

    ///
    /// \brief Constructor for frame
    /// \param width of frame
    /// \param height of frame
    ///
    Frame(int width, int height) : width{width}, height{height}

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
    setPixel(int frameX, int frameY, int* rgba);






private:
    int width,height;
    int* pixels;
};

#endif // FRAME_H
