#include "model.h"

Model::~Model()
{
    animationFrames.clear(); //stub to appease compiler
}

Model::Model(QObject *parent) : QObject(parent)
{

    Frame firstFrame(16);
    animationFrames.push_back(firstFrame);
}

void Model::pixelChanged(int canvasX, int canvasY)
{
    return; // stub
}
