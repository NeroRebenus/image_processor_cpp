#include "../headers/parser.h"
#include <stdexcept>
#include <map>
#include <iostream>

std::vector<std::pair<Filter *, std::vector<char *>>> Parser(int argc, char *argv[]) {
    std::map<std::string, std::pair<Filter_Type, int>> parsing_map{
        {"-crop", std::make_pair(Filter_Crop, 2)},
        {"-gs", std::make_pair(Filter_Grayscale, 0)},
        {"-neg", std::make_pair(Filter_Negative, 0)},
        {"-sharp", std::make_pair(Filter_Sharpening, 0)},
        {"-edge", std::make_pair(Filter_Edge_Detection, 1)},
        {"-blur", std::make_pair(Filter_Gaussian_Blur, 1)},
        {"-vortex", std::make_pair(Filter_Vortex_Distortion, 1)},
        {"-waves", std::make_pair(Filter_Waves, 1)}};
    std::vector<std::pair<Filter *, std::vector<char *>>> result;
    std::vector<char *> parameters{};
    for (int i = 3; i < argc; ++i) {
        parameters.clear();
        if (parsing_map.contains(static_cast<std::string>(argv[i]))) {
            Filter_Type applied_filter = parsing_map[argv[i]].first;
            int iterations = parsing_map[static_cast<std::string>(argv[i])].second;
            if (i + iterations >= argc) {
                std::cout << "Exception: " << static_cast<std::string>(argv[i]) << " requires " << iterations
                          << " arguments.\n";
            }
            for (int j = 0; j < iterations; ++j) {
                parameters.push_back(argv[i + 1]);
                ++i;
            }
            result.push_back(std::make_pair(Filter::CreateFilter(applied_filter), parameters));
        } else {
            throw std::runtime_error(
                "Incorrect filter input.\n"
                "To use this program, use one or several of the next commands after input and output file: \n"
                " -blur, requires 1 real positive number as argument (sigma).\n"
                " -crop, requires 2 natural numbers as arguments (size of cropping).\n"
                " -edge, requires 1 real positive number as argument (threshold).\n"
                " -gs, does not require arguments.\n"
                " -neg, does not require arguments.\n"
                " -sharp, does not require arguments.\n"
                " -vortex, requires 1 real positive number as argument (distortion strength).\n"
                " -waves, requires 1 real positive number as argument (waves strength).\n");
        }
    }
    return result;
}
