#include <iostream>
#include <thread>
#include <mutex>
#include "img_proces.h"

using namespace std;

/**
 * variable which defines number of available threads to run our process
 */
auto processors = std::thread::hardware_concurrency();

/**
 * declaration of mutex
 */
mutex mymutex;

/**
 * creating an array of threads to process images
 */
thread* worker = new thread[processors];

void Work(int n)
{
/**
 * thread routine. An image is loaded, processed and then a mutex locks 
 * to make sure only one image is written to hdd at a time.
 * @param n is a number of current processed image from images vector
 */
	img_read(n);
	edge_detecting(n);
	mymutex.lock();
	img_write(n);
	mymutex.unlock();
}

void multithread() {
/**
 * This function enables multithread processing.
 * At first the number of iterations is counted, given the number of images to process.
 * Whole processing work is divided by the number of available threads to run.
 * Function starts each thread and as it finished its work, realeases a thread in a for() loop.
 */
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
/**
 * delete an array of threads
 */
	delete[] worker;
}