#include "stdafx.h"
#include "Stack.h"




void Stack::add(const int value)
{
	elem* a = new elem;
	a->next = root;
	root = a;
	a-> value= value;
}

bool Stack::pop(int& value)
{
	if (root == nullptr) return false;
	elem* t = root;
	value = root->value;
	root = root->next;
	delete t;
	return true;

}

bool Stack::get(int& value)
{
	if (root==nullptr) return false;
	else
		value = root->value;
	return true;
}

bool Stack::isEmpty()
{

	return root==nullptr;
}

string Stack::toString()
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

Stack::~Stack()
{
	int a = 0;
	while (!isEmpty())
		pop(a);
}
