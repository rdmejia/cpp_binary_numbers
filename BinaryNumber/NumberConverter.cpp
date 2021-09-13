#include "pch.h"
#include "NumberConverter.h"
#include <iostream>
#include <string.h>

using std::string;
using std::vector;

string NumberPrinter::toBase2String(int number)
{
	if (number == 0) {
		return "0";
	}

	return toBase2String(number, 0, "");
}

vector<string> NumberPrinter::toBase2Strings(vector<int> numbers)
{
	vector<string> results = vector<string>();
	int size = numbers.size();

	for (int i = 0; i < size; i++) {
		string result = toBase2String(numbers[i]);

		results.push_back(result);
	}

	return results;
}

string NumberPrinter::toBase2String(int number, int i, string result)
{
	if (number == 0) {
		return result;
	}

	char digit = ((number % 2) + '0');
	result = result.insert(0, &digit);

	return toBase2String(number / 2, i + 1, result);
}
