#ifndef IMAGEFILTERS_BLUR_FILTER_H
#define IMAGEFILTERS_BLUR_FILTER_H

#include "support_filters.h"
#include "abstract_filter.h"

class blurFilter : public AbstractFilter, support_filters
{
private:
    int delta = 3;
public:
    blurFilter() {}
    void Convolution(image_data &imageData, FilterData &data, std::vector<int> boarders, int* resRGB);
    virtual void apply(image_data& imageData, FilterData &data);
};
#endif //IMAGEFILTERS_BLUR_FILTER_H
