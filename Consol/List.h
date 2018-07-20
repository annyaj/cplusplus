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


public:
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
	void add(int value);
	int pop();
	int get();
	bool isEmpty();
	string toString();
	void begin();
	void next();
	bool end();

	static void sort(List list, SortOrder order);

	~List();
};

