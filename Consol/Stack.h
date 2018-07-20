#pragma once
#include <string>

using namespace std;
class Stack
{
	struct elem
	{
		int value;
		elem* next;
		elem() {}
		elem(int value, elem* next) {
			this->value = value;
			this->next = next;
		}
	};
	elem* root = nullptr;

	
public:
	Stack(const Stack& old)
	{
		if (old.isEmpty()) return;
		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el != nullptr; el = el->next)
		{
			elem* current = new elem(el->value, nullptr);
			prev->next = current;
			prev = current;
		}
	}
	Stack()
	{
		root = nullptr;
	}
	void reverse(const Stack& old,Stack& rev);
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty()const;
	string toString();
	~Stack();
};

