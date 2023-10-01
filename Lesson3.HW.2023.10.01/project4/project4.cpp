#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	int x = 0;
	while (x <= 1000)
	{
		if (x * x * x * a + b * x * x + c * x + d == 0)
		{
			std::cout << x << std::endl;
		}
		x++;
	}
	return EXIT_SUCCESS;
}