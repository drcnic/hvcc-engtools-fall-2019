//Lab 6 - Problem 2

#include<iostream>
using namespace std;

int main()
{//variables defined here
	int age;
	string NAME;

	//data input
	cout << "enter your first name please.  ";
	cin  >> NAME;
	cout << "enter your age.  Whole numbers please";
	cin  >> age;

	//math stuff
	age=age+10;

	//data output
	cout << "hello " << NAME << "  You will be " << age << 
	" years old in the year 2028";

	return 0;
}

