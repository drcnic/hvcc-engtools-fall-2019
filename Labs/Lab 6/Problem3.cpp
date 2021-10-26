/* File: Problem3.cpp
 * Authors: Daric Niclas
 * Date: 10/8/19
 * Purpose: Evaluate a(b+c)-d^3 given all variables through user input
 */
 
#include <iostream>
#include <cmath>

int main() 
{
	using namespace std;
	
	// define variables
	float a, b, c, d;
	
	// I/O
	cout << "Evaluate a(b+c)-d^3 with given values of a, b, c, and d." << "\n" << endl;
	cout << "a = ";
	cin  >> a;
	cout << "b = ";
	cin  >> b;
	cout << "c = ";
	cin  >> c;
	cout << "d = ";
	cin  >> d;
	
	cout << "\na(b+c)-d^3 evaluates to: " << a*(b+c)-pow(d, 3) << endl;		// math here
	
	return 0;	// end
}
