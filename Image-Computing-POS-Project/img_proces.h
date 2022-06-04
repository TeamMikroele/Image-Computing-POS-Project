#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <vector>

using namespace cv;
using namespace std;

extern vector<Mat> Image;

void read_input_folder_info();
void img_read(int);
void img_write(int);
void edge_detecting(int);