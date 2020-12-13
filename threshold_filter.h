#ifndef THRESHOLD_FILTER_H
#define THRESHOLD_FILTER_H
#include "abstract_filter.h"
#include <algorithm>
#include "png_toolkit.h"
#include "support_filters.h"
#include "bw_filter.h"

class thresholdFilter : public AbstractFilter, support_filters
{
private:
	int delta = 5;
public:
	thresholdFilter() {}
	virtual void apply(image_data& imageData, FilterData &data);
};


#endif //THRESHOLD_FILTER_H
