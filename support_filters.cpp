#include "support_filters.h"

void support_filters::BlackAndWhite(image_data &imageData, FilterData &data)
{
    int r, g, b, i, j, index, intensity;

    for (i = data.boarders[0]; i < data.boarders[2]; i++)
        for (j = data.boarders[1]; j < data.boarders[3]; j++)
        {
            index = (imageData.w * i + j) * imageData.compPerPixel;
            r = imageData.pixels[index];
            g = imageData.pixels[index + 1];
            b = imageData.pixels[index + 2];

            intensity = (3 * r + 6 * g + b) / 10;

            imageData.pixels[index] = intensity;
            imageData.pixels[index + 1] = intensity;
            imageData.pixels[index + 2] = intensity;
        }
}

int support_filters::Median(image_data &imageData, FilterData &data, std::vector<int> boarders)
{
    std::vector<stbi_uc> elem;
    int i, j, index;

    for(i = boarders[0]; i < boarders[2]; i++)
    {
        if (i >= data.boarders[0] && i < data.boarders[2])
        {
            for (j = boarders[1]; j < boarders[3]; j++)
            {
                if (j >= data.boarders[1] && j < data.boarders[3])
                {
                    index = (imageData.w * i + j) * imageData.compPerPixel;
                    elem.push_back(imageData.pixels[index]);
                }
            }

        }
    }

    std::sort(elem.begin(), elem.end());

    return elem[elem.size() / 2];
}
