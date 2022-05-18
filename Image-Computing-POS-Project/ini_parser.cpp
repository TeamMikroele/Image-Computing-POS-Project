#include <iostream>
#include <windows.h>
#include <sys/stat.h>


using namespace std;

struct dir {
	char input [256];
	char output [256];
};
struct dir dir_img;

bool check_dir(char * dir) {

	if (dir == NULL) {

		cout << "Cannot read a directory" << endl;
		return false;
	}

	struct stat buffer;

	if (stat(dir, &buffer) != 0) {
		cout << "\"" << dir << "\"" << " directory doesn't exist!" << endl;
		return false;
	}
	else {
		cout << "\"" << dir << "\"" << " directory exist!" << endl;
	}
	return true;
}

int ini_read() {

	GetPrivateProfileString("input_folder", "input", NULL, dir_img.input, 256, "./Initial_file.ini");
	GetPrivateProfileString("output_folder", "output", NULL, dir_img.output, 256, "./Initial_file.ini");

	if (!check_dir(dir_img.input) || !check_dir(dir_img.output)) {
		return 0;
	}
	return 1;
}