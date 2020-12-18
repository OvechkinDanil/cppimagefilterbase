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

void support_filter::Monochrome(image_data& imgData, config_data& confData) {
	int redD, blueD, greenD;
	for (int i = confData.boardersOfArea[0]; i < confData.boardersOfArea[2]; i++) {
		for (int j = confData.boardersOfArea[1]; j < confData.boardersOfArea[3]; j++) {
			int pixel = (imgData.w * i + j) * imgData.compPerPixel;
			redD = imgData.pixels[pixel];
			greenD = imgData.pixels[pixel + 1];
			blueD = imgData.pixels[pixel + 2];
			int mono = (3 * redD + 6 * greenD + blueD) / 10;
			imgData.pixels[pixel] = mono;
			imgData.pixels[pixel + 1] = mono;
			imgData.pixels[pixel + 2] = mono;
		}
	}
}


int support_filter::Median(image_data& imgData, config_data& confData, std::vector<int> mBoarders) {
	std::vector<stbi_uc> elements;
	int pixel;
	for (int i = mBoarders[0]; i <= mBoarders[2]; i++) {
		if (i >= confData.boardersOfArea[0] && i < confData.boardersOfArea[2]) {
		    for (int j = mBoarders[1]; j <= mBoarders[3]; j++) {
				if (j >= confData.boardersOfArea[1] && j < confData.boardersOfArea[3]) {
					pixel = (imgData.w * i + j) * imgData.compPerPixel;
					elements.push_back(imgData.pixels[pixel]);
				}
			}
		}
	}
	std::sort(elements.begin(), elements.end());
	return elements[elements.size() / 2];
}

void Threshold::filter(image_data& imgData, config_data& confData) {
	std::vector<int> mBoarders;
	int pixel, median;
	Monochrome(imgData, confData);
	image_data saveImg;
	saveImg.compPerPixel = imgData.compPerPixel;
	saveImg.h = imgData.h;
	saveImg.w = imgData.w;
	int size = saveImg.h * saveImg.w * saveImg.compPerPixel;
	saveImg.pixels = new stbi_uc[size];
	memcpy(saveImg.pixels, imgData.pixels, size);
	for (int i = confData.boardersOfArea[0]; i < confData.boardersOfArea[2]; i++) {
		for (int j = confData.boardersOfArea[1]; j < confData.boardersOfArea[3]; j++) {
			pixel = (imgData.w * i + j) * imgData.compPerPixel;			
			mBoarders.push_back(i - size_matrix / 2);
			mBoarders.push_back(j - size_matrix / 2);
			mBoarders.push_back(i + size_matrix / 2);
			mBoarders.push_back(j + size_matrix / 2);
			median = Median(saveImg, confData, mBoarders);
			if (imgData.pixels[pixel] < median) {
				imgData.pixels[pixel] = 0;
				imgData.pixels[pixel + 1] = 0;
				imgData.pixels[pixel + 2] = 0;
			}
			mBoarders.clear();
		}
	}
	delete[] saveImg.pixels;
}

void Blur::Convolution(image_data& imgData, config_data& confData, std::vector<int> mBoarders, int* result) {
	int pixel;
	int medium = 9;
	for (int i = 0; i < 3; i++)
		result[i] = 0;
	for (int i = mBoarders[0]; i <= mBoarders[2]; i++) {
		if (i >= confData.boardersOfArea[0] && i < confData.boardersOfArea[2]) {
		    for (int j = mBoarders[1]; j <= mBoarders[3]; j++) {
				if (j >= confData.boardersOfArea[1] && j < confData.boardersOfArea[3]) {
					pixel = (imgData.w * i + j) * imgData.compPerPixel;
					result[0] += imgData.pixels[pixel];
					result[1] += imgData.pixels[pixel + 1];
					result[2] += imgData.pixels[pixel + 2];
				}
			}
		}
	}
	for (int i = 0; i < 3; i++)
		result[i] /= medium;
}

void Blur::filter(image_data& imgData, config_data& confData) {
	std::vector<int> mBoarders;
	int resultValue[3];
	int pixel;
	image_data saveImg;
	saveImg.compPerPixel = imgData.compPerPixel;
	saveImg.h = imgData.h;
	saveImg.w = imgData.w;
	int size = saveImg.h * saveImg.w * saveImg.compPerPixel;
	saveImg.pixels = new stbi_uc[size];
	memcpy(saveImg.pixels, imgData.pixels, size);
	for (int i = confData.boardersOfArea[0]; i < confData.boardersOfArea[2]; i++) {
		for (int j = confData.boardersOfArea[1]; j < confData.boardersOfArea[3]; j++) {
			pixel = (imgData.w * i + j) * imgData.compPerPixel;
			mBoarders.push_back(i - size_matrix / 2);
			mBoarders.push_back(j - size_matrix / 2);
			mBoarders.push_back(i + size_matrix / 2);
			mBoarders.push_back(j + size_matrix / 2);
			Convolution(saveImg, confData, mBoarders, resultValue);
			imgData.pixels[pixel] = resultValue[0];
			imgData.pixels[pixel + 1] = resultValue[1];
			imgData.pixels[pixel + 2] = resultValue[2];
			mBoarders.clear();
		}
	}
	delete[] saveImg.pixels;
}

int support_filter::Clump(int num) {
	if (num >= 0 && num <= 255)
		return num;
	else if (num < 0)
		return 0;
	else
		return 255;
}

int Edge::Convolution(image_data& imgData, config_data& confData, std::vector<int> mBoarders) {
	int pixel;
	int count = 0;
	int result = 0;
	for (int i = mBoarders[0]; i <= mBoarders[2]; i++) {
		if (i >= confData.boardersOfArea[0] && i < confData.boardersOfArea[2]) {
			for (int j = mBoarders[1]; j <= mBoarders[3]; j++) {
				if (j >= confData.boardersOfArea[1] && j < confData.boardersOfArea[3]) {
						pixel = (imgData.w * i + j) * imgData.compPerPixel;
						if (count == (size_matrix * size_matrix) / 2) {
							result += 9 * imgData.pixels[pixel];
						}
						else
							result -= imgData.pixels[pixel];
				}
				count++;
			}
		}
		else
		    count += size_matrix;

	}
	return Clump(result);
}

void Edge::filter(image_data& imgData, config_data& confData) {
	Monochrome(imgData, confData);
	int pixel;
	int convolut;
	std::vector<int> mBoarders;
	image_data saveImg;
	saveImg.compPerPixel = imgData.compPerPixel;
	saveImg.h = imgData.h;
	saveImg.w = imgData.w;
	int size = saveImg.h * saveImg.w * saveImg.compPerPixel;
	saveImg.pixels = new stbi_uc[size];
	memcpy(saveImg.pixels, imgData.pixels, size);
	for (int i = confData.boardersOfArea[0]; i < confData.boardersOfArea[2]; i++) {
		for (int j = confData.boardersOfArea[1]; j < confData.boardersOfArea[3]; j++) {
			pixel = (imgData.w * i + j) * imgData.compPerPixel;
			mBoarders.push_back(i - size_matrix / 2);
			mBoarders.push_back(j - size_matrix / 2);
			mBoarders.push_back(i + size_matrix / 2);
			mBoarders.push_back(j + size_matrix / 2);
			convolut = Convolution(saveImg, confData, mBoarders);
			imgData.pixels[pixel] = convolut;
			imgData.pixels[pixel + 1] = convolut;
			imgData.pixels[pixel + 2] = convolut;
			mBoarders.clear();
		}
	}
	delete[] saveImg.pixels;
}
