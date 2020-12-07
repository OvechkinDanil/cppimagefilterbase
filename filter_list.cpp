#include "filter_list.h"

filter_list::filter_list() {
	list_of_filters["Red"] = new Red();
	//list_of_filters["Threshold"] = new Threshold();
	//list_of_filters["Blur"] = new Blur();
	//list_of_filters["Edge"] = new Edge();
}

png_filter* filter_list::find_filter(std::string name) {
	if (list_of_filters.find(name) != list_of_filters.end())
		return list_of_filters.find(name)->second;
	else
		throw "Incorrect name of filter";
}