#include<iostream>
#include"IntStack.h"
using namespace std;

int main()
{
	IntStack arr1;
	arr1.add(7);
	arr1.add(23);
	arr1.add(5);
	arr1.add(1);
	arr1.add(14);
	arr1.add(5);
	arr1.add(23);
	arr1.add(0);
    arr1.print();
	cout << endl;

	IntStack arr2(arr1);
	arr2.add(2019);
	arr2.print();
	cout << endl;

	IntStack newStack(sortStack(arr2));
	newStack.print();
	cout << endl;

	system("pause");
	return 0;
}