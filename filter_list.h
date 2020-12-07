#pragma once
#include "png_filter.h"
#include <iostream>
#include <map>


class filter_list {
private:
	std::map<std::string, png_filter*> list_of_filters;
public:
	filter_list();
	png_filter* find_filter(std::string name);
};