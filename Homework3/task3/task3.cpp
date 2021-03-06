/**
*
* Solution to homework assignment 3
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
#include <iomanip>
#include<algorithm>
using namespace std;

//Function to write a matrix
void Write(int p, double matrixprint[][4])
{
	for (int row = 0; row < p; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			cout << matrixprint[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//Matrix1 appropriate matrix2 
void Appropriation(int k, double matrix1[][4], double matrix2[][4])
{
	for (int row = 0; row < k; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			matrix1[row][col] = matrix2[row][col];
		}
	}

}

//Function for basis using the method of Gaus
void Basis(const int n, double matrixA[][4], double BasisOfMatrixA[][4])
{
	double matrixU[10][4], c = 0;
	double matrixU1[10][4];
	double matrixU2[10][4];
	double matrixU3[10][4];

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			//First element of the main diagonal
			if (row == 0 && col == 0 && matrixA[row][col] != 0)
			{
				c = matrixA[row][col];
				for (int col1 = 0; col1 < 4; col1++)
				{
					matrixU[row][col1] = matrixA[row][col1];
				}
				int row1 = 0;
				while (row1 < n)
				{
					for (int col2 = 0; col2 < 4 && row1 != row; col2++)
					{
						matrixU[row1][col2] = matrixA[row][col2] * (-1)*(matrixA[row1][col] / c) + matrixA[row1][col2];
					}
					row1++;
				}
			}
			//if it is 0 the row is same
			else if (row == 0 && col == 0 && matrixA[row][col] == 0)
				for (int row0 = 0; row0 < n; row0++)
				{
					for (int col0 = 0; col0 < 4; col0++)
					{
						matrixU[row0][col0] = matrixA[row0][col0];
					}
				}
			//Second element of the main diagonal
			if (row == 1 && col == 1 && matrixU[row][col] != 0)
			{
				c = matrixU[row][col];
				for (int col1 = 0; col1 < 4; col1++)
				{
					matrixU1[row][col1] = matrixU[row][col1];
				}
				int row1 = 0;
				while (row1 < n)
				{
					for (int col2 = 0; col2 < 4 && row1 != row; col2++)
					{
						matrixU1[row1][col2] = matrixU[row][col2] * (-1)*(matrixU[row1][col] / c) + matrixU[row1][col2];
					}
					row1++;
				}
			}
			//if it is 0 the row is same
			else if (row == 1 && col == 1 && matrixU[row][col] == 0)
				for (int row1 = 0; row1 < n; row1++)
				{
					for (int col1 = 0; col1 < 4; col1++)
					{
						matrixU1[row1][col1] = matrixU[row1][col1];
					}
				}
			//Third element of the main diagonal
			if (row == 2 && col == 2 && matrixU1[row][col] != 0)
			{
				c = matrixU1[row][col];
				for (int col1 = 0; col1 < 4; col1++)
				{
					matrixU2[row][col1] = matrixU1[row][col1];
				}
				int row1 = 0;
				while (row1 < n)
				{
					for (int col2 = 0; col2 < 4 && row1 != row; col2++)
					{
						matrixU2[row1][col2] = matrixU1[row][col2] * (-1)*(matrixU1[row1][col] / c) + matrixU1[row1][col2];
					}
					row1++;
				}
			}
			//if it is 0 the row is same
			else if (row == 2 && col == 2 && matrixU1[row][col] == 0)
				for (int row2 = 0; row2 < n; row2++)
				{
					for (int col2 = 0; col2 < 4; col2++)
					{
						matrixU2[row2][col2] = matrixU1[row2][col2];
					}
				}
			//Fourth element of the main diagonal
			if (row == 3 && col == 3 && matrixU2[row][col] != 0)
			{
				c = matrixU2[row][col];
				for (int col1 = 0; col1 < 4; col1++)
				{
					matrixU3[row][col1] = matrixU2[row][col1];
				}
				int row1 = 0;
				while (row1 < n)
				{
					for (int col2 = 0; col2 < 4 && row1 != row; col2++)
					{
						matrixU3[row1][col2] = matrixU2[row][col2] * (-1)*(matrixU2[row1][col] / c) + matrixU2[row1][col2];
					}
					row1++;
				}
			}
			//if it is 0 the row is same
			else if (row == 3 && col == 3 && matrixU2[row][col] == 0)
				for (int row3 = 0; row3 < n; row3++)
				{
					for (int col3 = 0; col3 < 4; col3++)
					{
						matrixU3[row3][col3] = matrixU2[row3][col3];
					}
				}
		}
	}
	double matrixBasisA[10][4];
	switch (n)
	{
	case 1: Appropriation(n, matrixBasisA, matrixU); break;
	case 2: Appropriation(n, matrixBasisA, matrixU1); break;
	case 3:	Appropriation(n, matrixBasisA, matrixU2); break;
	}
	if (n >= 4) Appropriation(n, matrixBasisA, matrixU3);
	Appropriation(n, BasisOfMatrixA, matrixBasisA);
}

//Function to swap the rows in matrix B if on the main diagonal is 0
void Swap(int m, double matrixB[][4])
{
	for (int col = 0; col < m && col < 4; col++)
	{
		int row = col;
		if (matrixB[col][col] != 0)
		{
			continue;
		}

		int rowToSwap = col + 1;
		bool isFoundRowToSwap = false;
		while (rowToSwap < m)
		{
			if (matrixB[rowToSwap][col] != 0)
			{
				isFoundRowToSwap = true;
				break;
			}
			rowToSwap++;
		}
		if (isFoundRowToSwap)
		{
			for (int colToSwap = 0; colToSwap < 4; colToSwap++)
			{
				swap(matrixB[rowToSwap][colToSwap], matrixB[row][colToSwap]);
			}
		}
	}
}

//Making the elements of the main diagonal 1 
void ProcessMainDiaganol(double matrixB[][4], int m)
{
	for (int mainDiagonalPosition = 0; mainDiagonalPosition < 4 && mainDiagonalPosition < m; mainDiagonalPosition++)
	{
		if (matrixB[mainDiagonalPosition][mainDiagonalPosition] != 1 &&
			matrixB[mainDiagonalPosition][mainDiagonalPosition] != 0)
		{
			int row = mainDiagonalPosition;
			double divider = matrixB[mainDiagonalPosition][mainDiagonalPosition];
			for (int col = 0; col < 4; col++)
			{
				matrixB[row][col] = matrixB[row][col] / divider;
			}
		}
	}
}

void Solution(int m, double matrixBasisB[][4])
{
	bool pivot0 = false;
	bool pivot1 = false;
	bool pivot2 = false;
	bool pivot3 = false;
	int br0 = 0;
	int br1 = 0;
	int br2 = 0;
	int br3 = 0;
	int col0 = 0, col1 = 0, col2 = 0, col3 = 0;

	for (int row = 0; row < m; row++)
	{
		//is there an element that we used for Gaus
		//if it is yes so pivot0 is true
		if (row == 0)
		{
			while (col0 < 4)
			{
				if (matrixBasisB[row][col0] == 1)
				{
					pivot0 = true;
					break;
				}
				col0++;
			}
		}
		//is there an element that we used for Gaus
		//if it is yes so pivot1 is true
		if (row == 1)
		{
			while (col1 < 4)
			{
				if (matrixBasisB[row][col1] == 1)
				{
					pivot1 = true;
					break;
				}
				col1++;
			}
		}
		//is there an element that we used for Gaus
		//if it is yes so pivot2 is true
		if (row == 2)
		{
			while (col2 < 4)
			{
				if (matrixBasisB[row][col2] == 1)
				{
					pivot2 = true;
					break;
				}
				col2++;
			}
		}
		//is there an element that we used for Gaus
		//if it is yes so pivot3 is true
		if (row == 3)
		{
			while (col3 < 4)
			{
				if (matrixBasisB[row][col3] == 1)
				{
					pivot3 = true;
					break;
				}
				col3++;
			}
		}
	}
	int br = 0;
	//how many are the columns where we do not use an element
	if (pivot0 == false) br++;
	if (pivot1 == false) br++;
	if (pivot2 == false) br++;
	if (pivot3 == false) br++;

	bool isThereOne0 = false, isThereOne1 = false, isThereOne2 = false, isThereOne3 = false;

	double newMatrixBasisB[10][4];
	//Parameterization
	for (int row = 0; row < br; row++)
	{
		for (int col = 0; col < 4; col++)
		{

			if (col == 0 && pivot0 == true)
			{
				int row0 = 0;
				int col0 = row + br;
				newMatrixBasisB[row][col] = (-1)*matrixBasisB[row0][col0];
				col++;
			}
			else if (isThereOne0) col++;
			else
			{
				newMatrixBasisB[row][col] = 1;
				//Make the elemenets 0 after the 1 (on the same row)
				for (int newCol0 = col + 1; newCol0 < 4; newCol0++)
				{
					newMatrixBasisB[row][newCol0] = 0;
				}
				//Make the elements 0 under the 1 (in the same column)
				for (int newRow0 = row + 1; newRow0 < br; newRow0++)
				{
					for (int colUnder0 = col; colUnder0 < 1; colUnder0++)
					{
						newMatrixBasisB[newRow0][colUnder0] = 0;
					}

				}
				isThereOne0 = true;
				break;
			}
			if (col == 1 && pivot1 == true)
			{
				int row1 = 1;
				int col1 = row + br;
				newMatrixBasisB[row][col] = (-1)*matrixBasisB[row1][col1];
				col++;
			}
			else if (isThereOne1) col++;
			else
			{
				newMatrixBasisB[row][col] = 1;
				//Make the elemenets 0 after the 1 (on the same row)
				for (int newCol1 = col + 1; newCol1 < 4; newCol1++)
				{
					newMatrixBasisB[row][newCol1] = 0;
				}
				//Make the elements 0 under the 1 (in the same column)
				for (int newRow1 = row + 1; newRow1 < br; newRow1++)
				{
					for (int colUnder1 = col; colUnder1 < 1; colUnder1++)
					{
						newMatrixBasisB[newRow1][colUnder1] = 0;
					}

				}
				isThereOne1 = true;
				break;
			}
			if (col == 2 && pivot2 == true)
			{
				int row2 = 2;
				int col2 = row + br;
				newMatrixBasisB[row][col] = (-1)*matrixBasisB[row2][col2];
				col++;
			}
			else if (isThereOne2) col++;
			else
			{
				newMatrixBasisB[row][col] = 1;
				//Make the elemenets 0 after the 1 (on the same row)
				for (int newCol2 = col + 1; newCol2 < 4; newCol2++)
				{
					newMatrixBasisB[row][newCol2] = 0;
				}
				//Make the elements 0 under the 1 (in the same column)
				for (int newRow2 = row + 1; newRow2 < br; newRow2++)
				{
					for (int colUnder2 = col; colUnder2 < 4; colUnder2++)
					{
						newMatrixBasisB[newRow2][colUnder2] = 0;
					}

				}
				isThereOne2 = true;
				break;
			}
			if (col == 3 && pivot3 == true)
			{
				int row3 = 3;
				int col3 = row + br;
				newMatrixBasisB[row][col] = (-1)*matrixBasisB[row3][col3];
				col++;
			}
			else if (isThereOne3) col++;
			else
			{
				newMatrixBasisB[row][col] = 1;
				//Make the elemenets 0 after the 1 (on the same row)
				for (int newCol3 = col + 1; newCol3 < 4; newCol3++)
				{
					newMatrixBasisB[row][newCol3] = 0;
				}
				//Make the elements 0 under the 1 (in the same column)
				for (int newRow3 = row + 1; newRow3 < br; newRow3++)
				{
					for (int colUnder3 = col; colUnder3 < 1; colUnder3++)
					{
						newMatrixBasisB[newRow3][colUnder3] = 0;
					}

				}
				isThereOne3 = true;
				break;
			}

		}
	}
	Appropriation(br, matrixBasisB, newMatrixBasisB);
}

void TheBasisUW(int n, int m, double matrixUW[][4], double matrixBasisA[][4], double matrixBasisB[][4])
{
	for (int row = 0; row < n + m; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			for (row = 0; row < n; row++)
			{
				matrixUW[row][col] = matrixBasisA[row][col];
			}
			int newRowA = 0;
			for (row = n; row < n + m; row++)
			{
				matrixUW[row][col] = matrixBasisB[newRowA][col];
				newRowA++;
			}
		}
	}
}

int main()
{
	const int m = 2; //rows for b
	const int n = 4; //rows for a
	double matrixA[4][4] = { 2, 8, -3, 14,
	-1, 2, 3, 5,
	-1, 14, 6, 29 ,
	0., 12., 3., 24. };
	double matrixB[2][4] = { 0., 1., 1., 0.,
	10., 7., 0., -8. };

	double matrixBasisA[n][4];
	Basis(n, matrixA, matrixBasisA);
	cout << "Basis of MatrixA: " << endl;
	Write(n, matrixBasisA);

	Swap(m, matrixB);
	//Write(m, matrixB);
	ProcessMainDiaganol(matrixB, m);
	//Write(m, matrixB);

	double matrixBasisB[m][4];
	Basis(m, matrixB, matrixBasisB);
	cout << "Basis of MatrixB: " << endl;
	Write(m, matrixBasisB);

	Solution(m, matrixBasisB);
	//Write(m, matrixBasisB);

	double matrixUW[m + n][4];
	TheBasisUW(n, m, matrixUW, matrixBasisA, matrixBasisB);
	//Write(m + n, matrixUW);

	double matrixBasisUW[n + m][4];
	Basis(m + n, matrixUW, matrixBasisUW);
	cout << "Basis of U + W (without the rows with '0'):  " << endl;
	Write(m + n, matrixBasisUW);

	system("pause");
	return 0;
}
