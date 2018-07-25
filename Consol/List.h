#pragma once
#include <string>
#include "SortOrder.h"
using namespace std;




class List
{
	struct elem
	{
		int value;
		elem* next;
		elem() {}
		elem(int value, elem*next)
		{
			this->value = value;
			this->next = next;
		}
	};
	elem* root;
	elem* current;
	elem* tail = new elem(0, nullptr);


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
		iterator(iterator& it)
		{
			cur = it.cur;
		}
		bool operator ==(iterator& it)
		{
			return cur == it.cur;
		}
		bool operator!=(iterator& it)
		{
			return cur != it.cur;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator& operator=(iterator& it)
		{
			cur = it.cur;
			return *this;
		}
		int operator*()
		{
			return cur->value;
		}
	};
	List()
	{
		root = nullptr;
		current = nullptr;
	}
	List(const List& old)
	{
		root = new elem(old.root->value,nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el!= nullptr; el = el->next)
		{
			elem* current = new elem(el->value,nullptr);
			prev->next = current;
			prev = current;
		}
	}
	void rev();
	void add(int value);
	int pop();
	int get();
	bool isEmpty();
	string toString();
	iterator& begin();
	void next();
	iterator& end();
	void sort(SortOrder order);

	~List();
};

