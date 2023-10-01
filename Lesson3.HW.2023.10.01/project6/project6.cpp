#include <iostream>

int main(int argc, char* argv)
{
	int n = 0;
	std::cin >> n;
	int x = 0;
	int y = 0;
	int a = 0;
	int i = 0;
	while (i < n)
	{
		y = x;
		x = a;
		a = x + y;
		if (a == 0)
		{
			a++;
		}
		i++;
	}
	std::cout << a;
	return EXIT_SUCCESS;
}