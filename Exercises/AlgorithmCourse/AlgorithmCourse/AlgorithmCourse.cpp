#include <iostream>

uint16_t g_number = 3;

size_t counter()
{
	static size_t index = 0;

	return ++index;
}

int main()
{
	uint16_t l_number = g_number;

	std::cout << l_number << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << counter() << std::endl;
	}

	return 0;
}
