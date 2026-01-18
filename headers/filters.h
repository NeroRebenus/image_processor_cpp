#pragma once

#include "open_save.h"
#include "rgb.h"
#include <string>
#include <vector>

enum Filter_Type {
    Filter_Crop,
    Filter_Grayscale,
    Filter_Negative,
    Filter_Sharpening,
    Filter_Edge_Detection,
    Filter_Gaussian_Blur,
    Filter_Vortex_Distortion,
    Filter_Waves
};

class Filter {
public:
    virtual void DoFilter(Image &image, std::vector<char *> parameters) = 0;

    virtual ~Filter() = default;

    static Filter *CreateFilter(Filter_Type type);
};

class Crop : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~Crop() override = default;
};

class Grayscale : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~Grayscale() override = default;
};

class Negative : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~Negative() override = default;
};

class Sharpening : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~Sharpening() override = default;
};

class EdgeDetection : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~EdgeDetection() override = default;
};

class GaussBlur : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~GaussBlur() override = default;
};

class VortexDistortion : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~VortexDistortion() override = default;
};

class Waves : public Filter {
public:
    void DoFilter(Image &image, std::vector<char *> parameters) override;

    ~Waves() override = default;
};
