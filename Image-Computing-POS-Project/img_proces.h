#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <vector>

using namespace cv;
using namespace std;

/**
 * vector of images to process
 */
extern vector<Mat> Image;
/**
 * vector of loaded coloured images
 */
extern vector<Mat> ImageColor;

/**
 * function to read info of images to process
 */
void read_input_folder_info();
/**
* reads one image from source folder
*/
void img_read(int);
/**
* writes one processed image to destination folder
*/
void img_write(int);
/**
* edge detecting function based on laplacian detection, processes singular image
*/
void edge_detecting(int);
/**
* creates matrix of thumbnails of given images
*/
void thumbnails_matrix(string, vector<Mat>);