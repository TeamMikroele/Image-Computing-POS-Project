#include <iostream>
#include <thread>
#include <mutex>
#include "img_proces.h"

using namespace std;

auto processors = std::thread::hardware_concurrency();

mutex mymutex;
thread* worker = new thread[processors];

void Work(int n)
{
	img_read(n);
	edge_detecting(n);
	mymutex.lock();
	img_write(n);
	mymutex.unlock();
}

void multithread() {

	cout << "Number of threads: " << processors << endl;

	int images = size(Image) - 1;

	int iterations = size(Image) / processors;
	if (size(Image) % processors)
	{
		iterations++;
	}

	for (int i = 0; i < iterations; i++)
	{
		if (i == iterations - 1 && size(Image) % processors != 0)
			processors = size(Image) % processors;
		for (int j = 0; j < processors; j++)
		{
			worker[j] = thread(Work, images);
			images--;
		}

		for (int j = 0; j < processors; j++)
		{
			worker[j].join();
		}
	}
	delete[] worker;
}