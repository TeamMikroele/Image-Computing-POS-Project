#pragma once
/**
* global variable of directories of input and output dir
*/
struct dir {
	char input [256];
	char output [256];
};
extern struct dir dir_img;
/**
* reads initialization file
*/
int ini_read();
