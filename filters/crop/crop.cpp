#include "../../headers/filters.h"
#include <cctype>
#include <stdexcept>

void Crop::DoFilter(Image &image, std::vector<char *> parameters) {
    for (const auto &element : parameters) {
        std::string number = static_cast<std::string>(element);
        for (const auto &check_digit : number) {
            if (!isdigit(check_digit)) {
                throw std::runtime_error(
                    "Incorrect arguments for crop.\n"
                    "Expected 2 natural numbers\n");
            }
        }
    }
    int width = std::min(std::stoi(parameters[0]), image.Width());
    int height = std::min(std::stoi(parameters[1]), image.Height());
    Image image_cut(width, height);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            image_cut.ChangePixel(image.GetRgb(i, image.Height() - height + j), i, j);
        }
    }
    image = image_cut;
};
