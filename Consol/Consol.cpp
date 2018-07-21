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
	return t;
}
Stack rev(Stack& a)
{
	Stack f;
	while (!a.isEmpty())
	{
		int value = 0;
		a.pop(value);
		f.add(value);
	}
	return f;
}

Stack f(const Dlist& b)
{
	Dlist copy(b);
	Stack a;
	copy.set_begin();
	while (!copy.end())copy.next();
	while (!copy.is_begin())
	{
		int value = copy.get();
		a.add(value);
		copy.prev();
	}
	int value = copy.get();
	a.add(value);

	return a;
}
int main()
{
	Dlist d;
	d.push(4);
	d.push(2);
	d.push(1);
	d.push(9);
	d.push(7);
	cout << d.toStr() << endl;
	d.rev();
	cout << d.toStr();
	_getch();
	return 0;
}

