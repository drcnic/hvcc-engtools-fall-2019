/*	File: part_a.cpp
 *	Author: Daric Niclas
 *	Date: 11/18/19
 *	Purpose: 
 */

#define FIELD_WIDTH 15
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	float xStart, xEnd, xDelta;	// declare variables

	// I/O
	cout << "Enter the starting X, ending X, and delta X: ";
	cin  >> xStart >> xEnd >> xDelta;

	// table header
	cout << setfill(' ') << setw((FIELD_WIDTH+1)/2) << 'x' << setw((FIELD_WIDTH+1)/2) << '|' 
		 << setw((FIELD_WIDTH + 1) / 2) << 'y' << setw((FIELD_WIDTH + 1) / 2) << endl;
	cout << setfill('-') << setw(FIELD_WIDTH+1) << '|' << setw(FIELD_WIDTH) << '-' << setfill(' ') << endl;

	for (float x_i = xStart; x_i <= xEnd; x_i += xDelta) {
		cout << setprecision(5) << fixed;	// each number will have five decimal places
		cout << setw(FIELD_WIDTH) << left << x_i << '|' << setw(FIELD_WIDTH)			// table
			 << left << 5 * (x_i * x_i * x_i) - 2 * (x_i * x_i) + 6 * x_i - 5 << endl;	//  row
	}

	return 0;	//end
}