#include <iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	std::cin >> k;
	int x = 1;
	int n = 0;
	while (x <= k)
	{
		int m = 0;
		int g = 0;
		int l = 0;
		g = x;
		while (g > 0)
		{
			m *= 10;
			l = (g % 10);
			m += l;
			g = g / 10;
		}
		if (x == m)
		{
			n++;
		}
		x++;
	}
	std::cout << n;
	return EXIT_SUCCESS;
}