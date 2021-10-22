#pragma once

#include <string>

enum class Color : uint8_t
{
	Red,
	Green,
	Blue
};

enum class Size : uint8_t
{
	Small,
	Medium,
	Large
};

struct Product
{
	std::string name;
	Color color;
	Size size;
};

struct ProductFilter
{

};

class OCP
{
public:
	void Execute()
	{

	}
};

