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

class support_filter {
public:
	void Monochrome(image_data& imgData, config_data& confData);
	int Median(image_data& imgData, config_data& confData, std::vector<int> mBoarders);
	int Clump(int num);
};
	

class Red : public png_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData);
};

class Threshold : public png_filter, support_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData);
private:
	int size_matrix = 5;
};

class Edge : public png_filter, support_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData);
private:
	int size_matrix = 3;
	int Convolution(image_data& imgData, config_data& confData, std::vector<int> mBoarders);
};

class Blur : public png_filter, support_filter {
public:
	virtual void filter(image_data& imgData, config_data& confData);
private:
	int size_matrix = 3;
	void Convolution(image_data& imgData, config_data& confData, std::vector<int> mBoarders, int* result);
};






