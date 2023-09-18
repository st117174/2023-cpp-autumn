#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int b = 0;
	int c = 0;
	b = a + 1;
	c = a - 1;
	std::cout << "The next number for the number " << a << " is " << b << "." << std::endl;
	std::cout << "The previous number for the number " << a << " is " << c << "." << std::endl;
	return 0;
}