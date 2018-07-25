#pragma once
#include <string>

using namespace std;
class Queue
{
	struct elem
	{
		int value = 0;
		elem* next = nullptr;
		elem() {}
		elem(int value, elem* next) {
			this->value = value;
			this->next = next;
		}
	};
	elem* root = nullptr;
	elem* tail = new elem(0,nullptr);
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
		iterator(iterator& it)
		{
			cur = it.cur;
		}
		bool operator==(iterator& it)
		{
			return cur == it.cur;
		}
		bool operator !=(iterator& it)
		{
			return cur != it.cur;
		}
		iterator& operator++()
		{
			cur = cur->next;
			return *this;
		}
		iterator& operator=(iterator& it)
		{
			cur = it.cur;
			return *this;
		}
		int operator*()
		{
			return cur->value;
		}
	};
	Queue()
	{
	}
	Queue(const Queue& old)
	{
		if (old.isEmpty()) return;
		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el != old.tail; el = el->next)
		{
			elem* current = new elem(el->value, nullptr);
			prev->next = current;
			prev = current;
		}
	}
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty() const;
	iterator& begin();
	iterator& end();
	string toString();
	~Queue();
};

