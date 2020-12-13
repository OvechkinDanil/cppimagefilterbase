cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" "ListFilters.cpp" "ListFilters.h" 
    "abstract_filter.h" "config_parsing.h" "config_parsing.cpp" "red_filter.cpp" 
    "red_filter.h" "threshold_filter.cpp"
        "threshold_filter.h" "support_filters.cpp" "support_filters.h"
        "edge_filter.cpp" "edge_filter.h" "blur_filter.cpp" "blur_filter.h")
