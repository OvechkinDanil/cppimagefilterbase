#include "config_reader.h"

config_reader::config_reader() {}

void config_reader::read(std::string config_filename) {
	std::ifstream in(config_filename); 
	int counter = 0;
	if (!in.is_open())
		throw "Cannot open file.";
	else {
		std::string line;
		while (getline(in, line)) {
			config_data support_struct;
			std::istringstream i(line);
			for (std::string str; i >> str;) {
				if (counter == 0)
					support_struct.nameOfFilter = str;
				else
					support_struct.boardersOfArea.push_back(stoi(str));
				counter++;
			}
			if (!(support_struct.nameOfFilter.length() != 0 && support_struct.boardersOfArea.size() == 4))
				throw "Incorrect format of config.";
			this->confData.push_back(support_struct);
			counter = 0;
		}		
	}
	in.close();
}

void config_reader::toAreaBoarders(int height, int width) {
	for (int j = 0; j < confData.size(); j++) {
		for (int i = 0; i < this->confData[j].boardersOfArea.size(); i++) {
			if (this->confData[j].boardersOfArea[i] != 0) {
				int rem = this->confData[j].boardersOfArea[i];
				if (i == 0 || i == 2)
					this->confData[j].boardersOfArea[i] = height / rem;
				if (i == 1 || i == 3)
					this->confData[j].boardersOfArea[i] = width / rem;
			}

		}
	}
}

std::vector<config_data> config_reader::getConfigData() {
	return confData;
}

config_reader::~config_reader() {}