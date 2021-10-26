/*	File: part_2.cpp
 *	Author: Daric Niclas
 *	Date: 11/20/19
 *	Purpose:
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// define vars
	const int fieldWidth = 10;
	int arr1[4][3];
	float avg[3];

	for (int col = 0; col < 3; col++) {
		static int num = 1;
		int colSum = 0;	// accumulator

		for (int row = 0; row < 4; row++) {
			arr1[row][col] = num;
			colSum += num;	// accumulate values of all elements in column
			num += 2;	
		}

		avg[col] = colSum / 4.f;	// get average of values in column
	}

	cout << left << setw(fieldWidth) << "Original array:" << endl;
	for (int row = 0; row < 4; row++) {	// output original array
		for (int col = 0; col < 3; col++) {
			cout << setw(fieldWidth) << arr1[row][col];
		}
		cout << endl;
	}

	cout << endl;
	cout << left << setw(fieldWidth) << "Column averages:" << endl;
	for (int i = 0; i < 3; i++) {	// output average array
		cout << setw(fieldWidth) << avg[i];
	}

	cout << endl;

	return 0;	//end
}