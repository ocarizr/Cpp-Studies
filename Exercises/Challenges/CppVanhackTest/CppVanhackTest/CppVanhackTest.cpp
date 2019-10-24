// CppVanhackTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <vector>

using namespace std;

map<string, function<string(string, string)>> string_operators;
map<string, function<int(int, int)>> integer_operators;

void populate_binary_operator_function_objects_map() {
	/*
	 * Populate the global maps to hold the binary operation function objects.
	 */
	integer_operators["add"] = [](int a, int b){return a + b};
	integer_operators["sub"] = [](int a, int b){return a - b};
	integer_operators["bitwise_and"] = [](int a, int b){return a & b};
	integer_operators["bitwise_or"] = [](int a, int b){return a | b};
	integer_operators["bitwise_xor"] = [](int a, int b){return a ^ b};

	string_operators["pre_concat"] = [](string a, string b){return a + b};
	string_operators["post_concat"] = [](string a, string b){return b + a};
}

/*
 * Create the customized_accumulate function here.
 */
string customized_accumulate(vector<int>::iterator begin, vector<int>::iterator end, function<int(int, int)> first_operation, function<int(int, int)> second_operation)
{
	int ret = 0;
	try {
		if (end < begin)
		{
			return std::to_string(*begin);
		}

		auto it = begin;
		bool op = true;
		ret = first_operation(*it, *(it + 1));
		it += 2;

		while (it < end)
		{
			if (!op)
			{
				ret = first_operation(ret, *it);
			}
			else
			{
				ret = second_operation(ret, *it);
			}
			op = !op;
			it++;
		}
	}
	catch (...)
	{
		ret = *begin;
	}

	return std::to_string(ret);
}

string customized_accumulate(vector<string>::iterator begin, vector<string>::iterator end, function<string(string, string)> first_operation, function<string(string, string)> second_operation)
{
	string ret = "";
	try {
		if (end < begin)
		{
			return *begin;
		}

		auto it = begin;
		bool op = true;
		ret = first_operation(*it, *(it + 1));
		it += 2;

		while (it < end)
		{
			if (!op)
			{
				ret = first_operation(ret, *it);
			}
			else
			{
				ret = second_operation(ret, *it);
			}
			op = !op;
			it++;
		}
	}
	catch (...)
	{
		ret = *begin;
	}

	return ret;
}

void validate_binary_operator_function_objects() {
	assert(integer_operators["add"](3, 5) == 8);
	assert(integer_operators["sub"](3, 5) == -2);
	assert(integer_operators["bitwise_and"](3, 5) == 1);
	assert(integer_operators["bitwise_or"](3, 5) == 7);
	assert(integer_operators["bitwise_xor"](3, 5) == 6);

	assert(string_operators["pre_concat"]("abc", "pqrs") == "abcpqrs");
	assert(string_operators["post_concat"]("abc", "pqrs") == "pqrsabc");
}

void validate_customized_accumulate() {
	std::string type;
	int n;
	std::cin >> type >> n;

	std::vector<std::string> str_arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> str_arr[i];
	}

	std::string first_key, second_key;
	std::cin >> first_key >> second_key;

	if (type == "String") {
		auto first_operator = string_operators[first_key];
		auto second_operator = string_operators[second_key];

		std::cout << customized_accumulate(begin(str_arr), end(str_arr), first_operator, second_operator) << std::endl;
	}
	else {
		std::vector<int> int_arr(n);
		for (int i = 0; i < n; i++) {
			int_arr[i] = stoi(str_arr[i]);
		}

		auto first_operator = integer_operators[first_key];
		auto second_operator = integer_operators[second_key];

		std::cout << customized_accumulate(begin(int_arr), end(int_arr), first_operator, second_operator) << std::endl;
	}
}

int main()
{
	populate_binary_operator_function_objects_map();
	validate_binary_operator_function_objects();

	int q;
	std::cin >> q;

	while (q--) {
		validate_customized_accumulate();
	}

	return 0;
}
