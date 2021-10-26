/*	File: part_4.cpp
 *	Author: Daric
 *	Date: 11/11/19
 *	Purpose:
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define FIELD_WIDTH 12


int main()
{
	using namespace std;
	float tStart, tEnd, tDelta;	// declare vars

	// I/O
	cout << "Enter the time start, time end, and time delta.\n";
	cin >> tStart >> tEnd >> tDelta;

	// Table header
	cout << endl << endl;
	cout << setfill(' ') << setw(FIELD_WIDTH / 2) << " x" << setw(FIELD_WIDTH) << "y" << setw(FIELD_WIDTH / 2) << endl;
	cout << setfill('-') << setw(FIELD_WIDTH + 1) << "|" << setw(FIELD_WIDTH) << '-' << setfill(' ') << endl;

	for (float t_i = tStart; t_i < tEnd; t_i += tDelta) {
		static float v_i;
		
		v_i = 3*pow(t_i, 2) - 12 * t_i - 15;	// solve polynomial for this iteration

		if (v_i < 1 && v_i > -1) {
			cout << setw(FIELD_WIDTH) << left << t_i << "|" << setw(FIELD_WIDTH) << left << v_i << "(nearing zero)" << endl;
			return 1;	// stop execution
		}
		
		cout << setw(FIELD_WIDTH) << left << t_i << "|" << setw(FIELD_WIDTH) << left << v_i << endl;
	}

	cout << "\nNo zero values found.";

	return 0;	// end
}