#include "StudentPreProcessing.h"
#include "ImageFactory.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
    IntensityImage * img = ImageFactory::newIntensityImage();
    img->set(image.getWidth(), image.getHeight());
    int max = image.getWidth() * image.getHeight();
    for (int i = 0; i < max; i++) {
        img->setPixel(i, (image.getPixel(i).r + image.getPixel(i).g + image.getPixel(i).b)/3);
    }
    return img;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}