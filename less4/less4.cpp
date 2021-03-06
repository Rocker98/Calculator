// less4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef int(*arithmeticFnc)(int, int);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

arithmeticFnc getArithmeticFnc(const char a);

struct ArithmeticStruct
{
	char op;
	arithmeticFnc pfn=nullptr;
};

static ArithmeticStruct arithmeticArray[]={
	{'+',add},
	{'-',subtract},
	{'*',multiply},
	{'/',divide}
};


int main()
{
	int firstUserNumb, secondUserNumber;
	char symbol;

	cout << "Enter first number :\t";
	cin >> firstUserNumb;
	cin.ignore();
	while (1)
	{
		cout << "Enter math operation '+', '-', '*' or '/'\t";
		cin >> symbol;
		cin.ignore();
		if (symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/')
			break;
		else cout << "Enter correct operation!"<<endl;
	}
	cout << "Enter second number :";
	cin >> secondUserNumber;
	cin.ignore();
	if (symbol == '/'&&secondUserNumber == 0)
		do
		{
			cout << "Enter second number (except from 0) :";
			cin >> secondUserNumber;
			cin.ignore();
		} while (secondUserNumber == 0);

		arithmeticFnc pfnc = getArithmeticFnc(symbol);

		cout << "Resault is :" << pfnc(firstUserNumb, secondUserNumber) << endl;

    return 0;
}

int add(int a, int b)
{
	return a+b;
}

int subtract(int a, int b)
{
	return a-b;
}

int multiply(int a, int b)
{
	return a*b;
}

int divide(int a, int b)
{
	return a/b;
}

arithmeticFnc getArithmeticFnc(const char a)
{
	for (auto &arith : arithmeticArray)
	{
		if (arith.op == a)
			return arith.pfn;
	}
	return add;
}
