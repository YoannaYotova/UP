#pragma once
class IntStack
{
	int size;
	int capacity;
	int* elements;

	void expand();
public:
	IntStack();
	IntStack(const IntStack& cpy);
	IntStack&  operator= (const IntStack& cpy);
	~IntStack();

	int top()const;
	bool isEmpty() const;
	void add(const int& el);
	int pop();

	void print();

	friend IntStack sortStack(const IntStack& st );
};

