#include "./headers/parser.h"
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        throw std::runtime_error(
            "Not enough arguments.\n"
            "This program requires at least 2 arguments:\n"
            " path of the input file; path of the output file;\n"
            "Optionally: applying filters and necessary arguments for filter:\n"
            " -blur, requires 1 real positive number as argument (sigma).\n"
            " -crop, requires 2 natural numbers as arguments (size of cropping).\n"
            " -edge, requires 1 real positive from 0 to 1 number as argument (threshold).\n"
            " -gs, does not require arguments.\n"
            " -neg, does not require arguments.\n"
            " -sharp, does not require arguments.\n"
            " -vortex, requires 1 real positive number as argument (distortion strength).\n"
            " -waves, requires 1 real positive number as argument (waves strength).\n"
            "If there is no applying filter and arguments for that, "
            "program will copy photo from the input file to output file");
    }
    Image image_in;
    char *path_in = argv[1];
    char *path_out = argv[2];
    image_in.Read(path_in);
    std::vector<std::pair<Filter *, std::vector<char *>>> apply_filters;
    apply_filters = Parser(argc, argv);
    for (std::pair<Filter *, std::vector<char *>> const &filter : apply_filters) {
        filter.first->DoFilter(image_in, filter.second);
    }
    SaveFile(path_out, image_in);
    for (const auto &element : apply_filters) {
        delete element.first;
    }
    return 0;
}
