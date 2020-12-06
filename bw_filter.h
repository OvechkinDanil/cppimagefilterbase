#include "abstract_filter.h"

#ifndef BW_FILTER_H
#define BW_FILTER_H


class bwFilter : public AbstractFilter
{
	public:
		bwFilter()=default;
		~bwFilter() override = default;
		void apply(image_data& imageData, std::vector<int>& boarders) override;
};


#endif //BW_FILTER_H
