/**
*
* Solution to homework assignment 3
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
#include <windows.h>

using namespace std;

//What means each digit and print it
void printLetter(int intLetter) {
	switch (intLetter) {
	case 0:
		cout << " ";
		break;
	case 1:
		cout << "H";
		break;
	case 2:
		cout << "E";
		break;
	case 3:
		cout << "L";
		break;
	case 4:
		cout << "O";
		break;
	}
}

//Print HELLO without animation
void printMatrix(int matrix[5][40], int startCol, int endCol, int space)
{
	//to be in the center of console with 25 rows
	for (int row = 0; row < 11; row++)
	{
		cout << endl;
	}

	for (int row = 0; row < 5; row++)
	{
		for (int i = 0; i <= space; i++)
		{
			cout << " ";
		}
		for (int col = startCol; col <= endCol; col++)
		{
			printLetter(matrix[row][col]);
		}
		cout << endl;
	}
}

//Animate HELLO
void animate(int matrix[][40])
{
	int col = 39;
	while (col >= 0)
	{
		printMatrix(matrix, col, 39, 0);
		col--;
		Sleep(1);
		system("CLS");
	}
	int space = 1;
	int endcol = 39;
	while (space <= 80)
	{
		printMatrix(matrix, 0, endcol, space);
		space++;
		if (space > 40) endcol--;
		Sleep(1);
		system("CLS");
	}
}

int main()
{
	int matrix[5][40] = {
		{0,1, 0, 0, 0, 1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
		{0,1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0},
		{0,1, 1, 1, 1, 1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 4},
		{0,1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0},
		{0,1, 0, 0, 0, 1, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 3, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
	};

	animate(matrix);
	system("pause");
	return 0;
}
