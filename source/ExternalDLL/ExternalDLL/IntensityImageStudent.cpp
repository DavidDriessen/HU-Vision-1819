#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
    img = new int[1];
    max = 0;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
    set(other.getWidth(), other.getHeight());
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
    set(width, height);
}

IntensityImageStudent::~IntensityImageStudent() {
    delete[] img;
}

void IntensityImageStudent::set(const int width, const int height) {
    IntensityImage::set(width, height);
    delete[] img;
    img = new int[width * height];
    max = width * height - 1;
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
    set(other.getWidth(), other.getHeight());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
    setPixel(x + getWidth() * y, pixel);
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
    if (i > max) {
        return;
    }
    img[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
    return getPixel(x + getWidth() * y);
}

Intensity IntensityImageStudent::getPixel(int i) const {
    if (i > max) {
        return -1;
    }
    return img[i];
}