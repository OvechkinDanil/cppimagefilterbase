#ifndef LISTFILTERS_H
#define LISTFILTERS_H

#include <map>
#include "red_filter.h"
#include "threshold_filter.h"
#include "edge_filter.h"
#include "blur_filter.h"


class ListOfFilters
{
private:
	std::map<std::string, AbstractFilter*> FilterMap;
public:
	ListOfFilters();
	AbstractFilter* Find(std::string filterName);
};


#endif //LISTFILTERS_H