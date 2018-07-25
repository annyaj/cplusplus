#include "stdafx.h"
#include "Stack.h"




void Stack::add(const int value)
{
	
	if (root == nullptr)
	{
		elem* t = new elem(value,tail);
		root = t;
	}
	else
	{
		elem* a = new elem(value,root);
		root = a;
	}
}

bool Stack::pop(int& value)
{
	if (root==tail) return false;
	elem* t = root;
	value = root->value;
	root = root->next;
	delete t;
	return true;

}
bool Stack::pop()
{
	if (root == tail)return false;
	elem* t = root;
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

bool Stack::isEmpty()const
{

	return root==tail;
}

Stack::iterator& Stack::end()
{
	iterator* e = new iterator(tail);
	return *e;
}

Stack::iterator& Stack::begin()
{
	iterator* h = new iterator(root);
	return *h;
}


string Stack::toString()
{
	string s = "";
	elem* n = root;
	for (; n->next!= tail; n = n->next)
	{
		s += to_string(n->value);
		s += " ";
	}
	s += to_string(n->value);
	return s;
}

Stack::~Stack()
{
	while (!isEmpty())
		pop();
}
