#include "threshold_filter.h"
#include "bw_filter.h"


bool thresholdFilter::isActivePixel(int x, int y, int width, int height)
{
	return (x > 0 && x < width && y > 0 && y < height);
}

int thresholdFilter::GetMedian(image_data& imageData, int x_c, int y_c, int width, int height)
{
	std::vector<stbi_uc> buf;
	int pixel = -1;
	for (auto y = y_c - delta; y <= y_c + delta; y++)
		for (auto x = x_c - delta; x <= x_c + delta; x++)
		{
			if (isActivePixel(x, y, width, height))
			{
				pixel = (imageData.w * y + x) * imageData.compPerPixel;
				buf.push_back(imageData.pixels[pixel]);
			}
		}
	std::sort(buf.begin(), buf.end());
	return buf[buf.size() / 2];
}

void thresholdFilter::apply(image_data& imageData, std::vector<int>& boarders)
{
	int u = boarders[0];
	int l = boarders[1];
	int b = boarders[2];
	int r = boarders[3];

	int left = l == 0 ? 0 : imageData.w / l;
	int right = r == 0 ? 0 : imageData.w / r;
	int upper = u == 0 ? 0 : imageData.h / u;
	int bottom = b == 0 ? 0 : imageData.h / b;
	int pixel = -1;
	int red, blue, green, intensity;
	bwFilter* bw = new bwFilter();
	bw->apply(imageData, boarders);
	image_data copiedPictureData = imageData.Copy();
	for (auto y = upper; y < bottom; y++)
	{
		for (auto x = left; x < right; x++)
		{
			pixel = (imageData.w * y + x) * imageData.compPerPixel;
			if (imageData.pixels[pixel] < GetMedian(copiedPictureData, x, y, imageData.w, imageData.h))
			{
				imageData.pixels[pixel] = 0;
				imageData.pixels[pixel + 1] = 0;
				imageData.pixels[pixel + 2] = 0;
			}
		}
	}
}