#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
    img = new RGB[1];
    max = 0;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
    set(other.getWidth(), other.getHeight());
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
    set(width, height);
}

RGBImageStudent::~RGBImageStudent() {
    delete[] img;
}

void RGBImageStudent::set(const int width, const int height) {
    delete[] img;
    img = new RGB[width * height];
    max = width * height - 1;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
    set(other.getWidth(), other.getHeight());
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
    setPixel(x + getWidth() * y, pixel);
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
    if (i > max) {
        return;
    }
    img[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
    return getPixel(x + getWidth() * y);
}

RGB RGBImageStudent::getPixel(int i) const {
    if (i > max) {
        return -1;
    }
    return img[i];
}