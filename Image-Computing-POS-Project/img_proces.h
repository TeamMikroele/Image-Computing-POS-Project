#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <vector>

using namespace cv;
using namespace std;

extern vector<Mat> Image;

void img_read();
void img_write();
Mat edge_detecting(Mat);