#pragma once
#include <string>

using namespace std;
class Dequeue
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
	const elem* tail = new elem(4,nullptr);
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
	Dequeue() {
	
	}
	Dequeue(const Dequeue& old)
	{
		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el != old.tail; el = el->next)
		{
			elem* current = new elem(el->value,nullptr);
			prev->next = current;
			prev = current;
		}
		
	}
	void push_back(const int value);
	void push_front(const int value);
	bool pop_back(int& value);
	bool pop_front(int& value);
	bool get(int& value);
	bool isEmpty();
	iterator& begin();
	iterator& end();
	string toString();
	~Dequeue();
};

