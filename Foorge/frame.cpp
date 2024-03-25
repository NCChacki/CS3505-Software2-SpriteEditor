#include "frame.h"

Frame::Frame() {}

Frame::Frame(int width, int height)
{
    pixels = new int[height * width * 4] {};
}

Frame::~Frame()
{
    delete pixels;
}


Frame::setPixel(int frameX, int frameY, int *rgba)
{
    int pixelArrayIndex = (pixelY * width + pixelX) * 4;

    pixels[pixelArrayIndex] = rbga[0];
    pixels[pixelArrayIndex+1] = rbga[1];
    pixels[pixelArrayIndex+2] = rbga[2];
    pixels[pixelArrayIndex+3] = rbga[3];
}
