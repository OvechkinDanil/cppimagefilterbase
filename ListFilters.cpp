#include "ListFilters.h"

ListOfFilters::ListOfFilters()
{
	FilterMap["Red"] = new redFilter();
}

AbstractFilter* ListOfFilters::Find(std::string filterName)
{
	
	if (FilterMap.find(filterName) != FilterMap.end())
		return FilterMap.find(filterName)->second;
	else
		throw "Filter not found!";
}

ListOfFilters::~ListOfFilters()
{
    delete FilterMap["Red"];
}