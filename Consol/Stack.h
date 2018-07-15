#pragma once
#include <string>

using namespace std;
class Stack
{
	struct elem
	{
		int value;
		elem* next;
	};
	elem* root = nullptr;

public:
	Stack()
	{
		root = nullptr;
	}
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty();
	string toString();
	~Stack();
};

