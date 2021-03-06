#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <iostream>
#include "string"
#include "ini_parser.h"

/**
 * variable which defines size of cropped images
 */
const int ROWS = 125;
/**
 * variable which defines size of cropped images
 */
const int COLS = 125;

using namespace std;
using namespace cv;

/**
 * vector of images to process
 */
vector<Mat> Image;
/**
 * vector of loaded coloured images
 */
vector<Mat> ImageColor;
/**
 * vector of loaded images names
 */
vector<String> filenames;

void read_input_folder_info() {
/**
 * function to read info of images to process, gives statement if input folder is empty
 */
	strcat_s(dir_img.input, "*.png");
	glob(dir_img.input, filenames);
	Image.resize(filenames.size());
	ImageColor.resize(filenames.size());

	if (!filenames.size())
		cout << "error: there is no .png file in " << dir_img.input << endl;
}

void img_read(int img_index) {
/**
* reads one image from source folder, saves output image to global variable
* @param img_index is an index of processed image
*/
	Image[img_index] = imread(filenames[img_index]);
	ImageColor[img_index] = imread(filenames[img_index], IMREAD_GRAYSCALE);
}

void img_write(int img_index) {
/**
* writes one processed image from edge_detecting function to destination folder
* @param img_index is an index of processed image
*/
	string fileName = dir_img.output + to_string(img_index) + ".png";
	imwrite(fileName, Image[img_index]);
}

void edge_detecting(int img_index) {
/**
* edge detecting function based on laplacian detection, processes singular image from img_read function
* and saves output to global variable
* @param img_index is an index of processed image
*/
	Mat tmp;
	cvtColor(Image[img_index], tmp, COLOR_BGR2GRAY, 0);
	Laplacian(tmp, Image[img_index], CV_16S, 5, 1, 0, 4);
}

void thumbnails_matrix(string file_name, vector<Mat> ImagesToConcatanate){
/**
* creates matrix of thumbnails of given images, and saves to output file
* @param file_name is the name of output thumbnail matrix file
* @param ImagesToConcatanate is a vector of images to merge
*/
	vector<Mat> CroppedImages;
	CroppedImages.resize(filenames.size());
	for (int img_index = 0; img_index < filenames.size(); img_index++) {
		
		CroppedImages[img_index] = ImagesToConcatanate[img_index](
			Rect(
				ImagesToConcatanate[img_index].size().width / 2 - ROWS/2,
				ImagesToConcatanate[img_index].size().height / 2 - COLS/2,
				ROWS,
				COLS
			)
		);
	}
	
	int matrix_side = ceil(sqrt((float)filenames.size()));
	// Get dimension of final image
	int rows = ROWS * matrix_side;
	int cols = COLS * matrix_side;

	// Create a black image
	Mat res = cv::Mat::zeros(cv::Size(rows, cols), CV_64F);

	for (int i = 0; i < matrix_side; i++) {
		for (int j = 0; (j < matrix_side) and (j + matrix_side * i < filenames.size()); j++) {

			CroppedImages[j + matrix_side*i].copyTo(res(Rect(COLS*j, ROWS*i, CroppedImages[j + matrix_side * i].cols, CroppedImages[j + matrix_side * i].rows)));
		}
	}
	string fileName = dir_img.output + file_name + ".png";
	imwrite(fileName, res);
}