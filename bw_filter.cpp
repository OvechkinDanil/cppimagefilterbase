#include "bw_filter.h"

void bwFilter::apply(image_data& imageData, std::vector<int> boarders)
{
	int u = boarders[0];
	int l = boarders[1];
	int b = boarders[2];
	int r = boarders[3];

	int left = l == 0 ? 0 : imageData.w / l;
	int right = r == 0 ? 0 : imageData.w / r;
	int upper = u == 0 ? 0 : imageData.h / u;
	int bottom = b == 0 ? 0 : imageData.h / b;
	int red, blue, green;
	uint8_t value;
	for (auto y = upper; y < bottom; y++)
	{
		for (auto x = left; x < right; x++)
		{
			int pixel = (imageData.w * y + x) * imageData.compPerPixel;
			red = imageData.pixels[pixel];
			green = imageData.pixels[pixel + 1];
			blue = imageData.pixels[pixel + 2];
			int mono = (3* red + 6 * green + blue) / 10;
			imageData.pixels[pixel] = mono;
			imageData.pixels[pixel + 1] = mono;
			imageData.pixels[pixel + 2] = mono;
 		}
	}
}