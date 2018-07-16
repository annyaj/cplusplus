#pragma once
#include <string>

using namespace std;
class Queue
{
	struct elem
	{
		int value = 0;
		elem* next = nullptr;
		elem() {}
		elem(int value, elem* next) {
			this->value = value;
			this->next = next;
		}
	};


	elem* root = nullptr;
	elem* tail = nullptr;
public:
	Queue()
	{
	}
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty();
	string toString();
	~Queue();
};

