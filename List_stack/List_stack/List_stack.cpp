#include <iostream>
#include "../List_stack/Calculator.h"
#include "../List_stack/Stack.h"
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	string exp;
	TCalculator calc;
	cout << "Введите выражение: " << endl;
	cin >> exp;
	calc.SetFormula(exp);
	try
	{
		calc.ToPostfix();
		cout << "Ответ: " << calc.CalcPostfix() << endl;
	}
	catch (const char* n) { cout << n << endl; }

	return 0;
}