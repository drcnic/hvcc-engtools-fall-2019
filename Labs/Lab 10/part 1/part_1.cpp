/*	File: part_1.cpp
 *	Author: Daric
 *	Date: 11/11/19
 *	Purpose: to evaluate Y=X3-2X+10 and make a table of values 
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define FIELD_WIDTH 12


int main()
{
	using namespace std;
	float xStart, xEnd, xDelta;	// declare vars

	// I/O
	cout << "Enter the x start, x end, and x delta.\n";
	cin  >> xStart >> xEnd >> xDelta;	

	// Table header
	cout << endl << endl;
	cout << setfill(' ') << setw(FIELD_WIDTH/2) << " x" << setw(FIELD_WIDTH) << "y" << setw(FIELD_WIDTH/2) << endl;
	cout << setfill('-') << setw(FIELD_WIDTH+1) << "|"  << setw(FIELD_WIDTH) << '-'    << setfill(' ') << endl;

	float x_i = xStart;
	do {
		static float y_i;
		y_i = pow(x_i, 3) - 2 * x_i + 10;	// solve polynomial for this iteration
		cout << setw(FIELD_WIDTH) << left << x_i << "|" <<  setw(FIELD_WIDTH) << left << y_i << endl;
		x_i += xDelta;	// increment
	} while (x_i <= xEnd);	// check condition

	return 0;	// end
}