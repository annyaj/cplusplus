#include "stdafx.h"
#include "Stack.h"



void Stack::reverse(const Stack & old, Stack& rev)
{
	if (old.isEmpty())return;
	Stack copy(old);
	while (!copy.isEmpty())
	{
		int value = 0;
		copy.pop(value);
		rev.add(value);
	}
}

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
bool Stack::pop()
{
	if (root == nullptr)return false;
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
	while (!isEmpty())
		pop();
}
