#include "../headers/filters.h"

Filter *Filter::CreateFilter(Filter_Type type) {
    Filter *returning_filter{};
    switch (type) {
        case Filter_Crop:
            returning_filter = new Crop();
            break;
        case Filter_Grayscale:
            returning_filter = new Grayscale();
            break;
        case Filter_Negative:
            returning_filter = new Negative();
            break;
        case Filter_Sharpening:
            returning_filter = new Sharpening();
            break;
        case Filter_Edge_Detection:
            returning_filter = new EdgeDetection();
            break;
        case Filter_Gaussian_Blur:
            returning_filter = new GaussBlur();
            break;
        case Filter_Vortex_Distortion:
            returning_filter = new VortexDistortion();
            break;
        case Filter_Waves:
            returning_filter = new Waves();
            break;
    }
    return returning_filter;
}
