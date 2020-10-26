#include <iostream>
#include "png_toolkit.h"
#include "config_parsing.h"
#include "abstract_filter.h"
#include "bw_filter.h"
#include "red_filter.h"
#include "threshold_filter.h"
#include "ListFilters.h"

//AbstractFilter* ChoseFilter(std::vector<FilterData> data)
//{
//  return new bwFilter bw(data[0].boarders);
//  return &bw;
//}
int main(int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;
        ConfigParcer parcer;
        ListOfFilters lst;
        parcer.start(argv[1]);
        std::vector<FilterData> data = parcer.GetConfigData();
        
        studTool.load(argv[2]);
        image_data pixels = studTool.getPixelData();
       
        for (auto& filters : data)
        {
          lst.Find(filters.FilterName)->apply(pixels, filters.boarders);
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
