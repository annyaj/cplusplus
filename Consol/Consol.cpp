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
	while (!copy.is_end())copy.next();
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
	Dlist a;
	a.push(14);
	a.push(15);
	a.push(11);
	a.push(17);
	cout << a.toStr() << endl;
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		cout << *i<<" ";
	}
	_getch();
	return 0;
}

