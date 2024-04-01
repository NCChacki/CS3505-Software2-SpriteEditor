#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "frame.h"
#include <QObject>
#include <QPen>
#include <QColor>
#include <QWidget>
#include <QTimer>
#include <iostream>

/**
 * @brief The Model class header, inherits QObject
 *
 * @authors: Victoria Yong, Norman Canning, Evan Blanchard, Jaibir Singh Sandhu
 * @date: 4/1/2024
 */
class Model : public QObject
{

    Q_OBJECT

public:

    /**
     * Destructor - clears animation frame and deletes preview timer
    */
    ~Model();

    /**
     * @brief resetModel - clears the animation frame but doesn't delete the Model
     * @param size - default frame size set to 32
     */
    void resetModel(int size = 32);

    /**
     * @brief Model -
     * @param parent
     * @param size
     */
    explicit Model(QObject *parent = nullptr, int size = 32);

    /**
     * @brief bringBackFramesAfterLoad - used to set preview frames when loading in a project
     */
    void bringBackFramesAfterLoad();

    /**
     * @brief animationFrames - frames of current project
     */
    std::vector<Frame> animationFrames;

    /**
     * @brief currentFrame - the index of the current frame in the animationFrames vector
     */
    int currentFrame;

    /**
     * @brief frameSize - size of the frames in the project
     */
    int frameSize;


private:




    /**
     * @brief current pen for drawing on frame
     */
    QPen pen;

    // preview variables

    /**
     * @brief currentPreviewFrame index of current animation frame, default 0
     */
    int currentPreviewFrame = 0;
    /**
     * @brief previewTimer timer used to control fps of the preview
     */
    QTimer* previewTimer;
    /**
     * @brief timerFrameRate the fps of the preview
     */
    int timerFrameRate;
    /**
     * @brief blank defualt image
     */
    QImage blank;

    /**
     * @brief paintEnabled true is bursh is currently painting, false if erasing
     */
    bool paintEnabled;


    /**
     * @brief getPreviewFrames helper method for deterimining what 5 frames should be sent to view
     * to be shown in frame preview window
     * @return a vector of 5 images with the image at index 2 being the selected frame
     */
    std::vector<QImage> getPreviewFrames();

    /**
     * @brief onionState state of onion feature
     */
    bool onionState;


public slots:
    /**
     * @brief imageChanged slot for when image has been changed
     * @param point on canvas that has been changed
     * @param mousePressed - true is mouse press event occurs, false otherwise
     */
    void imageChanged(QPointF point, bool mousePressed);
    /**
     * @brief timeToUpdatePreview slot for when next frame of preview needs to be displayed
     */
    void timeToUpdatePreview();
    /**
     * @brief addNewFrame slot for when new frame is clicked, adding new fraem to the project
     */
    void addNewFrame();
    /**
     * @brief nextFrame slot for next frame is clicked.
     */
    void nextFrame();
    /**
     * @brief previousFrame slot for previous frame is clicked
     */
    void previousFrame();
    /**
     * @brief frameRateChanged slot for when the frame rate has been changed
     * @param newFrameRate the int repersting the new fps
     */
    void frameRateChanged(int newFrameRate);
    /**
     * @brief deleteFrame slot for delete frame is cliked, sends the index of the frame to be deleted
     */
    void deleteFrame();
    /**
     * @brief toggleOnion toggels onion button
     */
    void toggleOnion();
    /**
     * @brief updateOnion update onion's frames
     */
    void updateOnion();
    /**
     * @brief colorChanged color selected on the color picker
     * @param newColor the new selected color
     */
    void colorChanged(QColor newColor);
    /**
     * @brief eraseClicked slot for when the erase button has been clicked, erases rects tracked by mouse
     */
    void eraseClicked();
    /**
     * @brief eraseScreen slot for when the erase screeen button has been clicked. Setting all pixes to transparent
     */
    void eraseScreen();
    /**
     * @brief brushSizeChanged slot for when a new bursh size has been selected, updates the pen size
     * @param newSize
     */
    void brushSizeChanged(QString newSize);
    /**
     * @brief pushSelectedFrame slot for the current frame is moved back one in the project vector
     */
    void pushSelectedFrame();
    /**
     * @brief pullSelectedFrame slot for when the current frame is moved forward in the project vector
     */
    void pullSelectedFrame();
    /**
     * @brief undoFrame slot for when the undo frame button is clicked
     */
    void undoFrame();
    /**
     * @brief redoFrame slot for when the redo frame button is clicked
     */
    void redoFrame();


signals:
    /**
     * @brief imageUpdated signal for when the current frame has been succesfully changed and needs to be reflect on canvas
     * @param image updated image
     */
    void imageUpdated(QImage image);
    /**
     * @brief previewUpdated signal for when a frame in the preview has been updated and needs to be reflected in the animation preview
     * @param image
     */
    void previewUpdated(QImage image);
    /**
     * @brief sendPreviewFrames signal for alerting the view of what frames should be displayed within
     *  the frame preview.
     * @param imageVector imageArray is an array of the 5 QImages that need to be displayed
     */
    void sendPreviewFrames(std::vector<QImage> imageVector);
    /**
     * @brief enableOnion signal that delivers onion skin version of previous frame to be displayed on canvas
     * @param image previous frame with transparncey reduced
     */
    void enableOnion(QImage image);
    /**
     * @brief disableOnion signal that delivers a blank onion frame to be displayed under the canvas frame
     * @param image
     */
    void disableOnion(QImage image);



};

#endif // MODEL_H
