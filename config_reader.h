#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>


struct config_data {
	std::string nameOfFilter;
	std::vector<int> boardersOfArea;
};

class config_reader {
public:
	config_reader();
	void read(std::string config_filename);
	void toAreaBoarders(int height, int width);
	std::vector<config_data> getConfigData();
	~config_reader();
private:
	std::vector<config_data> confData;
};

#endif //CONFIG_READER_H
