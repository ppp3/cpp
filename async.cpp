#include <iostream>
#include <future>
#include <thread>

using namespace std;
using std::cout;

void main()
{
	 cout << "Thread ID von main: " << std::this_thread::get_id() << endl;;
	 auto myFuture1 = async(launch::deferred,[] {
		//Hat gleiche Thread ID wie main Thread. Wird später synchron aufgerufen 
		cout << "Thread ID von future1: " << std::this_thread::get_id()<<endl;
		cout << "Future1 geht schlafen!\n";
		std::this_thread::sleep_for(5000ms);
		cout << "Future1 wacht auf!!\n";
		return 42 + 12; 
		});
	
	
	std::future<int> myFuture2 = async(launch::async, [] {
		//Hat andere ID und wird direkt aufgerufen
		cout << "Thread ID von future2: " << std::this_thread::get_id() << endl;
		cout << "Future2 geht schlafen!\n";
		std::this_thread::sleep_for(5000ms);
		cout << "Future2 wacht auf!!\n";
		return 42 + 12; 
		});

	cout << "Main Thread geht schlafen\n";
	std::this_thread::sleep_for(10000ms);
	cout << "Main Thread wacht auf\n";
	//Blockieren beide
	cout << "Ergebnis von myFuture1:"<< myFuture1.get() << endl;
	cout << "Ergebnis von myFuture2:" << myFuture2.get() << endl;
	//cout << myFuture1.get() << endl;
	std::cout << "Ende!"<<endl; 
}
