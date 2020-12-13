#include "blur_filter.h"

void blurFilter::Convolution(image_data &imageData, FilterData &data, std::vector<int> boarders, int* resRGB)
{
    int index;
    int size = 9;
    int x, y;

    for (x = 0; x < 3; x++)
        resRGB[x] = 0;

    for (y = boarders[0]; y <= boarders[2]; y++)
    {
        if (y >= data.boarders[0] && y < data.boarders[2])
        {
            for (x = boarders[1]; x <= boarders[3]; x++)
            {
                if (x >= data.boarders[1] && x < data.boarders[3])
                {
                    index = (imageData.w * y + x) * imageData.compPerPixel;
                    resRGB[0] += imageData.pixels[index];
                    resRGB[1] += imageData.pixels[index + 1];
                    resRGB[2] += imageData.pixels[index + 2];
                }
            }
        }
    }

    for (x = 0; x < 3; x++)
        resRGB[x] /= size;
}

void blurFilter::apply(image_data &imageData, FilterData &data)
{
    std::vector<int> curBoarders;
    int index, conv, size, resRGB[3];
    image_data curImage;

    curImage.compPerPixel = imageData.compPerPixel;
    curImage.h = imageData.h;
    curImage.w = imageData.w;
    size = curImage.h * curImage.w * curImage.compPerPixel;
    curImage.pixels = new stbi_uc[size];
    //memcpy(curImage.pixels, imageData.pixels, size);

    for (int y = data.boarders[0]; y < data.boarders[2]; y++)
    {
        for (int x = data.boarders[1]; x < data.boarders[3]; x++)
        {
            index = (imageData.w * y + x) * imageData.compPerPixel;

            curBoarders.push_back(y - delta / 2);
            curBoarders.push_back(x - delta / 2);
            curBoarders.push_back(y + delta / 2);
            curBoarders.push_back(x + delta / 2);

            Convolution(imageData, data, curBoarders, resRGB);
            imageData.pixels[index] = resRGB[0];
            imageData.pixels[index + 1] = resRGB[1];
            imageData.pixels[index + 2] = resRGB[2];

            curBoarders.clear();
        }
    }
    delete [] curImage.pixels;
}
