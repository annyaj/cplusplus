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
	elem* tail = nullptr;
public:
	Dequeue();
	Dequeue(const Dequeue& old)
	{
		root = new elem(old.root->value, nullptr);
		elem* prev = root;
		for (elem* el = old.root->next; el != nullptr; el = el->next)
		{
			elem* current = new elem(el->value,nullptr);
			prev->next = current;
			prev = current;
		}
		tail = prev;
	}
	void push_back(const int value);
	void push_front(const int value);
	bool pop_back(int& value);
	bool pop_front(int& value);
	bool get(int& value);
	bool isEmpty();
	string toString();
	~Dequeue();
};

