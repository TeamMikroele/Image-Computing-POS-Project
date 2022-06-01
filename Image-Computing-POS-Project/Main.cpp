#include <iostream>
#include <thread>
#include <mutex>
#include "ini_parser.h"
#include "img_proces.h"

using namespace std;

bool finish = false;

auto processors = std::thread::hardware_concurrency();

mutex mymutex;
thread* worker = new thread[processors];

void Work(int n)
{
	using namespace literals::chrono_literals;

	while (!finish)
	{
		//mymutex.lock(); //do lockowania zapisu na dysk
		Image[n] = edge_detecting(Image[n]);
		//mymutex.unlock();
	}

}

int main() {

	cout << processors << endl;

	
	
	ini_read();
	img_read();
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

		finish = true;

		for (int j = 0; j < processors; j++)
		{
			worker[j].join();
		}
	}

	

	//for (int i =0; i<size(Image); i++) Image[i] = edge_detecting(Image[i]);

	img_write();
	
	delete[] worker;
	system("PAUSE");
	return 0;

}