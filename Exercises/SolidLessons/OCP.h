#pragma once

#include <string>
#include <vector>
#include <iostream>

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

template <typename T>
struct AndSpecification;

template <typename T>
struct Specification
{
	virtual ~Specification() = default;
	virtual bool is_satisfied(T* item) const = 0;

	AndSpecification<T> operator &&(const Specification<T>& other)
	{
		return { *this, other };
	}
};

template <typename T>
struct AndSpecification : public Specification<T>
{
	const Specification<T>& first;
	const Specification<T>& second;

	AndSpecification(const Specification<T>& f, const Specification<T>& s) : first(f), second(s) {}

	~AndSpecification() override = default;
	bool is_satisfied(T* item) const override
	{
		return first.is_satisfied(item) && second.is_satisfied(item);
	}
};

template <typename T>
struct Filter
{
	virtual ~Filter() = default;
	virtual std::vector<T*> filter(std::vector<T*>& items,
								   Specification<T>& spec) const = 0;
};

struct ProductFilter : public Filter<Product>
{
	~ProductFilter() override = default;
	std::vector<Product*> filter(std::vector<Product*>& items,
								 Specification<Product>& spec) const override
	{
		std::vector<Product*> result;
		for (auto& item : items)
		{
			if (spec.is_satisfied(item))
			{
				result.push_back(item);
			}
		}
		return result;
	}
};

struct ColorSpec : public Specification<Product>
{
	Color color;

	ColorSpec(Color c) : color(c) {}
	~ColorSpec() override = default;

	bool is_satisfied(Product* item) const override
	{
		return item->color == color;
	}
};

struct SizeSpec : public Specification<Product>
{
	Size size;

	SizeSpec(Size s) : size(s) {}
	~SizeSpec() override = default;

	bool is_satisfied(Product* item) const override
	{
		return item->size == size;
	}
};

class OCP
{
public:
	void Execute()
	{
		Product notebook{ "notebook", Color::Green, Size::Medium };
		Product pen{ "pen", Color::Blue, Size::Small };
		Product monitor{ "monitor", Color::Green, Size::Large };
		Product fridge{ "fridge", Color::Red, Size::Large };

		std::vector<Product*> products{ &notebook, &pen, &monitor, &fridge };

		ColorSpec colorSpec(Color::Green);
		SizeSpec sizeSpec(Size::Large);
		auto colorAndSizeSpec = colorSpec && sizeSpec;
		auto testSpec = ColorSpec(Color::Blue) && SizeSpec(Size::Small);
		ProductFilter pf;

		auto greenStuff = pf.filter(products, colorSpec);
		auto largeStuff = pf.filter(products, sizeSpec);
		auto greenAndLargeStuff = pf.filter(products, colorAndSizeSpec);
		auto test = pf.filter(products, testSpec);
	}
};

