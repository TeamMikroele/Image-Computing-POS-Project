#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <iostream>
#include "ini_parser.h"

using namespace std;
using namespace cv;

vector<Mat> Image;
vector<String> filenames;

void read_input_folder_info() {

	strcat_s(dir_img.input, "*.png");
	glob(dir_img.input, filenames);
	Image.resize(filenames.size());

	if (!filenames.size())
		cout << "error: there is no .png file in " << dir_img.input << endl;
}

void img_read(int img_index) {

	Image[img_index] = imread(filenames[img_index]);
}

void img_write(int img_index) {

	string fileName = dir_img.output + to_string(img_index) + ".png";
	imwrite(fileName, Image[img_index]);
}

void edge_detecting(int img_index) {

	Mat tmp;
	cvtColor(Image[img_index], tmp, COLOR_BGR2GRAY, 0);
	Laplacian(tmp, Image[img_index], CV_16S, 5, 1, 0, 4);
}