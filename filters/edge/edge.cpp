#include "../../headers/filters.h"
#include <cctype>
#include <stdexcept>

void EdgeDetection::DoFilter(Image &image, std::vector<char *> parameters) {
    std::string number = static_cast<std::string>(parameters[0]);
    for (const auto &check_digit : number) {
        if (!isdigit(check_digit)) {
            if (check_digit != '.' || check_digit == number[0]) {
                throw std::runtime_error(
                    "Incorrect arguments for Edge Detection.\n"
                    "Expected real number from 0 to 1\n");
            }
        }
    }
    double changed_pixel_color = 0.0;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            changed_pixel_color =
                0.299 * image.GetRgb(i, j).r + 0.587 * image.GetRgb(i, j).g + 0.114 * image.GetRgb(i, j).b;  // NOLINT
            image.ChangePixel(Rgb(changed_pixel_color, changed_pixel_color, changed_pixel_color), i, j);
        }
    }
    double threshold = std::stof(static_cast<std::string>(parameters[0]));
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
            red =
                std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).r -
                                                1 * image.GetRgb(i, matrix_height_lowest).r + 4 * image.GetRgb(i, j).r -
                                                1 * image.GetRgb(i, matrix_height_highest).r -
                                                1 * image.GetRgb(matrix_width_highest, j).r));  // NOLINT
            blue =
                std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).b -
                                                1 * image.GetRgb(i, matrix_height_lowest).b + 4 * image.GetRgb(i, j).b -
                                                1 * image.GetRgb(i, matrix_height_highest).b -
                                                1 * image.GetRgb(matrix_width_highest, j).b));  // NOLINT
            green =
                std::min(1.0, std::max(0.0, -1 * image.GetRgb(matrix_width_lowest, j).g -
                                                1 * image.GetRgb(i, matrix_height_lowest).g + 4 * image.GetRgb(i, j).g -
                                                1 * image.GetRgb(i, matrix_height_highest).g -
                                                1 * image.GetRgb(matrix_width_highest, j).g));  // NOLINT
            if (red > threshold && blue > threshold && green > threshold) {
                image_copy.ChangePixel(Rgb(1, 1, 1), i, j);
            } else {
                image_copy.ChangePixel(Rgb(0, 0, 0), i, j);
            }
        }
    }
    image = image_copy;
}
