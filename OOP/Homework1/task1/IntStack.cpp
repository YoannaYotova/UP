#include "IntStack.h"
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void IntStack::expand()
{
	int* temp = new int[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = elements[i];
    }
	delete[size] elements;
	elements = temp;
	capacity *= 2;
}

IntStack::IntStack(): capacity(5), size(0)
{
	elements = new int[capacity];
}
 
IntStack::IntStack(const IntStack& cpy):capacity(cpy.capacity), size(cpy.size)
{
	elements = new int[capacity];
	for (size_t i = 0; i < size; i++)
	{
		elements[i] = cpy.elements[i];
	}
}

IntStack & IntStack::operator=(const IntStack & cpy)
{
	if (this != &cpy)
	{
		delete[capacity] elements;

		capacity = cpy.capacity;
		size = cpy.size;
		 
		elements = new int[capacity];
		for (size_t i = 0; i < size; i++)
		{
			elements[i] = cpy.elements[i];
		}

	}
	return *this;
}

IntStack::~IntStack()
{
	delete[capacity] elements;
}

int IntStack::top() const
{
	return elements[size-1];
}

bool IntStack:: isEmpty() const
{
	return size == 0;
}

void IntStack::add(const int& el)
{
	if (size == capacity)
	{
		expand();
	}
	elements[size] = el;
	size++;
}

int IntStack::pop()
{
	size--;
	if (size < 0)
	{
		size = 0;
		return int();
	}
	return elements[size];
}

void IntStack::print() 
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << elements[i]<<" ";
	}
}

IntStack sortStack(const IntStack & st)
{
	IntStack result(st);
//	sort(&result.elements[0], &result.elements[result.size]);
	for (size_t i = 0; i < result.size; i++)
	{
		for (size_t j = 0; j < result.size-1; j++)
		{
			if (result.elements[j] > result.elements[j + 1])
			{
				int tmp = result.elements[j];
				result.elements[j] = result.elements[j + 1];
				result.elements[j + 1] = tmp;
			}
		}
	}
	return result;
}
