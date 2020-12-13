#include "edge_filter.h"

void edgeFilter::apply(image_data &imageData, FilterData &data)
{
    std::vector<int> curBoarders;
    int index, conv, size;
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

            conv = Convolution(imageData, data, curBoarders);
            imageData.pixels[index] = conv;
            imageData.pixels[index + 1] = conv;
            imageData.pixels[index + 2] = conv;

            curBoarders.clear();
        }
    }
    delete [] curImage.pixels;
}

int edgeFilter::Convolution(image_data &imageData, FilterData &data, std::vector<int> boarders)
{
    int index, counter = 0, res = 0, x, y;

    for (y = boarders[0]; y <= boarders[2]; y++)
    {
        if (y >= data.boarders[0] && y < data.boarders[2])
        {
            for (x = boarders[1]; x <= boarders[3]; x++)
            {
                if (x >= data.boarders[1] && x < data.boarders[3])
                {
                    index = (imageData.w * y + x) * imageData.compPerPixel;
                    if (counter == (delta * delta / 2))
                        res += 9 * imageData.pixels[index];
                    else
                        res -= imageData.pixels[index];
                }
                counter++;
            }
        }
        else
            counter += delta;
    }

    if (res >= 0 && res <= 0)
        return res;
    else if (res < 0)
        return 0;
    else
        return 255;
}

