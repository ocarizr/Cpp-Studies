#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>

using namespace std;
/*
 * Declare the global maps here.
 */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int bitwise_and(int a, int b) { return a & b; }
int bitwise_or(int a, int b) { return a | b; }
int bitwise_xor(int a, int b) { return a ^ b; }

string pre_concat(string a, string b) { return a + b; }
string post_concat(string a, string b) { return b + a; }

map<string, function<int(int, int)>> integer_operators;
map<string, function<string(string, string)>> string_operators;

void populate_binary_operator_function_objects_map() {
	/*
	 * Populate the global maps to hold the binary operation function objects.
	 */
	integer_operators["add"] = add;
	integer_operators["sub"] = sub;
	integer_operators["bitwise_and"] = bitwise_and;
	integer_operators["bitwise_or"] = bitwise_or;
	integer_operators["bitwise_xor"] = bitwise_xor;

	string_operators["pre_concat"] = pre_concat;
	string_operators["post_concat"] = post_concat;
}

/*
 * Create the customized_accumulate function here.
 */
string customized_accumulate(vector<string>::iterator begin, vector<string>::iterator end, function<string(string, string)> first_operator, function<string(string, string)> second_operator)
{
	vector<string> str_arr;
	vector<string>::iterator it;
	it = str_arr.begin();
	for (it = begin; it != end; it++)
	{
		str_arr.push_back(*it);
	}

	string _customized_accumulate = str_arr[0];

	for (unsigned int i = 1; i < str_arr.size(); i++)
	{
		if ((i - 1) % 2 == 0)
		{
			_customized_accumulate = first_operator(_customized_accumulate, str_arr[i]);
		}
		else {
			_customized_accumulate = second_operator(_customized_accumulate, str_arr[i]);
		}
	}
	return _customized_accumulate;
}

int customized_accumulate(vector<int>::iterator begin, vector<int>::iterator end, function<int(int, int)> first_operator, function<int(int, int)> second_operator)
{
	vector<int> str_arr;
	vector<int>::iterator it;
	it = str_arr.begin();
	for (it = begin; it != end; it++)
	{
		str_arr.push_back(*it);
	}

	int _customized_accumulate = str_arr[0];

	for (unsigned int i = 1; i < str_arr.size(); i++)
	{
		if ((i - 1) % 2 == 0)
		{
			_customized_accumulate = first_operator(_customized_accumulate, str_arr[i]);
		}
		else {
			_customized_accumulate = second_operator(_customized_accumulate, str_arr[i]);
		}
	}
	return _customized_accumulate;
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

	system("pause");

	return 0;
}
