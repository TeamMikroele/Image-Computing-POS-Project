#include <iostream>
#include "ini_parser.h"
#include "img_proces.h"

using namespace std;

int main() {
	
	ini_read();
	img_read();
	img_write();
	system("PAUSE");
	return 0;
}