/*	File: part_3.cpp
 *	Author: Daric
 *	Date: 11/11/19
 *	Purpose:
 */

#include <iostream>

int main() 
{
	using namespace std;
	int numValues, i;		// declare vars
	float total = 0, i_v;	// declare vars

	// I/O
	cout << "Number of values: ";
	cin  >> numValues;
	i = numValues;

	while (i) {
		// I/O
		cout << "Enter value " << i << ": ";
		cin >> i_v;	

		total += i_v;	// accumulate last entered value

		i--;	// decrement
	}

	// I/O
	cout << "Sum: " << total << endl;
	cout << "Average: " << total / (float)numValues << endl;	// calc average
	cout << "Total values: " << numValues << endl;

	return 0;	// end
}