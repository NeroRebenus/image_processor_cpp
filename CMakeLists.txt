set (CMAKE_CXX_STANDARD 23)

add_executable(
    image_processor
    image_processor.cpp
    parser/parser.cpp
    classes/filters.cpp
    headers/filters.h
    classes/image.cpp
    classes/open_save.cpp
    classes/rgb.cpp
    headers/filters.h
    headers/parser.h
    filters/crop/crop.cpp
    filters/edge/edge.cpp
    filters/grayscale/grayscale.cpp
    filters/negative/negative.cpp
    filters/sharpening/sharpening.cpp
    filters/gaussianblur/gaussianblur.cpp
    filters/vortexdistortion/vortexdistortion.cpp
        filters/waves/waves.cpp
)
