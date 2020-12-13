#include "threshold_filter.h"


void thresholdFilter::apply(image_data& imageData, FilterData &data)
{
	std::vector<int> curBoarders;
	int index, median, size;
	image_data curImage;

	BlackAndWhite(imageData, data);

    curImage.compPerPixel = imageData.compPerPixel;
    curImage.h = imageData.h;
    curImage.w = imageData.w;
    size = curImage.h * curImage.w * curImage.compPerPixel;
    curImage.pixels = new stbi_uc[size];
    memcpy(curImage.pixels, imageData.pixels, size);

    for (int y = data.boarders[0]; y < data.boarders[2]; y++)
    {
        for (int x = data.boarders[1]; x < data.boarders[3]; x++)
        {
			index = (imageData.w * y + x) * imageData.compPerPixel;

			curBoarders.push_back(y - delta / 2);
			curBoarders.push_back(x - delta / 2);
			curBoarders.push_back(y + delta / 2);
			curBoarders.push_back(x + delta / 2);

			median = Median(curImage, data, curBoarders);
			if (imageData.pixels[index] < median)
            {
			    imageData.pixels[index] = 0;
			    imageData.pixels[index + 1] = 0;
			    imageData.pixels[index + 2] = 0;
            }
			curBoarders.clear();
		}
	}
    delete [] curImage.pixels;
}