#pragma once
#include "../List_stack/Stack.h"
#include <iostream>
#include <string>
class TCalculator
{
	std::string infix;
	std::string postfix;
public:
	void SetFormula(std::string str);
	double CalcPostfix();
	int Priority(char elem);
	Stack<char> st_c;
	Stack<double> st_d;
	void ToPostfix();
	bool CheckBrackets();
};