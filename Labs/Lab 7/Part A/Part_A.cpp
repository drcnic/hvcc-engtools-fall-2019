/*	File: Part_A.cpp
 *	Author: Daric
 *	Date: 10/16/19
 *	Purpose: Calculate kinetic energy of an object given its mass and velocity.
 */
#include <iostream>

using namespace std;

int main() 
{
	float f_Mass, f_Velocity;	// define variables
	
	// I/O
	cout << "Calculate kinetic energy of an object given its mass and velocity. \n\n";
	cout << "Enter mass (kg): ";
	cin  >> f_Mass;
	cout << "Enter velocity (m/s): ";
	cin  >> f_Velocity;
	
	cout << "Kinetic energy (kgm/s): " << (0.5f)*(f_Mass*f_Velocity*f_Velocity) << "kgm/s" << endl;	// math
	cout << "Mass: " << f_Mass << "kg" << endl;
	cout << "Velocity: " << f_Velocity << "m/s" << endl;
	
	return 0;
}
