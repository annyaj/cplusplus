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
	void push_front(int value)
	{
		elem* t = new elem(value, nullptr, nullptr);
		if (head == nullptr)
			head = tail = t;
		else
		{
			t->next = head;
			head->prev = t;
			head = t;
		}
	}

	void push_back(const int value)
	{
		elem* t = new elem(value, nullptr, nullptr);
		if (head == nullptr)
			head = tail = t;
		else
		{
			tail->next = t;
			t->prev = tail;
			tail = t;
		}
	}
	void insert_cur(const int value)
	{
		elem* t = new elem(value, nullptr, nullptr);
		if (head == nullptr)
			head = tail = t;
		else
		{
			t->next = current->next;
			current->next->prev = t;
			current->next = t;
			t->prev = current;
			current = t;
		}
	}

	bool pop_front(int& value)
	{
		if (head == nullptr)return false;
		elem* t = head;
		value = head->value;
		head = head->next;
		head->prev = nullptr;
		delete t;
		return true;
	}
	bool pop_back(int& value)
	{
		if (head == nullptr)return false;
		elem* t = tail;
		value = t->value;
		tail->prev->next = nullptr;
		tail = tail->prev;
		delete t;
		return true;
	}
	bool pop_cur(int& value)
	{
		if (head == nullptr)return false;
		value = current->value;
		elem* pc = current->prev;
		elem* nc = current->next;
		pc->next = nc;
		nc->prev = pc;
		current->prev = nullptr;
		current->next = nullptr;
		delete current;
		current = pc;
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

