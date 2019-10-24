#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <functional>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

typedef pair<string, function<int(int, int)>> mapPair;

mutex semaforo;

void imprimeChar(int n, char c)
{
	semaforo.lock();
	for (int i = 0; i < n; i++)
	{
		cout << c;;
	}
	cout << endl;
	semaforo.unlock();
}

void hello()
{
	cout << "Hello World" << endl;
}

void seeYou()
{
	cout << "See You Later" << endl;
}

void somaNumeros(int a, int b)
{
	cout << (a + b) << endl;
}

int main()
{
	try
	{
		thread First(hello);
		this_thread::sleep_for(chrono::milliseconds(100));
		thread Second(seeYou);
		this_thread::sleep_for(chrono::microseconds(100));
		thread Third(somaNumeros, 50, 10);

		First.join();
		Second.join();
		Third.join();

		thread t1(imprimeChar, 3, 'a');
		thread t2(imprimeChar, 5, 'b');
		thread t3(imprimeChar, 7, 'c');
		thread t4(imprimeChar, 1, 'e');

		t1.join();
		t2.join();
		t3.join();
		t4.join();

		vector<int> listOfGrades;
		vector<int>::iterator it;

		listOfGrades.push_back(10);
		listOfGrades.push_back(9);
		listOfGrades.push_back(7);
		listOfGrades.push_back(8);

		for (auto grade : listOfGrades)
		{
			std::cout << grade << std::endl;
		}

		for (it = listOfGrades.begin(); it != listOfGrades.end(); it++)
		{
			std::cout << *it << std::endl;
		}

		std::cout << listOfGrades.size() << std::endl;

		std::sort(listOfGrades.begin(), listOfGrades.end());

		for (auto grade : listOfGrades)
		{
			std::cout << grade << std::endl;
		}

		map<string, function<int(int, int)>> funcMap;

		funcMap.insert(mapPair("soma", [](int a, int b) {return a + b; }));
		funcMap.insert(mapPair("subtracao", [](int a, int b) {return a - b; }));

		std::cout << funcMap["soma"](10, 50) << std::endl;
		std::cout << funcMap["subtracao"](50, 10) << std::endl;

		listOfGrades.pop_back();
		listOfGrades.pop_back();
		listOfGrades.pop_back();
		listOfGrades.pop_back();
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}

	int num = 0;
	double num2 = num;
	num2 = 2.25;
	num = num2;
	cout << num << endl;
	double num3 = (int)num2 + num2;
	cout << num3 << endl;

	int num4 = static_cast<int>(num3);
	cout << num4 << endl;

	return 0;
}