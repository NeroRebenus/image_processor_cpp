#include "../../headers/filters.h"

void Sharpening::DoFilter(Image &image, std::vector<char *> parameters) {
    Image image_copy = Image(image.Width(), image.Height());
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            int matrix_width_lowest = std::max(0, i - 1);
            int matrix_height_lowest = std::max(0, j - 1);
            int matrix_width_highest = std::min(image.Width() - 1, i + 1);
            int matrix_height_highest = std::min(image.Height() - 1, j + 1);
            red = std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).r -
                                                  1 * image.GetRgb(i, matrix_height_lowest).r +   // NOLINT
                                                  5 * image.GetRgb(i, j).r -                      // NOLINT
                                                  1 * image.GetRgb(i, matrix_height_highest).r -  // NOLINT
                                                  1 * image.GetRgb(matrix_width_highest, j).r));  // NOLINT
            blue = std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).b -
                                                   1 * image.GetRgb(i, matrix_height_lowest).b +   // NOLINT
                                                   5 * image.GetRgb(i, j).b -                      // NOLINT
                                                   1 * image.GetRgb(i, matrix_height_highest).b -  // NOLINT
                                                   1 * image.GetRgb(matrix_width_highest, j).b));  // NOLINT
            green = std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).g -
                                                    1 * image.GetRgb(i, matrix_height_lowest).g +   // NOLINT
                                                    5 * image.GetRgb(i, j).g -                      // NOLINT
                                                    1 * image.GetRgb(i, matrix_height_highest).g -  // NOLINT
                                                    1 * image.GetRgb(matrix_width_highest, j).g));  // NOLINT
            image_copy.ChangePixel(Rgb(red, green, blue), i, j);
        }
    }
    image = image_copy;
}
