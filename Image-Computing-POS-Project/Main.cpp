#include <iostream>
#include "ini_parser.h"
#include "img_proces.h"
#include "multithread.h"

using namespace std;

int main() {	
	ini_read();
	multithread();
	system("PAUSE");
	return 0;
}