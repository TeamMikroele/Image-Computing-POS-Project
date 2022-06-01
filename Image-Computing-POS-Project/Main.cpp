#include <iostream>
#include "ini_parser.h"
#include "img_proces.h"

using namespace std;

int main() {
	
	ini_read();
	img_read();
	for (int i =0; i<size(Image); i++) Image[i] = edge_detecting(Image[i]);
	img_write();
	system("PAUSE");
	return 0;

}