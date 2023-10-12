#include <iostream>

int main(int argc, char argv[])
{
	int a = 0;
	std::cin >> a;

	int n = 0;
	int m = 1;
	while (a != 0)
	{
		n = a % 10;
		a = a / 10;
		m *= n;
	}

	std::cout << m;
	return EXIT_SUCCESS;
}
