#pragma once
#include "../List_stack/Stack.h"
#include <iostream>
#include <string>
using namespace std;

class TCalculator
{
	string infix;
	string postfix;
	Stack<char> st_c;
	Stack<double> st_d;
	void ToPostfix();
	bool CheckBrackets();
	int Priority(char elem);
public:
	void SetFormula(string str);
	double CalcPostfix();
};