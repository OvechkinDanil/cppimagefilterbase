#include "png_filter.h"

void Red::filter(image_data& imgData, config_data& confData) {
	for (int i = confData.boardersOfArea[0]; i < confData.boardersOfArea[2]; i++) {
		for (int j = confData.boardersOfArea[1]; j < confData.boardersOfArea[3]; j++) {
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel] = 255;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 1] = 0;
			imgData.pixels[(imgData.w * i + j) * imgData.compPerPixel + 2] = 0;
		}
	}
}

