#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <vector>

#define MATRIX_PROCESSED_IMAGES 2
#define MATRIX_INPUT_IMAGES 1
#define PROCESSED_IMAGE 0

using namespace cv;
using namespace std;

extern vector<Mat> Image;
extern vector<Mat> ImageColor;

void read_input_folder_info();
void img_read(int);
void img_write(int);
void edge_detecting(int);
void thumbnails_matrix(string, vector<Mat>);