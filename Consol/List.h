#pragma once
#include <string>

using namespace std;

class List
{
	struct elem
	{
		int value;
		elem* next;
	};
	elem* root;
	elem* current;

public:
	List()
	{
		root = nullptr;
		current = nullptr;
	}
	void add(int value);
	int pop();
	int get();
	bool isEmpty();
	string toString();
	void begin();
	void next();
	bool end();

	~List();
};

