/*	File: part_3.cpp
 *	Author: Daric Niclas
 *	Date: 12/3/19
 *	Purpose:
 */

#include <stdio.h>
#include <iomanip>
#include <iostream>

using namespace std;

bool matrixMultiply(float*, float*, float*, int, int, int, int);

int main()
{
	float arr_A[5][3], arr_B[3] = {1, 2, 3}, arr_C[5];
	
	// init arr_A, row-by-row, values 2 to 30
	for (int row = 0; row < 5; row++) {
		static int num = 2;
		for (int col = 0; col < 3; col++) {
			arr_A[row][col] = num;
			num += 2;
		}
	}
	
	bool success = matrixMultiply((float*)arr_A, arr_B, arr_C, 5, 3, 3, 1);

	if (success) {	// if the operation was successful...
		cout << "MTRX_A:" << endl;
		for (int row = 0; row < 5; row++) {
			for (int col = 0; col < 3; col++) {
				cout << setw(5) << arr_A[row][col];
			}
			cout << endl;
		} cout << endl << endl;


		cout << "MTRX_B:" << endl;
		for (int row = 0; row < 3; row++) {
			cout << setw(5) << arr_B[row];
		} cout << endl << endl << endl;


		cout << "PRODUCT:" << endl;
		for (int row = 0; row < 5; row++) {
			 cout << setw(5) << arr_C[row];
		} cout << endl << endl;
	}
	
	return 0;	// end
}

// was going to make this work for every potential matrix operation, but ran out of time the day it was due
// TODO: assign final values to arr_C correctly
bool matrixMultiply(float *arr_A, float *arr_B, float *arr_C, int row_A, int col_A, int row_B, int col_B) {	
	if (col_A != row_B) {
		printf("Attempted invalid matrix operation: multiply %dx%d by %dx%d Aborting...", row_A, col_A, row_B, col_B);
		return false;
	}

	int row_C = col_B;
	int col_C = row_A;
	
	//printf("Product matrix dim.: %dx%d\n", row_C, col_C);
	
	for (int row = 0; row < row_A; row++) {
		float accum = 0;	// accumulator
		int col = 0;

		//float arr[5];

		for (col; col < row_B; col++) {
			// L1: accum = A11 * B11 + A12 * B21 + A13 * B31
			// L2: accum = A21 * B11 + A22 * B21 + A23 * B31
			
			accum += *((arr_A+row*col_A)+col) * *((arr_B + row * (col_B - 1))+col);
		}

		//arr[row] = accum;
		//cout << arr[row] << ": " << row << endl;

		*((arr_C) + row) = accum;	// + row*(col_C-1)
	}

	return true;
}