/*	File: Part_B.cpp
 *	Author: Daric
 *	Date: 10/16/19
 *	Purpose: Calculate the equivalent resistance of two resistors wired in parallel
 *			 using Kirchoff's law
 */
 
 #include <iostream>
 
 using namespace std;
 
 int main() 
 {
 	float f_R1, f_R2, f_Req;	// Define variables
 	
 	// I/O
 	cout << "Calculate the equivalent resistance of two loads wired in parallel.\n\n";
 	cout << "Enter R1 (Ohms): ";
 	cin  >> f_R1;
 	cout << "Enter R2 (Ohms): ";
 	cin  >> f_R2;
 	
 	f_Req = 1/( (1/f_R1)+(1/f_R2) );	// Calculate Req
 	
 	// I/O
 	cout << endl;
 	cout << "R1 (Ohms): " << f_R1 << endl;
 	cout << "R2 (Ohms): " << f_R2 << endl;
 	cout << "Equivalent resistance (Ohms): " << f_Req << endl;
 	
 	// end
 	return 0;	
 }
