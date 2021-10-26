/*	File: Part_C.cpp
 *	Author: Daric
 *	Date: 10/16/19
 *	Purpose: Calculate the x and y components of a resultant force given its magnitude and angle.
 */
 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Define variables
	float forceResultant, theta;	// inputs
	float componentX, componentY;	// outputs
	
	// I/O
	cout << "Calculate the x and y components of a resultant force given its magnitude and angle."
			<< endl << endl;
	cout << "Enter the resultant force (N): ";
	cin  >> forceResultant;
	cout << "Enter the angle (degrees): ";
	cin  >> theta;
	
	// Calculations
	componentX = forceResultant * cos(theta);
	componentY = forceResultant * sin(theta);
	
	// I/O
	cout << endl;
	cout << "Resultant force: " << forceResultant << " N" 		<< endl;
	cout << "Theta: "			<< theta		  << " degrees" << endl;	
	cout << "X Component: "		<< componentX	  << " N"		<< endl;
	cout << "Y Component: "		<< componentY	  << " N"		<< endl;
	
	// end
	return 0;
}