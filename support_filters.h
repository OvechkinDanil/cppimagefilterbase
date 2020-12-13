#ifndef IMAGEFILTERS_SUPPORT_FILTERS_H
#define IMAGEFILTERS_SUPPORT_FILTERS_H

#include "png_toolkit.h"
#include "config_parsing.h"
#include <algorithm>

class support_filters
{
public:
    void BlackAndWhite(image_data& imageData, FilterData& data);
    int Median(image_data& imageData, FilterData& data, std::vector<int> boarders);

};

#endif //IMAGEFILTERS_SUPPORT_FILTERS_H
