/*	File: part_2.cpp
 *	Author: Daric
 *	Date: 11/11/19
 *	Purpose:
 */

#include <iostream>
#include <iomanip>

#define FIELD_WIDTH 14

int main()
{
	using namespace std;
	short choice;
	float xStart, xEnd, xDelta;
	
	// I/O
	cout << "Choose a polynomial:\n";
	cout << "1. Y = X^3 - 2X + 10\n";
	cout << "2. Y = X^4 + 3X^2 - 15\n";
	cout << "3. Y = X^2 - 10\n";

	cin >> choice;

	if (choice > 3 || choice < 1) {
		cout << "Bad input.";
		return -1;
	}

	cout << "\nEnter the x start, x end, and x delta:\n";
	cin >> xStart >> xEnd >> xDelta;

	// Table header
	cout << endl << endl;
	cout << setfill(' ') << setw(FIELD_WIDTH / 2) << " x" << setw(FIELD_WIDTH) << "y" << setw(FIELD_WIDTH / 2) << endl;
	cout << setfill('-') << setw(FIELD_WIDTH + 1) << "|" << setw(FIELD_WIDTH) << '-' << setfill(' ') << endl;

	float x_i = xStart;
	do {
		static float y_i;
		
		if (choice == 1)
			y_i = pow(x_i, 3) - 2 * x_i + 10;
		else if (choice == 2)
			y_i = pow(x_i, 4) + 3 * x_i*x_i - 15;
		else
			y_i = pow(x_i, 2) - 10;
			
		cout << setw(FIELD_WIDTH) << left << x_i << "|" << setw(FIELD_WIDTH) << left << y_i << endl;
		x_i += xDelta;		// increment
	} while (x_i <= xEnd);	// check condition

	return 0;
}