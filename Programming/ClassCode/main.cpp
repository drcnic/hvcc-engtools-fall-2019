

#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	float a,b,y;
	
	std::cout << "Solves \"y = 5a^2 - 3b^2\" for y given values of a and b" << std::endl;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	
	y = 5*pow(a, 2) - 3*pow(b, 2);
	
	std::cout << "y = " << y << ", a = " << a << ", b = " << b << std::endl;
	std::cin.get();
	
	return 0;
}
