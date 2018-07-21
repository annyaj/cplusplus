#pragma once
#include <string>
#include "SortOrder.h"

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
	void set_begin()
	{
		current = head;
	}
	bool is_begin()
	{
		return current == head;
	}

	void next()
	{
		current = current->next;
	}
	void prev()
	{
		current = current->prev;

	}
	bool end()const
	{
		return (current == nullptr);
	}
	void sort(SortOrder order)
	{
		if (head == nullptr || head->next == nullptr)return;
		bool flag = true;
		current = head->next;
		do
		{
			flag = true;
			for (current = head->next; !end(); current = current->next)
			{
				if (order == SortOrder::Ascending)
				{
					if (current->value < current->prev->value)
					{
						swap(current->value, current->prev->value);
						flag = false;
					}
				}
				else
				{
					if (current->value > current->prev->value)
					{
						swap(current->value, current->prev->value);
						flag = false;
					}

				}
			}
			if (flag)break;
		} while (!flag);
	}
	void rev()
	{
		elem* pr = nullptr;
		elem* nx = nullptr;
		current = head;
		while (current->next!= nullptr)
		{
			pr = current->prev;
			nx = current->next;
			current->prev = nx;
			current->next = pr;
			current = nx;
		}current->next = current->prev;
		head = current;
	}
	~Dlist();
};

