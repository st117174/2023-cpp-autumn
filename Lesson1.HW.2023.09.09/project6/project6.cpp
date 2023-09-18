#include <iostream>

int main(int argc, char* argv[])
{
	int a, b;
	std::cin >> a >> b;
	int c = a / b;
	int d = b / a;
	std::cout << (a * c + b * d) / (c + d);
	return 0;
}