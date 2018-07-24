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
	elem* tail = nullptr;


public:

	class iterator
	{
		elem* cur = nullptr;
		
	public:
		iterator() {}
		iterator(elem* cur)
		{
			this->cur = cur;
		}
		bool operator==(iterator& it) {
			return cur == it.cur;
		}
		bool operator!= (iterator& it)
		{
			return cur != it.cur;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator(iterator& it)
		{
			cur = it.cur;
		}
		iterator& operator=(iterator& it)
		{
			cur = it.cur;
			return *this;
		}
		int operator*()
		{
			return 	cur->value;
		}

	};
	
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
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty()const;
	iterator& begin();
	string toString();
	~Stack();
};

