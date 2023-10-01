#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int n = 0;
	while (a % 10 == 0)
	{
		a = a / 10;
	}
	while (a > 0)
	{
		n = a % 10;
		std::cout << n;
		a = a / 10;
	}
	return EXIT_SUCCESS;
}