/* File: Problem4.cpp
 * Authors: Daric Niclas
 * Date: 10/8/19
 * Purpose: Calculate area & circumference of a circle given its radius
 */

#include <iostream>
#include <cmath>

int main()
{
	using namespace std;
	
	// define variables
	float radius;
	
	// I/O
	cout << "Calculate area and circumference of a circle, given its r" 
		 << endl << endl;
		
	cout << "Enter the radius: ";
	cin  >> radius;
	
	cout << "Circumference: " << 2*M_PI*radius 		<< endl;	// math here
	cout << "Area: "		  << M_PI*radius*radius << endl;	// more math
	
	return 0;	// end
}
