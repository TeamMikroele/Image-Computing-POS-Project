#include <iostream>
#include <windows.h>

using namespace std;

struct dir {
	char input [256];
	char output [256];
};
struct dir dir_img;

char * get_dir() {
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
	GetPrivateProfileString("input_folder", "input", NULL, dir_img.input, 256, get_dir());
	GetPrivateProfileString("output_folder", "output", NULL, dir_img.output, 256, get_dir());

	if (!check_dir(dir_img.input) || !check_dir(dir_img.output)) {
		return 0;
	}
	return 1;
}