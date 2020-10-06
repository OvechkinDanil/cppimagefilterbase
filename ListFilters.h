#ifndef LISTFILTERS_H
#define LISTFILTERS_H
#include <iostream>
#include <map>
#include "abstract_filter.h"
#include "bw_filter.h"
#include "red_filter.h"
#include "threshold_filter.h"


class ListOfFilters
{
private:
	std::map<std::string, AbstractFilter*> FilterMap;
public:
	ListOfFilters();
	AbstractFilter* Find(std::string filterName);
};


#endif LISTFILTERS_H