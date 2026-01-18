#include "../../headers/filters.h"

void Grayscale::DoFilter(Image &image, std::vector<char *> parameters) {
    double changed_pixel_color = 0.0;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            changed_pixel_color =
                0.299 * image.GetRgb(i, j).r + 0.587 * image.GetRgb(i, j).g + 0.114 * image.GetRgb(i, j).b;  // NOLINT
            image.ChangePixel(Rgb(changed_pixel_color, changed_pixel_color, changed_pixel_color), i, j);
        }
    }
}
