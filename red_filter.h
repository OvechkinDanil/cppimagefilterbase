#include "abstract_filter.h"

#ifndef RED_FILTER_H
#define RED_FILTER_H


class redFilter : public AbstractFilter
{
public:
	redFilter()
	{

	}
	~redFilter() {};
	virtual void apply(image_data& imageData, std::vector<int>& boarders) override;
};


#endif //RED_FILTER_H

