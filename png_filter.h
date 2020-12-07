#pragma once
#include "stb_image_write.h"
#include "png_toolkit.h"
#include "config_reader.h"
#include <algorithm>
#include <cstring>


class png_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData) = 0;
	virtual ~png_filter() {};
	
};	

class Red : public png_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData);
};








