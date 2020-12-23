#include"../List_stack/Stack.h"
#include "../List_stack/Calculator.h"
#include <string>
#include <iostream>

using namespace std;

void TCalculator::SetFormula(string str)
{
	infix = "";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			infix += " ";
		}
		infix += str[i];
	}
	if (CheckBrackets() != true)
	{
		throw 0;
	}
	Stack<char> s(infix.size());
	Stack<double> d(str.size());
	st_c = s;
	st_d = d;
}


bool TCalculator::CheckBrackets()
{
	st_c.Clear();
	st_d.Clear();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
				st_c.Push('(');
			
		}
		if (infix[i] == ')')
		{
			if (st_c.Empty() == true)
			{
				return false;
			}
			else
			{
				st_c.Pop();
			}
		}
	}
	return st_c.Empty();
}

int TCalculator::Priority(char elem)
{
	switch (elem)
	{
	case  '(': return 0;
	case  ')': return 1;
	case  '+': return 2;
	case  '-': return 2;
	case  '*': return 3;
	case  '/': return 3;
	case  '^': return 4;
	}
}

void  TCalculator::ToPostfix()
{
	if (!CheckBrackets())
	{
		throw "Wrong number of brackets";
	}
	st_c.Clear();
	st_d.Clear();
	postfix = " ";
	string scr = "( " + infix + " )";
	char elem = ' ! ';
	unsigned int i = 0;
	st_c.Clear();
	while (i < scr.size())
	{
		if (scr[i] == '+' || scr[i] == '-' || scr[i] == '*' || scr[i] == '/' || scr[i] == '^')
		{
			postfix += " ";
			elem = st_c.Pop();
			while (Priority(elem) >= Priority(scr[i]))
			{
				postfix += elem;
				elem = st_c.Pop();
			}
			st_c.Push(elem);
			st_c.Push(scr[i]);
		}
		else
			if (scr[i] == '(')
			{
				st_c.Push(scr[i]);
			}
			else
				if (scr[i] == ')')
				{
					elem = st_c.Pop();
					while (elem != '(')
					{
						postfix += elem;
						elem = st_c.Pop();
					}
				}
				else
					if (scr[i] >= '0' && scr[i] <= '9')
					{
						postfix += scr[i];
					}
		i++;
	}
	if (!st_c.Empty())
	{
		throw 0;
	}
}


double  TCalculator::CalcPostfix()
{
	if (!CheckBrackets())
	{
		throw "Wrong number of brackets";
	}
	st_d.Clear();
	char* tmp;
	unsigned int i = 0;
	double res = 0;
	while (i < postfix.size())
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_d.Push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			if (st_d.Empty())
			{
				throw "Wrong";
			}
			else
			{
				double op1, op2;
				op2 = st_d.Pop();
				op1 = st_d.Pop();
				switch (postfix[i]) {
				case '+':
					res = op1 + op2; break;
				case '-':
					res = op1 - op2; break;
				case '*':
					res = op1 * op2; break;
				case '/':
					res = op1 / op2; break;
				case '^':
					res = pow(op1, op2); break;
				default: if (postfix[i] != ' ')
					st_d.Push(postfix[i] - '0');
					break;
				}
				st_d.Push(res);
			}
		}
		i++;
	}
	if (st_d.Empty())
	{
		throw "Wrong";
	}
	else
	{
		res = st_d.Pop();
		return res;
	}
}