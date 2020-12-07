#include "red_filter.h"

void redFilter::apply(image_data& imageData, FilterData& data)
{
	for (auto y = data.boarders[0]; y < data.boarders[2]; y++)
	{
		for (auto x = data.boarders[1]; x < data.boarders[3]; x++)
		{
			int pixel = (imageData.w * y + x) * imageData.compPerPixel;
			imageData.pixels[pixel] = 255;
			imageData.pixels[pixel + 1] = 0;
			imageData.pixels[pixel + 2] = 0;
		}
	}
}