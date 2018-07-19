#include "stdafx.h"
#include "Queue.h"



void Queue::add( int value)
{
	elem* t = new elem(value, nullptr);
	if (root == nullptr)
	{
		root = tail = t;
	}
	else
		tail->next = t;
	tail = t;
}

bool Queue::pop(int & value)
{
	if (root == nullptr) return false;
	elem* t = root;
	value = root->value;
	root = root->next;
	t->next = nullptr;
	delete t;
	return true;
}

bool Queue::pop()
{
	if (root == nullptr) return false;
	elem* t = root;
	root = root->next;
	t->next = nullptr;
	delete t;
	return true;
}

bool Queue::get(int & value)
{

	if (root == nullptr) return false;
	else
		value = root->value;
	return true;
}

bool Queue::isEmpty() const
{
	return root == nullptr;
}

string Queue::toString()
{
	string s = "";
	elem* n = root;
	for (; n->next != nullptr; n = n->next)
	{
		s += to_string(n->value);
		s += " ";
	}
	s += to_string(n->value);
	return s;
}

Queue::~Queue()
{
}
