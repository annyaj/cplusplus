#include "stdafx.h"
#include "List.h"



void List::add(int value)
{
	elem* a = new elem;
		a->next = nullptr;
		a->value = value;
	if (root == nullptr)
	{
		root = a;
		current = a;
	}
	else if (current->next != nullptr)
	{
		a ->next = current->next;
		current ->next = a;
		current = a;
	}
	else
	{
		current->next = a;
		current = a;
	}
}

int List::pop()
{
	elem* t=root;
	while (t->next != current)
	{
		t = t->next;
	}
	if (current == root)
	{
		if (root->next != nullptr)
		{
			root = root->next;
			delete current;
			current = root;
		}
		else
		{
			delete current;
			root = nullptr;
			current = nullptr;
		}
	}
	else if (current->next == nullptr)
	{
		elem* t = root;
		while (t->next != current)
		{
			t = t->next;
		}
		delete current;
		t->next = nullptr;
		current = t;

	}
	else
	{
		elem* a = root;
		while (a->next != current)
		{
			a->next = current;
		}
		a->next = current->next;
		delete current;
		current = a;
	}

	return 0;
}


string List::toString()
{
	string ss = "";
	for (begin(); !end(); next())
	{
		ss +=to_string(current->value);
		ss += " ";
	}
	ss += to_string(current->value);
	return ss;
}

void List::begin()
{
	current = root;
}

void List::next()
{
	current = current->next;
}

bool List::end()
{
	return (current->next ==nullptr);
}

List::~List()
{
}
