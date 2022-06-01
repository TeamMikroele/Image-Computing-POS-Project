#include <iostream>
#include <thread>
#include <mutex>
#include "ini_parser.h"
#include "img_proces.h"

using namespace std;

auto processors = std::thread::hardware_concurrency();

mutex mymutex;
thread* worker = new thread[processors];

void Work(int n)
{
	using namespace literals::chrono_literals;
	//mymutex.lock(); //do lockowania zapisu na dysk
	edge_detecting(n);
	//mymutex.unlock();

}

int main() {

	cout << processors << endl;

	
	
	ini_read();
	read_input_folder_info();
	for (int i = 0; i < size(Image); i++)img_read(i);
	int obrazki = size(Image) - 1;

	int iteracje = size(Image) / processors;
	if (size(Image) % processors)
	{
		iteracje++;
	}

	
	for (int i = 0; i < iteracje; i++)
	{
		if (i == iteracje - 1 && size(Image) % processors != 0)
			processors = size(Image) % processors;
		for (int j = 0; j < processors; j++)
		{
			worker[j] = thread(Work, obrazki);
			obrazki--;
		}

		for (int j = 0; j < processors; j++)
		{
			worker[j].join();
		}
	}

	

	//for (int i =0; i<size(Image); i++) Image[i] = edge_detecting(Image[i]);

	for (int i = 0; i < size(Image); i++)img_write(i);
	
	delete[] worker;
	system("PAUSE");
	return 0;

}