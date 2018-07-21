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
void ArrayProcessor::selection_sort(int*values, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		cout << "<DEBUG: " << endl;
		for (int k = 0; k < 10; k++)
			cout << values[k] << " ";
		for (int j = i + 1; j < size; j++)
		{
			if (values[j] < values[min])
				min = j;
		}
		if (min != i)
		{
			cout << "\t<swap " << values[i] << " with " << values[min] << ">" << endl;
			swap(values[i], values[min]);
		}
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

void ArrayProcessor::shell_sort(int* values, const int size)
{
	for (int d = size/2; d > 0; d = d/2)
	{
		for (int i = d; i < size; i++)
		{
			for (int j = i; j >= d; j = j - d)
			{
				if(values[j-d] > values[j])swap(values[j-d], values[j]);
			}
		}
	}

}

void ArrayProcessor::opti_buble_sort(int * values, const int size)
{
	bool flag = true;
	do
	{
		flag = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (values[j] > values[j + 1]) {
				std::swap(values[j], values[j + 1]);
				flag = false;
			}
		}
		if (flag) break;
	} while (!flag);
}


