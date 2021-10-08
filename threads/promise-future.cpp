#include <iostream>
#include <future>
#include <thread>
using namespace std;

void product(promise<int>&& prom, int a, int b)
{
	std::cout << "product geht schlafen\n";
	std::this_thread::sleep_for(5000ms);
	std::cout << "product wacht auf\n";
	prom.set_value(a * b);
}

void main()
{
	promise<int> prom;
	future<int> result = prom.get_future();

	std::cout << "main geht schlafen vor thread aufruf\n";
	std::this_thread::sleep_for(1000ms);
	std::cout << "main wacht auf vor thread aufruf\n";
	thread t(product, std::move(prom), 1, 2);
	std::cout << "main geht schlafen nach thread aufruf\n";
	std::this_thread::sleep_for(1000ms);
	std::cout << "main wacht auf nach thread aufruf\n";

	std::cout << result.get() << endl;
	t.join();
}

/*
main geht schlafen vor thread aufruf
main wacht auf vor thread aufruf
main geht schlafen nach thread aufruf
product geht schlafen
main wacht auf nach thread aufruf
product wacht auf
2
*/
