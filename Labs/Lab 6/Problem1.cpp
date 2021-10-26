//Lab 6 - Problem 1
#include<iostream>
using namespace std;

int main()
{//variables defined here
	int firstnum, sum;
	float secondnum;

	//data input section
	cout << "Enter a value for x: ";
	cin  >> firstnum;
	cout << "Enter a value for y: ";
	cin  >> secondnum;

	//math stuff
	sum = firstnum + secondnum;

	//data output section
	cout << "This is a really simple program that doesn't do much";
	cout << "\nthe sum of firstnum and secondnum is "<<sum<<"\n";

	return 0;
}

