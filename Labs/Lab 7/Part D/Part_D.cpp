/*	File: Part_D.cpp
 *	Author: Daric 
 *	Date: 10/16/19
 *	Purpose: Solve Y = (9/5)X^2 - (1/2)X + 2 for six given x-values.
 */

#include <iostream>

using namespace std;

float solve(float);	// prototype

int main()
{
	// Define variables
	float x1,x2,x3,x4,x5,x6;

	// I/O
	cout << "Solve Y = (9/5)X^2 - (1/2)X + 2 for six given x-values.\n\n";
	cout << "Enter x1: ";
	cin  >> x1; 
	cout << "Enter x2: ";
	cin  >> x2; 
	cout << "Enter x3: ";
	cin  >> x3; 
	cout << "Enter x4: ";
	cin  >> x4; 
	cout << "Enter x5: ";
	cin  >> x5; 
	cout << "Enter x6: ";
	cin  >> x6; 
	
	// Math
	cout << endl;
	cout << "Ordered pairs:" << endl;
	cout << "(" << x1 << ", " << solve(x1) << ")" << endl;
	cout << "(" << x2 << ", " << solve(x2) << ")" << endl;
	cout << "(" << x3 << ", " << solve(x3) << ")" << endl;
	cout << "(" << x4 << ", " << solve(x4) << ")" << endl;
	cout << "(" << x5 << ", " << solve(x5) << ")" << endl;
	cout << "(" << x6 << ", " << solve(x6) << ")" << endl;
	
	
	// end
	return 0;
}

// Y = (9/5)X^2 - (1/2)X + 2
float solve(float input) 
{
	return ( ((9.f/5.f)*(input*input)) - ((1.f/2.f)*input) + 2.f );
}
