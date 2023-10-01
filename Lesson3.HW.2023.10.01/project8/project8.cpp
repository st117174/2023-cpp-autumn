#include <iostream>

int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;
	int n = 0;
	std::cin >> x;
	std::cin >> y;
	std::cin >> n;
	if ((x % 2 == 0 && y % 2 == 0 && n % 2 != 0) || (n > x && n > y) || ((x == y) && (n != 0 || n != x)))
	{
		std::cout << "Impossible";
	}
	else if (n == x)
	{
		std::cout << ">A" << std::endl;
	}
	else if (n == y)
	{
		std::cout << ">B" << std::endl;
	}
	else if (x > y)
	{
		if ((x - n) % y == 0)
		{
			std::cout << ">A" << std::endl;
			for (int i = 0; i < (x - n) / y; i++)
			{
				std::cout << "A>B" << std::endl;
			}
		}
		else if (n % y == 0)
		{
			for (int i = 0; i < n / y; i++)
			{
				std::cout << ">B" << std::endl << "B>A" << std::endl;
			}
		}

		else if ((n - (x % y)) % y == 0)
		{
			std::cout << ">A" << std::endl;
			for (int i = 0; i < ((x / y) - (n - (x % y)) % y); i++)
			{
				std::cout << "A>B" << std::endl;
			}
		}
		else if (n == y - x % y)
		{
			for (int i = 0; i < 1 + x / y; i++)
			{
				std::cout << ">B" << std::endl << "B>A" << std::endl;
			}
		}
		else if ((n + x % y) % y == 0)
		{
			for (int i = 0; i < 1 + x / y; i++)
			{
				std::cout << ">B" << std::endl << "B>A" << std::endl;
			}
			std::cout << "A>" << std::endl << "B>A" << std::endl;
			for (int i = 0; i < ((n + x % y) / y - 1); i++)
			{
				std::cout << ">B" << std::endl << "B>A" << std::endl;
			}
		}
		else
		{
			std::cout << "Impossible";
		}
	}
	else if (y > x)
	{
		if ((y - n) % x == 0)
		{
			std::cout << ">B" << std::endl;
			for (int i = 0; i < (y - n) / x; i++)
			{
				std::cout << "B>A" << std::endl;
			}
		}
		else if (n % x == 0)
		{
			for (int i = 0; i < n / x; i++)
			{
				std::cout << ">A" << std::endl << "A>B" << std::endl;
			}
		}

		else if ((n - (y % x)) % x == 0)
		{
			std::cout << ">B" << std::endl;
			for (int i = 0; i < ((y / x) - (n - (y % x)) % x); i++)
			{
				std::cout << "B>A" << std::endl;
			}
		}
		else if (n == x - y % x)
		{
			for (int i = 0; i < 1 + y / x; i++)
			{
				std::cout << ">A" << std::endl << "A>B" << std::endl;
			}
		}
		else if ((n + y % x) % x == 0)
		{
			for (int i = 0; i < 1 + y / x; i++)
			{
				std::cout << ">A" << std::endl << "A>B" << std::endl;
			}
			std::cout << "B>" << std::endl << "A>B" << std::endl;
			for (int i = 0; i < ((n + y % x) / x - 1); i++)
			{
				std::cout << ">A" << std::endl << "A>B" << std::endl;
			}
		}
		else
		{
			std::cout << "Impossible";
		}
	}
	return EXIT_SUCCESS;
}