/**
* Solution to homework task 5
* Introduction to programming course
* Faculty of Matematics and Informatics os Sofia University
* Winter semester 2018/2019
*
*@author Yoanna Yotova
*@idnumber 62359
*@task 5
*compiler VC
*
*/

#include "pch.h"
#include <iostream>
#include<math.h>
using namespace std;

/*function for calculatingthe distance from the center of circle
with coordinats (0,3) and (0,-3) to the point of coordinate we choose
*/
double distance(double x, double y)
{
	double dist;
	int x1 = 0, y1 = 0;

	if (y > 0) y1 = 3;
	if (y < 0)y1 = -3;
	dist = sqrt(pow(x - x1, 2) + pow(y - y1, 2));

	return dist;
}


int main()
{
	double a, b, theDistance;
	cout << "Enter the x: "; cin >> a;
	cout << "Enter the y: "; cin >> b;

	//calling the function about the distance
	theDistance = distance(a, b);

	//if the point is on the ordinate
	if (a == 0) {
		if (b == 0 || b == 2 || b == 4 || b == -2 || b == -4 || b == 6 || b == -6)cout << "Undifined" << endl;
		else if (b > 2 && b < 4) cout << "Black" << endl;
		else if (b <-2 && b > -4)cout << "White" << endl;
		else if (b < -6 || b > 6) cout << "Outside" << endl;
	}

	//if the point is on the abscissa
	if (b == 0) {
		if (a == 0 || a == 6 || a == -6)cout << "Undifined" << endl;
		else if (a > 0 && a < 6) cout << "Black" << endl;
		else if (a < 0 && a > -6)cout << "White" << endl;
		else if (a < -6 || a > 6) cout << "Outside" << endl;
	}


	//first quadrant
	if (a > 0 && b > 0) {
		if (theDistance == 1 || theDistance == 3) cout << "Undefined" << endl;
		else if (theDistance > 0 && theDistance < 1) cout << "Black" << endl;
		else if (theDistance > 1 && theDistance < 3) cout << "White" << endl;
		else if (theDistance > 3 && theDistance < 6) cout << "Black" << endl;
		else if (theDistance > 6)cout << "Outside" << endl;
	}
	//second quadrant
	if (a < 0 && b > 0) {
		if (theDistance == 1) cout << "Undefined" << endl;
		else if (theDistance > 0 && theDistance < 1) cout << "Black" << endl;
		else if (theDistance > 1 && theDistance < 6) cout << "White" << endl;
		else if (theDistance > 6)cout << "Outside" << endl;
	}
	//third quadrant
	if (a < 0 && b < 0) {
		if (theDistance == 1 || theDistance == 3) cout << "Undefined" << endl;
		else if (theDistance > 0 && theDistance < 1) cout << "White" << endl;
		else if (theDistance > 1 && theDistance < 3) cout << "Black" << endl;
		else if (theDistance > 3 && theDistance < 6) cout << "White" << endl;
		else if (theDistance > 6)cout << "Outside" << endl;
	}
	//fourth quadrant
	if (a > 0 && b < 0) {
		if (theDistance == 1) cout << "Undefined" << endl;
		else if (theDistance > 0 && theDistance < 1) cout << "White" << endl;
		else if (theDistance > 1 && theDistance < 6) cout << "Black" << endl;
		else if (theDistance > 6)cout << "Outside" << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
