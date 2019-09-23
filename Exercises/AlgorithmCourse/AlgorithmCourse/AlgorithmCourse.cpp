#include <iostream>

class single
{
	single() { std::cout << "Create" << std::endl; }

	static single instance;

public:
	~single() { std::cout << "Destroy" << std::endl; }

	inline static single getInstance() { return instance; }

	inline void print() { std::cout << "Print" << std::endl; }
};

int main()
{
	single *i = &single::getInstance();

	i->print();

	single::getInstance().print();

	return 0;
}
