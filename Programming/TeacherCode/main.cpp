#include <iostream>
#include <cmath>

int main(int argc, char** argv) 
{
	using namespace std;
	
	float n1,n2,n3;
	float avg;	
	
	cout << "Enter first number: " 	<< endl;
	cin  >> n1;
	cout << "Enter second number: " << endl;
	cin  >> n2;
	cout << "Enter third number: " 	<< endl;
	cin  >> n3;
	
	avg = (n1+n2+n3)/3;
	
	cout << "Average: " << avg << endl;
	
	cin.get();
	
	return 0;
}


