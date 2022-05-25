#include <iostream>
#include <thread>

using namespace std;

bool finish = false;

const auto processors = std::thread::hardware_concurrency();

void Work()
{
	using namespace literals::chrono_literals;

	while (!finish)
	{
		cout << "Praca, praca...\n";
		this_thread::sleep_for(1s);
	}
}

int main()
{
	cout << processors << endl;

	thread worker(Work);
	//thread worker1(Work);

	cin.get();
	finish = true;

	worker.join();
	//worker1.join();
	cout << "Koniec.\n";

	cin.get();
	return 0;
}
