/**
* Solution to homework task 3
* Introduction to programming course
* Faculty of Matematics and Informatics os Sofia University
* Winter semester 2018/2019
*
*@author Yoanna Yotova
*@idnumber 62359
*@task 3
*compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<math.h>
using namespace std;

/*
function to control inputs for the first number;
continue when the input number is a string or a number
that is not in the interval
*/
double SafelyInputIngener1(double lowerBound1, double upperBound1)
{
	double intNumber1;
	do
	{
		cout << "Input the first number: "; cin >> intNumber1;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (intNumber1 == 0)break;
		if (intNumber1 < 0) break;
	} while (intNumber1 < lowerBound1 || intNumber1 > upperBound1);

	return intNumber1;
}


//functions to control inputs for the first number
double SafelyInputIngener2(double lowerBound2, double upperBound2)
{
	double intNumber2;
	do
	{
		cout << "Input the second number: "; cin >> intNumber2;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (intNumber2 == 0) break;
		if (intNumber2 < 0)  break;
	} while (intNumber2 < lowerBound2 || intNumber2 > upperBound2);

	return intNumber2;
}



int main()
{

	int addition = 0, subtraction = 0, multiplication = 1, division = 1, operation;
	double numberone = 0, numbertwo = 0;
	//calling the functions about the first and the second number
	numberone = SafelyInputIngener1(1, pow(2, 31) - 1);
	numbertwo = SafelyInputIngener2(1, pow(2, 31) - 1);

	cout << "Enter a operation: \n";
	cout << "'0' for addition \n";
	cout << "'1' for subtraction \n";
	cout << "'2' for multiplication \n";
	cout << "'3' for division \n";
	cin >> operation;

	//checking which operation we choose
	switch (operation)
	{
		//addition
	case 0: {
		if ((numberone >= 0 && numberone <= 15) && (numbertwo >= 0 && numbertwo <= 15)) {

			addition = numberone + numbertwo;
			if (addition >= 16) addition = addition % 16; //turnning into 4 bites
			cout << numberone << " + " << numbertwo << " = " << addition << endl;

		}
		else cout << "Wrong input!" << endl;
	}
			break;
			//subtraction
	case 1: {
		if ((numberone >= 0 && numberone <= 15) && (numbertwo >= 0 && numbertwo <= 15)) {
			subtraction = numberone - numbertwo;
			if (subtraction < 0) subtraction = (subtraction + 16) % 16; //turnning into 4 bites
			cout << numberone << " - " << numbertwo << " = " << subtraction << endl;
		}
		else cout << "Wrong input!" << endl;
	}
			break;
			//multiplication
	case 2: {
		if ((numberone >= 0 && numberone <= 15) && (numbertwo >= 0 && numbertwo <= 15)) {

			multiplication = numberone * numbertwo;
			if (multiplication >= 16) multiplication = multiplication % 16; //turnning into 4 bites
			cout << numberone << " * " << numbertwo << " = " << multiplication << endl;

		}
		else cout << "Wrong input!" << endl;
	}
			break;
			//division
	case 3: {
		if ((numberone >= 0 && numberone <= 15) && (numbertwo > 0 && numbertwo <= 15)) {

			division = numberone / numbertwo;
			if (division >= 16) division = division % 16; //prevrushtane v 4 bitovo chislo
			cout << numberone << " / " << numbertwo << " = " << numberone / numbertwo << endl;

		}
		else if (numbertwo == 0)  cout << "It is impossible!" << endl;
		else cout << "Wrong input!" << endl;
	} break;
		//when we input a wrong operation
	default:cout << "Wrong operation!" << endl; break;
	}

	system("PAUSE");

	return 0;
}
