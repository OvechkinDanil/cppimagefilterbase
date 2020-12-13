#include "config_parsing.h"

void ConfigParser::start(std::string ConfigFileName)
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
        while (getline(in, line))
        {
            if (line.length() == 0)
                continue;
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

void ConfigParser::changeBoarders(int h, int w)
{
    int tmp;
    for (int j = 0; j < ConfigData.size(); j++)
    {
        for (int i = 0; i < this->ConfigData[j].boarders.size(); i++)
        {
            if (this->ConfigData[j].boarders[i] != 0)
            {
                tmp = this->ConfigData[j].boarders[i];
                if (i == 0 || i == 2)
                    this->ConfigData[j].boarders[i] = h / tmp;
                else if (i == 1 || i == 3)
                    this->ConfigData[j].boarders[i] = w / tmp;
            }

        }
    }
}