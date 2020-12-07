#include "abstract_filter.h"

#ifndef RED_FILTER_H
#define RED_FILTER_H


class redFilter : public AbstractFilter
{
public:
    virtual void apply(image_data& imageData, FilterData& data);
};


#endif //RED_FILTER_H

