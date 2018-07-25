#include "stdafx.h"
#include "List.h"



void List::rev()
{
	current = root;
	elem* prev = nullptr;
	elem* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	root = prev;
}

void List::add(int value)
{
	if (root == nullptr)
	{
		elem* t = new elem(value,tail);
		root = t;
		current = t;
	}
	else if (current->next != nullptr)
	{
		elem* a = new elem(value, nullptr);
		a ->next = current->next;
		current ->next = a;
		current = a;
	}
	else
	{
		elem* t = new elem(value, tail);
		current->next = t;
		current = t;
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
	else if (current->next == tail)
	{
		elem* t = root;
		while (t->next != current)
		{
			t = t->next;
		}
		delete current;
		t->next = tail;
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

int List::get()
{

	return current->value;
}


bool List::isEmpty()
{
	
	return root==nullptr;
}

string List::toString()
{
	string ss = "";
	for (current=root; current!=tail; current=current->next)
	{
		ss +=to_string(current->value);
		ss += " ";
	}
	return ss;
}

List::iterator& List::begin()
{
	iterator* b = new iterator(root);
	return *b;
}

void List::next()
{
	current = current->next;
}

List::iterator& List::end()
{
	iterator* e=new iterator(tail);
	return *e;
}

void List::sort(SortOrder order)
{
	if (root == nullptr || root->next == nullptr)return;
	elem* t = root;
	current = root->next;
	bool flag = true;
	do
	{
		flag = true;
		t = root;
		current = root->next;
		for (; current!=tail; t = t->next, current = current->next)
		{
			if (order == SortOrder::Ascending)
			{
				if (t->value > current->value) {
					swap(t->value, current->value);
					flag = false;
				}
			}
			else
			{
				if (t->value < current->value)
				{
					swap(t->value, current->value);
					flag = false;
				}
			}
		}
		if (flag) break;
	} while (!flag);
}

List::~List()
{
}
