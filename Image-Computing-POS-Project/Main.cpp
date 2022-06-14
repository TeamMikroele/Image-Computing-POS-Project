#include <iostream>
#include "ini_parser.h"
#include "img_proces.h"
#include "multithread.h"

//#define debug

using namespace std;

int main() {
	/**
	* program main function
	* calls every needed function
	* memory tests can be called from here
	*/
	#ifdef debug
		// Memory leak
		int* q = new int;
		//no delete
		_CrtDumpMemoryLeaks();

		int* test = new int[1];
		for (int i = 0; i < 10; i++) {
			test[i] = 1;
		}
		_ASSERTE(_CrtCheckMemory());
	#endif

	ini_read();
	read_input_folder_info();
	multithread();
	thumbnails_matrix("matrix_input", ImageColor);
	thumbnails_matrix("matrix_processed", Image);
	_ASSERTE(_CrtCheckMemory());
	system("PAUSE");
	return 0;
}