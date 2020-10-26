#include "config_parsing.h"

ConfigParcer::ConfigParcer() {};

void ConfigParcer::start(std::string ConfigFileName)
{
    std::ifstream in(ConfigFileName);
    if (!in.is_open())
    {
        throw "Cannot open file";
    }
    else
    {
        std::string line;
        int count = 0;
        while (getline(in, line, '\n'))
        {
            FilterData filter;
            std::istringstream i(line);
            for (std::string str; i >> str;) {
                if (count == 0)
                    filter.FilterName = str;
                else
                    filter.boarders.push_back(stoi(str));
                count++;
            }
            count = 0;
            if (filter.FilterName.length() == 0 || filter.boarders.size() != 4)
                throw "Not correct config";
            this->ConfigData.push_back(filter);
        }
        in.close();
    }
}
