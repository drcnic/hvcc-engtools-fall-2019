/*  File: part_1.cpp
 *  Author: Daric Niclas
 *  Date: 10/31/19
 *  Purpose: choose shape from menu, output area and shape etc this time with switch
 */
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	short choice = 0;	// variable to store choice

	// I/O
	cout << "Choose a shape:" << endl;
	cout << "1. Circle" << endl;
	cout << "2. Rectangle" << endl;
	cout << "3. Triangle" << endl;
	cout << "4. Trapezoid" << endl;
	cout << endl;
	cin >> choice;

	double area = -1;	// variable to store area, initialized at -1 for 
						// nonexistant error check

	switch(choice) {
		case 1: {	// circle
			double radius;

			// I/O
			cout << "\nCircle selected.\nEnter radius: ";
			cin >> radius;

			area = M_PI * radius * radius;	//math

			break;
		}
		case 2: {	// rectangle
			double length, width;

			// I/O
			cout << "\nRectangle selected.\nEnter length: ";
			cin >> length;
			cout << "Enter width: ";
			cin >> width;

			area = length * width;	// math

			break;
		}
		case 3: {	// triangle
			double base, height;

			// I/O
			cout << "\nTriangle selected.\nEnter base: ";
			cin >> base;
			cout << "Enter height: ";
			cin >> height;

			area = .5f * base * height;	// math

			break;
		}
		case 4: {	// trapezoid
			double height, b1, b2;
	
			// I/O
			cout << "\nTrapezoid selected.\nEnter height: ";
			cin >> height;
			cout << "Enter base 1: ";
			cin >> b1;
			cout << "Enter base 2: ";
			cin >> b2;

			area = .5f * (b1 + b2) * height;	// math

			break;
		} 
		default: {
			cout << "\nBad input." << endl;
			return -1;
		}
	}

	// final output
	cout << "\nChoice: " << choice << endl;
	cout << "Area: " << area << endl;

	return 0;	// end
}