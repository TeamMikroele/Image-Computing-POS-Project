
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <math.h>
#include <iostream>
#include "ini_parser.h"

using namespace std;
using namespace cv;

const int w = 500;
int levels = 3;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

vector<Mat> Image;

void img_read()
{
    vector<String> filenames;
    glob(dir_img.input, filenames);
    Image.resize(filenames.size());


    for (int i = 0; i < filenames.size(); ++i)
    {
        Image[i] = imread(filenames[i]);
    }
	

}

void img_write()
{
    vector<String> filenames;
    glob(dir_img.input, filenames);

    for (int i = 0; i < filenames.size(); ++i)
    {
        string fileName = dir_img.output + to_string(i) + ".png";
        imwrite(fileName, Image[i]);
        
    }
}