/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Yoanna Yotova
* @idnumber 62359
* @task 3
* @compiler VC
*
*/


#include "pch.h"
#include <iostream>
using namespace std;

int Matrix(int matrix[][6], int M)
{

	//Checking the matrix: simplified or not simplified
	int el = 0;
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (matrix[row][col] >= 0 && matrix[row][col] <= 9) el++;
		}
	}

	if (el != 36) return -1;

	int a[10]; //New array for the digits of the number M
	int count = 0, br = 0, count1 = 0, count2 = 0;

	//Loop for the digits of the number
	do
	{
		a[count] = M % 10;
		M /= 10;
		count++;
		br++; //How many digits in the number

	} while (M != 0);
	cout << endl;

	int d = br - 1;

	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			//First case ->
			//If one element of the row is the same as the first digit of the num, check those after this element
			if (matrix[row][col] == a[d])
			{
				count1++;
				int col2 = col + 1;
				for (int i = d - 1; i >= 0 && col2 < 6; i--)
				{
					if (matrix[row][col2] == a[i]) count1++;
					col2++;
				}
			}
			if (count1 == br) count2++;
			count1 = 0;

			//Second case <-
			//If one element of the row is the same as the last digit of the num, check those after this element
			if (matrix[row][col] == a[0])
			{
				count1++;
				int col3 = col + 1;
				for (int i = 1; i <= d && col3 < 6; i++)
				{
					if (matrix[row][col3] == a[i]) count1++;
					col3++;
				}
			}
			if (count1 == br) count2++;
			count1 = 0;

			//Third case from top to bottom
			//If one element of the col is the same as the first digit of the num, check those after this element(in the column)
			if (matrix[row][col] == a[d])
			{
				count1++;
				int row2 = row + 1;
				for (int i = d - 1; i >= 0 && row2 < 6; i--)
				{
					if (matrix[row2][col] == a[i]) count1++;
					row2++;
				}
			}
			if (count1 == br) count2++;
			count1 = 0;

			//Fourth case from bottom to top
			//If one element of the col is the same as the first digit of the num, check those before this element(in the column)
			if (matrix[row][col] == a[0])
			{
				count1++;
				int row3 = row + 1;
				for (int i = 1; i <= d && row3 < 6; i++)
				{
					if (matrix[row3][col] == a[i]) count1++;
					row3++;
				}
			}
			if (count1 == br) count2++;
			count1 = 0;
		}
	}

	return count2;

}

int main()
{
	int matrix[6][6] = { 5, 4, 3, 8, 0, 6,
				 9, 4, 5, 1, 0, 2,
				 8, 5, 8, 0, 6, 1,
				 0, 9, 6, 8, 4, 2,
				 6, 1, 0, 2, 6, 1,
				 2, 1, 8, 4, 2, 6 };

	int number = 0;
	cout << "Enter a number: ";
	cin >> number;
	//print the matrix
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			cout << matrix[row][col] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	int result;
	result = Matrix(matrix, number);
	if (result == -1) cout << "The matrix is not simplified!" << endl;
	else
	{
		cout << "The matrix is simplified!" << endl;
		cout << "The count is: " << result << endl;
	}
	system("pause");
	return 0;
}
