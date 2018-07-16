#include "stdafx.h"
#include "Dequeue.h"


Dequeue::Dequeue()
{
}

void Dequeue::push_back(const int value)
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

void Dequeue::push_front(const int value)
{
	elem* t = new elem(value, nullptr);
	if (root == nullptr)
	{
		root = tail = t;
	}
	else
	t->next=root;
	root = t;
}

bool Dequeue::pop_back(int & value)
{
	if (root == nullptr) return false;
	elem* t = root;
	while (t->next != tail)
	{
		t = t->next;
	}
	value = tail->value;
	t->next = nullptr;
	delete tail;
	tail = t;
	return true;
}

bool Dequeue::pop_front(int & value)
{
	if (root == nullptr) return false;
	elem* t = root;
	value = root->value;
	root = root->next;
	t->next = nullptr;
	delete t;
	return true;
}

bool Dequeue::get(int & value)
{
	return false;
}

bool Dequeue::isEmpty()
{
	return root==nullptr;
}

string Dequeue::toString()
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


Dequeue::~Dequeue()
{
}
