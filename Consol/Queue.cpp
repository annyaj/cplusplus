#include "stdafx.h"
#include "Queue.h"



void Queue::add( int value)
{
	elem* t = new elem(value, tail);
	if (root == nullptr)
	{
		root = t;
	}
	else
	{
		elem* g = root;
		while (g->next != tail)g = g->next;
		g->next = t;
	}
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

Queue::iterator& Queue::begin()
{
	iterator* b = new iterator(root);
	return *b;
}

Queue::iterator& Queue::end()
{
	iterator* e = new iterator(tail);
	return *e;
}

string Queue::toString()
{
	string s = "";
	elem* n = root;
	for (; n!=tail; n = n->next)
	{
		s += to_string(n->value);
		s += " ";
	}
	return s;
}

Queue::~Queue()
{
}
