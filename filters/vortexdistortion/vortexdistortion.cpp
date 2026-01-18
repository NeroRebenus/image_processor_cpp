#include "../../headers/filters.h"
#include <cctype>
#include <cmath>
#include <stdexcept>

// best if argument is at least 30
void VortexDistortion::DoFilter(Image &image, std::vector<char *> parameters) {
    std::string number = static_cast<std::string>(parameters[0]);
    for (const auto &check_digit : number) {
        if (!isdigit(check_digit)) {
            if (check_digit != '.' || check_digit == number[0]) {
                throw std::runtime_error(
                    "Incorrect arguments for Vortex Distortion.\n"
                    "Expected 2 real positive numbers\n");
            }
        }
    }
    double distortion_coefficient = std::stof(parameters[0]);
    Image image_copy = Image(image.Width(), image.Height());
    double distance_to_center = 0.0;
    double angle = 0.0;
    const int central_dot_width = image.Width() / 2;
    const int central_dot_height = image.Height() / 2;
    for (int i = 0; i < image.Width(); ++i) {
        for (int j = 0; j < image.Height(); ++j) {
            distance_to_center = std::sqrt((i - central_dot_width) * (i - central_dot_width) +
                                           (j - central_dot_height) * (j - central_dot_height));
            angle = distortion_coefficient / distance_to_center +
                    std::atan2((i - central_dot_width), (j - central_dot_height));
            int width_coord = static_cast<int>(central_dot_width + distance_to_center * std::sin(angle));
            int height_coord = static_cast<int>(central_dot_height + distance_to_center * std::cos(angle));
            image_copy.ChangePixel(image.GetRgb((std::max(0, std::min((image.Width() - 1), width_coord))),
                                                (std::max(0, std::min(image.Height() - 1, height_coord)))),
                                   i, j);
        }
    }
    image = image_copy;
}