#include <iostream>
#include "png_toolkit.h"
#include "png_filter.h"
#include "config_reader.h"
#include "filter_list.h"
#include <map>


int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

    png_toolkit studTool;
		config_reader configReader;
		filter_list filterList;
		std::vector<config_data> cnfData;
		configReader.read(argv[1]);
    studTool.load(argv[2]);
		image_data imgData = studTool.getPixelData();
		configReader.toAreaBoarders(imgData.h, imgData.w);
		cnfData = configReader.getConfigData();
		for (auto& item : cnfData) {
		filterList.find_filter(item.nameOfFilter)->filter(imgData, item);
		}
        studTool.save(argv[3]);
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
