/**
* Solution to homework task 1
* Introduction to programming course
* Faculty of Matematics and Informatics os Sofia University
* Winter semester 2018/2019
*
*@author Yoanna Yotova
*@idnumber 62359
*@task 1
*compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<math.h>
using namespace std;

//function to control inputs
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


int main()
{
	int naturalNum, min=65535, max=0, lowerbound;
	int count = 0;
    lowerbound = -pow(2, 31);

    do{
        naturalNum = SafelyInputIngener(lowerbound, 65535);
		count++;
			if (naturalNum < 0) break;
			if (naturalNum < min) min = naturalNum;
			if (naturalNum > max) max = naturalNum;
	} while (naturalNum >= 0);

	//if the input numbers are lesser than 2 this is error
	if (count <= 2)cout << "Error" << endl;
	else {
		cout << "minimum= " << min << endl;;
		cout << "maximum= " << max << endl;
		cout << "Absolute value of the | minimum - maximum | is: " << fabs(min - max) << endl;
	}
	
	system("PAUSE");
	return 0;
	
}
