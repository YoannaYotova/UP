/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Yoanna Yotova
* @idnumber 62359
* @task 1
* @compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<math.h>
using namespace std;


void MoveEl(int Arr[], int L, int M)
{
	//second array for the new positions
	int Arr2[100];
	//if M<0 positions are the same as M=M+L and then M>0 and the movements are to right
	if (M < 0) M += L;


	/* this is a new array with the elements
	of the first one and new positions
	after moving*/
	for (int i = 0; i < L; i++)
	{
		Arr2[(i + M) % L] = Arr[i];
	}
	//this is a copy of the second array in the first one
	for (int i = 0; i < L; i++)
	{
		Arr[i] = Arr2[i];
	}
	cout << endl;


}
int main()
{
	int M = 0;
	int Arr[] = { 1, 2, 3, 4, 5 };
	const int L = 5;
	cout << "How many positions to move? ";
	cin >> M;
	if (abs(M) >= L) cout << "Error!";
	else
	{
		cout << endl;
		cout << "The array before the moving the elements: " << endl;
		for (int i = 0; i <= L - 1; i++)
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
		MoveEl(Arr, L, M);
		cout << "The array after the moving the elements: " << endl;
		for (int i = 0; i <= L - 1; i++)
		{
			cout << Arr[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
