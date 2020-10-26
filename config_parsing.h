#ifndef CONFIG_PARCING_H
#define CONFIG_PARCING_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct FilterData
{
	std::string FilterName;
	std::vector<int> boarders;
};

class ConfigParcer
{
	public:
		ConfigParcer();
		void start(std::string ConfigFileName);
		std::vector<FilterData> GetConfigData()
		{
			return ConfigData;
		}
		~ConfigParcer() {};
	private:
		std::vector<FilterData> ConfigData;
};

#endif //CONFIG_PARCING_H
