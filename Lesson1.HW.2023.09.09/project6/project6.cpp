#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a >> b;
	int c = a / b;
	int d = b / a;
	std::cout << (a * c + b * d) / (c + d);
	return 0;
}