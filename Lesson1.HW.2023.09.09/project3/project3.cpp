#include <iostream>

int main(int argc, char* argv[])
{
	long long a;
	std::cin >> a;
	long long b = a / 10;
	long long c = b * (b + 1);
	std::cout << c * 100 + 25;
	return 0;
}