#include <iostream>
#include <windows.h>
#include "ini_parser.h"

using namespace std;

/**
* global variable of directories of input and output dir
*/
struct dir dir_img;

char * get_dir() {
/**
* function reads global path of .exe file and changes it to folder where .ini file is located
* @return string with a global path to .ini file
*/
	char ownPth[MAX_PATH];

	// When NULL is passed to GetModuleHandle, the handle of the exe itself is returned
	HMODULE hModule = GetModuleHandle(NULL);
	if (hModule != NULL)
	{
		// Use GetModuleFileName() with module handle to get the path
		GetModuleFileName(hModule, ownPth, (sizeof(ownPth)));
		char buf[MAX_PATH];
		sprintf_s(buf, "%s/../../../Image-Computing-POS-Project/Initial_file.ini", ownPth);
		return buf;
	}
	else
	{
		cout << "Module handle is NULL" << endl;
		return ownPth;
	}
}

bool check_dir(char * dir) {
/**
* checks if given directory in *.ini file exists and output statement if it doesn't exist
* @param dir is an array of chars which contains directory
*/
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
/**
* reads initialization file and output file from path in Initial_file.ini
* @return returns 1 in case given directories in .ini file exist, if not returns 0
*/
	GetPrivateProfileString("input_folder", "input", NULL, dir_img.input, 256, get_dir());
	GetPrivateProfileString("output_folder", "output", NULL, dir_img.output, 256, get_dir());

	if (!check_dir(dir_img.input) || !check_dir(dir_img.output)) {
		return 0;
	}
	return 1;
}