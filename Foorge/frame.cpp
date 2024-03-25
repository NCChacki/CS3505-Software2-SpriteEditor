#include "frame.h"

Frame::Frame() {}

Frame::Frame(int size) : size(size)
{
    pixels = new int[size * size * 4] {};
}

Frame::~Frame()
{
    delete pixels;
}


void Frame::setPixel(int frameX, int frameY, int *rgba)
{
    int pixelArrayIndex = (frameY * size + frameX) * 4;

    pixels[pixelArrayIndex] = rgba[0];
    pixels[pixelArrayIndex+1] = rgba[1];
    pixels[pixelArrayIndex+2] = rgba[2];
    pixels[pixelArrayIndex+3] = rgba[3];
}
