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
	elem* tail = new elem(0,nullptr,nullptr);
	elem* current = nullptr;
public:
	class iterator
	{
		elem* cur = nullptr;

	public:
		iterator() {}
		iterator(elem* cur)
		{
			this->cur = cur;
		}
		bool operator==(iterator& it) {
			return cur == it.cur;
		}
		bool operator!= (iterator& it)
		{
			return cur != it.cur;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator(iterator& it)
		{
			cur = it.cur;
		}
		iterator& operator=(iterator& it)
		{
			cur = it.cur;
			return *this;
		}
		int operator*()
		{
			return 	cur->value;
		}
	};

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
	}
	void push(const int value)
	{
		
		if (head == nullptr)
		{
			elem* h = new elem(value, nullptr, tail);
			head = h;
			current = h;
		}
		else if (current->next!=nullptr)
		{
			elem* t = new elem(value, nullptr, nullptr);
			t->next = current->next;
			current->next->prev = t;
			current->next = t;
			t->prev = current;
			current = t;
		}
		else
		{
			elem* h = new elem(value, current, tail);
			current->next = h;
			current = h->prev;
		}
	}


	bool pop(int& value)
	{
		if (head == tail)return false;
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
				head= nullptr;
				current = nullptr;
			}
		}
		else if (current->next== tail)
		{
			tail->prev = current->prev;
			current->prev->next = tail;
			delete current;
			current = current->prev;
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
		return (head == tail);
	}
	string toStr()
	{
		string s = "";
		elem* t = head;
		for (; t!= tail; t = t->next)
		{
			s += to_string(t->value);
			s += " ";
		}
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
	iterator& begin()
	{
		iterator* b = new iterator(head);
		return *b;
	}
	iterator& end()
	{
		iterator* e = new iterator(tail);
		return *e;
	}

	void next()
	{
		current = current->next;
	}
	void prev()
	{
		current = current->prev;

	}
	bool is_end()const
	{
		return (current == tail);
	}
	void sort(SortOrder order)
	{
		if (head == tail || head->next == tail)return;
		bool flag = true;
		current = head->next;
		do
		{
			flag = true;
			for (current = head->next; !is_end(); current = current->next)
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
		while (current->next!= tail)
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

