#include "abstract_filter.h"
#include <algorithm>
#include "png_toolkit.h"
#ifndef THRESHOLD_FILTER_H
#define THRESHOLD_FILTER_H


class thresholdFilter : public AbstractFilter
{
private:
	int delta;
	bool isActivePixel(int x, int y, int width, int height);
	int GetMedian(image_data& imageData, int x_c, int y_c, int width, int height);
public:
	thresholdFilter() { delta = 2; }
	~thresholdFilter() {};
	virtual void apply(image_data& imageData, std::vector<int>& boarders) override;
};


#endif //THRESHOLD_FILTER_H

