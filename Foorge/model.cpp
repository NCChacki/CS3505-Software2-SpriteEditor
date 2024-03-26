#include "model.h"

//Model::Model() {}

// Model::Model(int frameSize) : frameSize(frameSize)
// {
//     // create an empty frame of the proper size and add it to the vector
//     Frame firstFrame(frameSize);
//     animationFrames.push_back(firstFrame);

// }

Model::Model(QObject *parent) : QObject(parent)
{


}

Model::~Model()
{

}

void Model::pixelChanged(int canvasX, int canvasY)
{
    return; // stub
}
