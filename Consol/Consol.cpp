// Consol.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "ArrayProcessor.h"
#include "Dlist.h"
#include "Stack.h"
using namespace std;

Stack func(const Stack& a, const Queue& b)
{
	Stack t(a);
	Stack f;
	while (!t.isEmpty())
	{
		Queue n(b);
		int value = 0;
		t.pop(value);
		while (!n.isEmpty())
		{
			int val2 = 0;
			n.pop(val2);
			if (value == val2)
			{
				f.add(value);
			}
		}
	}
	return f;
}

Stack f(const Stack& a)
{
	Stack n(a);
	Stack t;
	while (!n.isEmpty())
	{
		bool out = false;
		int value = 0;
		n.pop(value);
		for (int i = 2; i < value; i++)
		{
			if (value%i == 0)
			{
				out = true;
				break;

			}
		}
		if (out == true)
		{
			t.add(value);
		}

	}
	return t;
}
int main()
{

	Stack n;
	n.add(44);
	n.add(85);
	n.add(17);
	n.add(95);
	n.add(13);


	cout << f(n).toString() << endl;

	

	_getch();
	return 0;
}

