/*	File: main.cpp
 *	Author: Daric
 *	Date: 11/11/19
 *	Purpose: predict the number of cars parked at HVCC on any given day.
 
	PROBLEM STATEMENT: This program predicts the number of cars parked at HVCC on any given 
					   day. First, it retrieves all necessary user input: the number of classes
					   scheduled (classes), the number of scheduled tests (tests), the weather 
					   (weather), and the semester week (week). Then, adjustments are made to
					   the maxCars value based on the number of classes, tests, weather and
					   semester week. maxCars is rounded to a whole number integer and displayed, 
					   along with all user-entered information.
 */ 

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
{
	using namespace std;
	int classes, tests, weather, week;	// define vars
	
	// I/O
	cout << "Enter number of scheduled classes: ";
	cin  >> classes;
	cout << "\nEnter number of scheduled tests: ";
	cin  >> tests;
	cout << "\nChoose the best description of today's weather:\n1. Bad\n2. Good\nChoice: ";
	cin  >> weather; 
	cout << "\nEnter the semester week: ";
	cin  >> week;
	cout << endl;

	float maxCars = (classes*24.f)/1.02;

	// Adjustments based on number of tests
	if (tests < 15) {
		// no modification
	} else if (15 <= tests && 30 >= tests) {
		maxCars -= .15 * (24 * classes);

	} else if (tests > 30) {
		maxCars -= (1.f / 10.f) * (24 * classes);

	} else {
		cout << "Bad value for number of tests. Aborting.\n";
		return -1;
	}


	if (weather == 1) {	// BAD weather
		// Adjustments based on semester week
		if (week > 0 && week < 5) {
			// no modification

		} else if (week >= 5 && week < 12) {
			maxCars -= (classes + .25 * classes) / (.3 * classes);

		} else if (week >= 12 && week < 17) {
			maxCars -= classes * .05;

		} else {
			cout << "Bad value for semester week. Aborting.\n";
			return -2;
		}

	} else if (weather == 2) {	// GOOD weather
		// Adjustments based on semester week
		if (week > 0 && week < 5) {
			maxCars -= (1.f / 10.f) * (.12 * classes + (classes/1.02));

		} else if (week >= 5 && week < 12) {
			maxCars -= (3.f / 5.f) * (.12 * classes + 50);

		} else if (week >= 12 && week < 17) {
			maxCars -= (1.f / 5.f) * (classes);

		} else {
			cout << "Bad value for semester week. Aborting.\n";
			return -3;
		}

	} else {
		cout << "Bad value for weather. Aborting.\n";
	}
	//cout << maxCars;
	maxCars = round(maxCars);	// can't have partial cars

	// results output
	cout << "Classes: " << classes << "; Tests: " << tests << "; Weather: " 
		<< weather << "; Week: " << week << endl << endl;
	cout << "Prediction: " << maxCars << " cars maximum.\n\n";

	return 0;
}