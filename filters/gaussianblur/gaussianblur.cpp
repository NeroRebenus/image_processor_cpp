#include "../../headers/filters.h"
#include <cctype>
#include <cmath>
#include <stdexcept>
#include <vector>

void GaussBlur::DoFilter(Image &image, std::vector<char *> parameters) {
    std::string number = static_cast<std::string>(parameters[0]);
    for (const auto &check_digit : number) {
        if (!isdigit(check_digit)) {
            if (check_digit != '.' || check_digit == number[0]) {
                throw std::runtime_error(
                    "Incorrect arguments for Gaussian Blur.\n"
                    "Expected 1 real positive number\n");
            }
        }
    }
    double sigma = std::stof(parameters[0]);
    Image image_copy = Image(image.Width(), image.Height());
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;
    double coef = 0.0;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            for (int k = static_cast<int>(std::round(-3.0 * sigma));  // NOLINT
                 k < static_cast<int>(std::round(3.0 * sigma)) + 1;   // NOLINT
                 ++k) {
                coef = 1.0 / (std::sqrt(2.0 * M_PI * sigma * sigma)) *  // NOLINT
                       std::exp(-static_cast<double>(k * k) / (2 * sigma * sigma));
                red += coef * image.GetRgb(std::min(std::max(i + k, 0), image.Width() - 1), j).r;
                green += coef * image.GetRgb(std::min(std::max(i + k, 0), image.Width() - 1), j).g;
                blue += coef * image.GetRgb(std::min(std::max(i + k, 0), image.Width() - 1), j).b;
            }
            image_copy.ChangePixel(Rgb(red, green, blue), i, j);
        }
    }
    image = image_copy;
    image_copy = Image(image.Width(), image.Height());
    for (int i = 0; i < image.Height(); ++i) {
        for (int j = 0; j < image.Width(); ++j) {
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            for (int k = static_cast<int>(std::round(-3.0 * sigma));  // NOLINT
                 k < static_cast<int>(std::round(3.0 * sigma)) + 1;   // NOLINT
                 ++k) {
                coef = 1.0 / (std::sqrt(2.0 * M_PI * sigma * sigma)) *  // NOLINT
                       std::exp(-static_cast<double>(k * k) / (2 * sigma * sigma));
                red += coef * image.GetRgb(j, std::min(std::max(i + k, 0), image.Width() - 1)).r;
                green += coef * image.GetRgb(j, std::min(std::max(i + k, 0), image.Width() - 1)).g;
                blue += coef * image.GetRgb(j, std::min(std::max(i + k, 0), image.Width() - 1)).b;
            }
            image_copy.ChangePixel(Rgb(red, green, blue), j, i);
        }
    }
    image = image_copy;
}
