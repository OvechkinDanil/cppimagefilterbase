#include "ListFilters.h"

ListOfFilters::ListOfFilters()
{
	FilterMap["Red"] = new redFilter();
	FilterMap["Threshold"] = new thresholdFilter();
	FilterMap["Edge"] = new edgeFilter();
	FilterMap["Blur"] = new blurFilter();
}

AbstractFilter* ListOfFilters::Find(std::string filterName)
{
	
	if (FilterMap.find(filterName) != FilterMap.end())
		return FilterMap.find(filterName)->second;
	else
		throw "Filter not found!";
}
