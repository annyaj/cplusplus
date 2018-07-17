#pragma once
#include "Dequeue.h"
#include <iostream>
#include <conio.h>

using namespace std;
class ArrayProcessor
{
public:
	static void worst_sort(int* values, const int size);
	static void bubble_sort(int* values, const int size);
	static void selection_sort(int* values, const int size);
	static void insertion_sort(int* values, const int size);
	static void shell_sort(int* values, const int size);


};

