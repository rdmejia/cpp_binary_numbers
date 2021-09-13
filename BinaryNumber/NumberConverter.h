#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

ref class NumberPrinter
{
public:
	static string toBase2String(int number);
	static vector<string> toBase2Strings(vector<int> numbers);

private:
	static string toBase2String(int number, int i, string result);
};

