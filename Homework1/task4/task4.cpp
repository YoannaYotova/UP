/**
* Solution to homework task 4
* Introduction to programming course
* Faculty of Matematics and Informatics os Sofia University
* Winter semester 2018/2019
*
*@author Yoanna Yotova
*@idnumber 62359
*@task 4
*compiler VC
*
*/

#include "pch.h"
#include <iostream>
using namespace std;

//functions to control inputs
int SafelyInputIngener(int lowerBound, int upperBound)
{
	int intNumber;
	do
	{
		cout << "Input a number: "; cin >> intNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while (intNumber <lowerBound || intNumber > upperBound);

	return intNumber;
}

//function to draw a square
void DrawSquare(int length, char symbol)
{
	int numOfRows = (2 * length) - 1; //this is the formula of the numbers of rows
	int numOfSymbols = 1;
	int numOfSpaces = 40 - numOfSymbols;//this is the formula of the number of spaces on a row
	int row;

	//this for is to return new lines before starting to draw the square in the center
	for (row = 1; row <= 14 - length; row++)
	{
		cout << endl;
	}

	//this for is about drawing the square
	for (row = 1; row <= numOfRows; row++)
	{
		//this for is o paint the spaces before the symbols
		for (int space = 1; space <= numOfSpaces; space++)
		{
			cout << " ";
		}
		//this for is to paint the symbols on the row
		for (int symbols = 1; symbols <= numOfSymbols; symbols++)
		{
			cout << symbol;
		}
		cout << endl;

		//this if is about drawing the upper part
		if (row < length)
		{
			numOfSpaces--;
			numOfSymbols += 2;
		}
		//this draw the bottom part
		else
		{
			numOfSpaces++;
			numOfSymbols -= 2;
		}
	}
	//this for is to return new lines after drawing the square in the center
	for (row = 14; row <= 25 - length; row++)
	{
		cout << endl;
	}

}

int main()
{
	int length;
	char symbol;
	//calling the function of control inputs
	length = SafelyInputIngener(1, 13);

	cout << "Enter a symbol: ";
	cin >> symbol;

	//calling the function of drawing the square
	DrawSquare(length, symbol);

	system("PAUSE");
	return 0;

}
