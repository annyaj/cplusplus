// Consol.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Dequeue.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include "ArrayProcessor.h"
#include "List.h"
using namespace std;
/*
Dequeue m;
m.push_front(44);
m.push_front(48);
m.push_back(95);
cout << m.toString()<<endl;
int a = 0;
m.pop_back(a);
cout << m.toString();
cout << endl << a;
m.pop_front(a);
cout << m.toString();
cout << endl << a;
_getch();
*/


int main()
{
	srand(time(0));
	int* a = new int[10];
	for (int i = 0; i < 10; i++)
		a[i] = rand() % 10;

	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;

	ArrayProcessor::bubble_sort(a, 10);
	List m;
	List::sort(m, SortOrder::Ascending);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
    return 0;
}

