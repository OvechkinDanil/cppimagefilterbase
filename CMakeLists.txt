cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "main.cpp" "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" "ListFilters.cpp" "ListFilters.h" 
    "abstract_filter.h" "bw_filter.cpp" "bw_filter.h" "config_parsing.h"
    "config_parsing.cpp")

