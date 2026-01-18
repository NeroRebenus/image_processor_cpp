#pragma once

struct Rgb {
    double r = 0.0;
    double g = 0.0;
    double b = 0.0;

    ~Rgb();

    Rgb();

    Rgb(double r, double g, double b);

    Rgb &operator=(const Rgb &rgb);
};
