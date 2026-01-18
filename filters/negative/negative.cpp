#include "../../headers/filters.h"

void Negative::DoFilter(Image &image, std::vector<char *> parameters) {
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            red = 1 - image.GetRgb(i, j).r;
            green = 1 - image.GetRgb(i, j).g;
            blue = 1 - image.GetRgb(i, j).b;
            image.ChangePixel(Rgb(red, green, blue), i, j);
        }
    }
}
