/*	File: part_c.cpp
 *	Author: Daric Niclas
 *	Date: 11/19/19
 *	Purpose:
 */

#define ARR_SIZE 5
#define FIELD_WIDTH 15
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	float tFahren[ARR_SIZE], tCelsius[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++) {	// input loop
		cout << "Enter temperature " << i+1 << " (Fahrenheit): ";
		cin >> tFahren[i];
		tCelsius[i] = ( (tFahren[i] - 32) * 5.f/9.f );	// fahren -> celsius conversion
	}

	// table header
	cout << endl;
	cout << setfill(' ') << setw(FIELD_WIDTH / 2.f) << " Fahrenheit" 
		 << setw((FIELD_WIDTH -4) / 2.f) << '|' << setw(FIELD_WIDTH / 2.f) << " Celsius" << endl;
	cout << setfill('-') << setw(FIELD_WIDTH + 1) << '|' << setw(FIELD_WIDTH + 1) << '-' << endl;
	cout << setfill(' ');

	for (int i = 0; i < ARR_SIZE; i++) {	// output loop
		// table row
		cout << setw(FIELD_WIDTH) << tFahren[i] << '|' << setw(FIELD_WIDTH) << tCelsius[i] << endl;
	}

	return 0;
}