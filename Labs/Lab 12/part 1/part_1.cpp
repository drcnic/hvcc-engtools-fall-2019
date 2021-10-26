/*	File: part_1.cpp
 *	Author: Daric Niclas
 *	Date: 11/19/19
 *	Purpose:
 */

#include <iostream>
#include <iomanip>

using namespace std;

float arrSum(float[], int, int);

int main()
{
	const int arrSize = 15, fieldWidth = 15;	// define constants
	float arr1[arrSize] = { 12.14, 11.12, 12.65, 13.6, 17.1, 15.33, 9.75, 11.2,	// define array 1
							12.43, 16.41, 10.49, 12.9, 8.6, 16.87, 12.32 };
	float arr2[arrSize];
	arr2[0] = arr1[0];
	arr2[arrSize - 1] = arr1[arrSize - 1];

	for (int i = 1; i < arrSize - 1; i++) {
		//arr1[i] = rand() % 100;		// random number between 0 and 100
		//cout << arrSum(arr1, i-1, 3) << endl;
		arr2[i] = (arrSum(arr1, i-1, 3) / 3);	// smoothing math
	}
	
	// output table
	cout << setw(fieldWidth) << "Unsmoothed" << setw(fieldWidth) << "Smoothed" << endl;
	for (int i = 0; i < arrSize; i++) {
		cout << left << setw(fieldWidth) << arr1[i] << setw(fieldWidth) << arr2[i] << endl;
	}
}

// get the sum of array elements given an array, a starting index, and a length from that index
float arrSum(float arr[], int indexStart, int length) 
{
	float sum = 0;

	for (int i = indexStart; i < indexStart + length; i++) {	// loop from start index to final index
		sum += arr[i];
	}

	return sum;
}