#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	if (a % 10 == 1 && a % 100 != 11)
	{
		std::cout << a << " bochka" << std::endl;
	}
	else if ((a % 10 == 2 || a % 10 == 3 || a % 10 == 4) && ((a % 100 - a % 10) / 10 != 1))
	{
		std::cout << a << " bochki" << std::endl;
	}
	else if (((a % 100 - a % 10) != 1) || (a % 10 == 0) || a % 10 >= 5)
	{
		std::cout << a << " bochek" << std::endl;
	}
	return EXIT_SUCCESS;
}