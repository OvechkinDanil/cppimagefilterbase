#include "red_filter.h"

void redFilter::apply(image_data& imageData, std::vector<int>& boarders)
{
	int u = boarders[0];
	int l = boarders[1];
	int b = boarders[2];
	int r = boarders[3];

	int left = l == 0 ? 0 : imageData.w / l;
	int right = r == 0 ? 0 : imageData.w / r;
	int upper = u == 0 ? 0 : imageData.h / u;
	int bottom = b == 0 ? 0 : imageData.h / b;
	for (auto y = upper; y < bottom; y++)
	{
		for (auto x = left; x < right; x++)
		{
			int pixel = (imageData.w * y + x) * imageData.compPerPixel;
			imageData.pixels[pixel] = 255;
			imageData.pixels[pixel + 1] = 0;
			imageData.pixels[pixel + 2] = 0;
		}
	}
}