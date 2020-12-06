#ifndef ABSTRACT_FILTER_H
#define ABSTRACT_FILTER_H
#include <vector>
#include <iostream>
#include "png_toolkit.h"
class AbstractFilter
{
	public:
		AbstractFilter() = default;
		virtual void apply(image_data& imageData, std::vector<int>& boarders) = 0;
		virtual ~AbstractFilter() = default;
};


#endif //ABSTRACT_FILTER_H
