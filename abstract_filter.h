#ifndef ABSTRACT_FILTER_H
#define ABSTRACT_FILTER_H

#include "png_toolkit.h"
#include "config_parsing.h"

class AbstractFilter
{
	public:
		virtual void apply(image_data& imageData, FilterData& data ) = 0;
		virtual ~AbstractFilter() {};
};


#endif //ABSTRACT_FILTER_H
