#pragma once
#include "filters.h"
#include "image.h"
#include <vector>

std::vector<std::pair<Filter *, std::vector<char *>>> Parser(int argc, char *argv[]);
