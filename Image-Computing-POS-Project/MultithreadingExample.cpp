#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

bool finish = false;

const auto processors = std::thread::hardware_concurrency();

mutex mymutex;
thread* worker = new thread[processors];

void Work(int n)
{
	using namespace literals::chrono_literals;
	
	while (!finish)
	{
		mymutex.lock(); //do lockowania zapisu na dysk
		cout << "Thread" << n + 1 << "working. ID=" << worker[n].get_id() << endl;
		//this_thread::sleep_for(0.5s);
		mymutex.unlock();
	}
	
}

int main()
{
	cout << processors << endl;

	for (int i = 0; i < processors; i++)
	{
		worker[i] = thread(Work, i);
	}

	cin.get();
	finish = true;

	for (int i = 0; i < processors; i++)
	{
		worker[i].join();
	}

	cout << "Finish.\n";

	cin.get();
	
	delete[] worker;

	return 0;
}
