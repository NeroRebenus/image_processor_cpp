#include "../headers/rgb.h"

Rgb::Rgb() : r(0), g(0), b(0) {
}

Rgb::Rgb(double r, double g, double b) : r(r), g(g), b(b) {
}

Rgb &Rgb::operator=(const Rgb &rgb) {
    r = rgb.r;
    g = rgb.g;
    b = rgb.b;
    return *this;
}

Rgb::~Rgb() {
}
