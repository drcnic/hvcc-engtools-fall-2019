/*  File: part_3.cpp
 *  Author: Daric Niclas
 *  Date: 11/5/19
 *  Purpose: calculate the variation of a mass of a particle given user inputs
 */

#define _USE_MATH_DEFINES	// so MSVC will let me use constants
#include <iostream>	// for I/O streaming
#include <cmath>	// for math funcs like sqrt()
#include <iomanip>	// for I/O stream formatting

using namespace std;

int main()
{
	// declare variables
	double v_delta, v_start, v_end, i_v, i_m;	// v: velocity
	
	// I/O
	cout << "Enter the start velocity: "; cin >> v_start;
	cout << "Enter the end velocity:   "; cin >> v_end;
	cout << "Enter the velocity delta: "; cin >> v_delta;

	i_v = v_start;

	// start of chart
	cout << endl;
	cout << "   Velocity   |     Mass     " << endl;
	cout << "--------------|--------------" << endl;

	while ( !(i_v > v_end) ) {
		static int fieldWidth = 14;

		i_m = 1.f / (sqrt(1.f - (i_v * i_v)));	// calculate mass
		
		// output table row
		cout << setw(fieldWidth) << left << i_v << "|"
			<< setw(fieldWidth) << left << i_m << endl;

		i_v += v_delta;	// increment by the delta
	}
	
	return 0;	// end
}