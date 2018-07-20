// Consol.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "ArrayProcessor.h"
#include "List.h"
#include "Dlist.h"
#include "Stack.h"
#include "Queue.h"
#include "Dequeue.h"

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
	Stack ret;
	t.reverse(t, ret);
	return ret;
}
int main()
{
	srand(time(0));
	ArrayProcessor n;
	int size = 10;
	int* matr = new int[size];
	for (int i = 0; i < size; i++)
	{
		matr[i] = rand() % 10;
		cout << matr[i] << " ";
	}
	cout << endl;
	n.shell_sort(matr,size);
	for (int i = 0; i < size; i++)
	{
		cout << matr[i] << " ";
	}
	_getch();
	return 0;
}

