/**
* Solution to homework task 2
* Introduction to programming course
* Faculty of Matematics and Informatics os Sofia University
* Winter semester 2018/2019
*
*@author Yoanna Yotova
*@idnumber 62359
*@task 2
*@compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<math.h>
using namespace std;

//function to control inputs for the number
long long SafelyInputIngener1(long long lowerNum, long long upperNum)
{
	long long longNumber;
	do
	{
		cout << "Input a number: "; cin >> longNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (longNumber > lowerNum && longNumber < upperNum) break;
	} while (!cin.fail());

	return longNumber;
}

//function to control inputs for the digits
int SafelyInputIngener2(int lowerIngener, int upperIngener)
{
	int intDigit;
	do
	{
		cout << "Input a digit: "; cin >> intDigit;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (intDigit == 0) break;
	} while (intDigit < lowerIngener || intDigit > upperIngener);

	return intDigit;
}

int main()
{
	long long number, lowernum, uppernum;
	int digit, digitofnum, count = 0;

	lowernum = -pow(2, 32);
	uppernum = pow(2, 32) - 1;

	number = SafelyInputIngener1(lowernum, uppernum);
	digit = SafelyInputIngener2(1, 9);

	do {

		digitofnum = number % 10;      //finding the last digit
		number = number / 10;          //remove the last digit from the number

		if (digitofnum == digit)count++;

	} while (number != 0);

	if (count == 0) cout << "This digit is not in the number!" << endl;
	else cout << "The count of the digit in this number is: " << count << endl;

	system("PAUSE");

	return 0;
}
