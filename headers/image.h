#pragma once

#include <vector>
#include "rgb.h"

class Image {
private:
    int width_;
    int height_;
    int x_pixels_per_m_;
    int y_pixels_per_m_;
    std::vector<std::vector<Rgb>> pixels_;

public:
    Image();

    Image(int width, int height);

    Rgb GetRgb(int x, int y) const;

    void ChangePixel(Rgb rgb, int x, int y);

    int Width() const;

    int Height() const;

    int GetXPixels() const;

    int GetYPixels() const;

    friend void SaveFile(const char *path, Image &image);

    void Read(const char *path);

    explicit Image(const char *path);
};
