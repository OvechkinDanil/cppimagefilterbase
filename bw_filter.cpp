//#include "bw_filter.h"
//
//void bwFilter::apply(image_data& imageData, std::vector<int>& boarders)
//{
//	int left = boarders[1] == 0 ? 0 : imageData.w / boarders[1];
//	int right = boarders[3] == 0 ? 0 : imageData.w / boarders[3];
//	int upper = boarders[0] == 0 ? 0 : imageData.h / boarders[0];
//	int bottom = boarders[2] == 0 ? 0 : imageData.h / boarders[2];
//
//	int red, blue, green;
//	for (auto y = upper; y < bottom; y++)
//	{
//		for (auto x = left; x < right; x++)
//		{
//			int pixel = (imageData.w * y + x) * imageData.compPerPixel;
//			red = imageData.pixels[pixel];
//			green = imageData.pixels[pixel + 1];
//			blue = imageData.pixels[pixel + 2];
//			int mono = (3 * red + 6 * green + blue) / 10;
//			imageData.pixels[pixel] = mono;
//			imageData.pixels[pixel + 1] = mono;
//			imageData.pixels[pixel + 2] = mono;
// 		}
//	}
//}
