#include "bw_filter.h"
#include "red_filter.h"
#include "threshold_filter.h"
#include "ListFilters.h"


int main(int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;
        ConfigParser parser;
        parser.start(argv[1]);
        
        studTool.load(argv[2]);
        ListOfFilters lst;
        image_data pixels = studTool.getPixelData();
        parser.changeBoarders(pixels.h, pixels.w);
        std::vector<FilterData> data = parser.GetConfigData();
        for (auto& filters : data)
        {
          lst.Find(filters.FilterName)->apply(pixels, filters);
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
