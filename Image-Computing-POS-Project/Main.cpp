#include <iostream>
#include "ini_parser.h"
#include "img_proces.h"
#include "multithread.h"

using namespace std;

int main() {

	ini_read();
	read_input_folder_info();
	multithread();
	thumbnails_matrix("matrix_input", ImageColor);
	thumbnails_matrix("matrix_processed", Image);

	system("PAUSE");
	return 0;
}