#ifndef IMAGEFILTERS_EDGE_FILTER_H
#define IMAGEFILTERS_EDGE_FILTER_H

#include "support_filters.h"
#include "abstract_filter.h"

class edgeFilter : public AbstractFilter, support_filters
{
private:
    int delta = 3;
public:
    edgeFilter() {}
    int Convolution(image_data& imageData, FilterData &data, std::vector<int> boarders);
    virtual void apply(image_data& imageData, FilterData &data);
};

#endif //IMAGEFILTERS_EDGE_FILTER_H
