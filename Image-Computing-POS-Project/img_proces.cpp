#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/core/matx.hpp"
#include <math.h>
#include <iostream>
#include "ini_parser.h"

using namespace std;
using namespace cv;

vector<Mat> Image;

void img_read()
{
    vector<String> filenames;

	strcat_s(dir_img.input, "*.png");
    glob(dir_img.input, filenames);

    Image.resize(filenames.size());
	if (!filenames.size())
		cout << "error: there is no .png file in " << dir_img.input << endl;

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