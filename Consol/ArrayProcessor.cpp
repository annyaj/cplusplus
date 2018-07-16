#include "stdafx.h"
#include "ArrayProcessor.h"

void ArrayProcessor::worst_sort(int * values, const int size) {

	for (int i = 0; i < size; i++)
	{
		cout << "<DEBUG: ";
		for (int k = 0; k < 10; k++)
			cout << values[k] << " ";
		cout << "/>" << endl;

		for (int j = 1; j < size; j++)
		{
			if (values[j - 1] > values[j])
			{
				swap(values[j - 1], values[j]);
			}

		}


	}
}

void ArrayProcessor::bubble_sort(int * values, const int size)
{
	for (int i = size; i >= 0; i--)
	{
		cout << "<DEBUG: ";
		for (int k = 0; k < 10; k++)
			cout << values[k] << " ";

		for (int j = 1; j < i; j++)
		{
			if (values[j - 1] > values[j])
			{
				cout << "\t<swap " << values[j - 1] << " with " << values[j] << ">" << endl;
				swap(values[j - 1], values[j]);
			}
		}

		cout << "/>" << endl;
	}
}

void ArrayProcessor::insertion_sort(int * values, const int size)
{
	int x = 0;
	for (int i = 0; i < size; i++)
	{
		x = values[i];
		int j = i;
		for (; j > 0 && values[j - 1] > x; j--)
		{
			values[j] = values[j - 1];
		}
		values[j] = x;		
	}
}
