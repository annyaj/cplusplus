#pragma once
#include <string>

using namespace std;
class Dlist
{
	struct elem
	{
		int value = 0;
		elem* prev = nullptr;
		elem* next = nullptr;
		elem() {}
		elem(int value, elem* prev, elem* next) {
			this->value = value;
			this->prev = prev;
			this->next = next;
		}

	};
	elem* head = nullptr;
	elem* tail = nullptr;
	elem* current = nullptr;
public:

	Dlist()
	{
	};
	Dlist(const Dlist& old)
	{
		head = new elem(old.head->value, nullptr, nullptr);
		elem* prev  = head;
		for (elem* el = old.head->next; el != nullptr; el = el->next)
		{
			elem* current = new elem(el->value,prev,nullptr);
			prev->next = current;
			prev = current;
		}
		tail = prev;
	}
	void push(const int value)
	{
		elem* t = new elem(value, nullptr, nullptr);
		if (head == nullptr)
		{
			head = tail = t;
			current = t;
		}
		else if (current->next!=nullptr)
		{
			t->next = current->next;
			current->next->prev = t;
			current->next = t;
			t->prev = current;
			current = t;
		}
		else
		{
			current->next = t;
			t->prev = current;
			current = t->prev;
		}
	}


	bool pop(int& value)
	{
		if (head == nullptr)return false;
		value = current->value;
		if (current == head)
		{
			if (head->next != nullptr)
			{
				head = head->next;
				delete current;
				current = head;
			}
			else
			{
				delete current;
				head = tail= nullptr;
				current = nullptr;
			}
		}
		else if (current->next== nullptr)
		{
			tail=tail->prev;
			delete current;
			current = tail;
		}
		else
		{
			
			elem* pc = current->prev;
			elem* nc = current->next;
			pc->next = nc;
			nc->prev = pc;
			delete current;
			current = pc;
		}

		return true;
	}
	int get()
	{
		return (current->value);
	}
	bool isEmpty()
	{
		return (head == nullptr);
	}
	string toStr()
	{
		string s = "";
		elem* t = head;
		for (; t->next != nullptr; t = t->next)
		{
			s += to_string(t->value);
			s += " ";
		}
		s += to_string(t->value);
		return s;
	}

	~Dlist();
};

