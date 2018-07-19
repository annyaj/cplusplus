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
	elem* tail = nullptr;
public:
	Queue()
	{
	}
	Queue(const Queue& old)
	{
		if (old.isEmpty()) return;
		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el != nullptr; el = el->next)
		{
			elem* current = new elem(el->value, nullptr);
			prev->next = current;
			prev = current;
		}
		tail = prev;
	}
	void add(const int value);
	bool pop(int& value);
	bool pop();
	bool get(int& value);
	bool isEmpty() const;
	string toString();
	~Queue();
};

