// Consol.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	Stack m;
	m.add(44);
	m.add(48);
	m.add(95);
	cout << m.toString()<<endl;
	int a = 0;
	m.pop(a);
	cout << m.toString();
	cout << endl << a;
	_getch();
    return 0;
}

