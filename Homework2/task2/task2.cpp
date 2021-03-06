/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Yoanna Yotova
* @idnumber 62359
* @task 2
* @compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<string.h>

using namespace std;

void MaxString(char B[100], char C[100])
{
	int count = 0;
	int maxLenght = 0;
	int index = -1;

	for (int i = 0; i < strlen(B); i++)
	{
		int f = 0;
		if (B[i] == C[f])
		{
			count = 0;
			int i2 = i + 1;
			f++;
			for (f = 1; f < strlen(B) && i2 < strlen(B); f++) //new loop for searching the string C in string B
			{
				//if there is no elements in sting C start from the first (and count one)
				if (f >= strlen(C))
				{
					f = 0;
					count++;
				}
				//if there is a same element in B like in C check the next element in B
				if (B[i2] == C[f])
				{
					i2++;
				}
				else
				{
					break;
				}

			}
		}
		if (f >= strlen(C)) count++;
		//if the count is bigger the local max lenght then the max lenght is new
		// and the index is where it starts
		if (count > maxLenght)
		{
			maxLenght = count;
			index = i;
		}
	}
	cout << "Max Lenght: " << maxLenght * strlen(C) << endl; //the number of th elements in the biggest substring
	cout << "Index: " << index << endl;
}


int main()
{
	char B[100];
	char C[100];
	cout << "Enter the first string: ";
	cin >> B;
	cout << endl;
	cout << "Enter the second string: ";
	cin >> C;
	cout << endl;
	MaxString(B, C);
	system("pause");
	return 0;
}