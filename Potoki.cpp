#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void doWork()
{

	for (int i = 0; i < 5; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << this_thread::get_id() << "work   " << i+1 << endl;
	}

}
int main()
{
	setlocale(LC_ALL, "ru");
	doWork();
	doWork();
	/*thread th(doWork); 
	thread th2(doWork);*/

	for (int i = 0; i < 5; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << this_thread::get_id() << "main   " <<  i+1 << endl;
	}
	//th.join();
	//th2.join();
	
	return 0;
}