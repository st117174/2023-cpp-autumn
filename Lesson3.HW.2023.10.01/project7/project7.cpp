#include <iostream>


int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int k = 0;
	int c = 0;
	int n = 0;
	if (a == 1)
	{
		std::cout << 0;
	}
	else
	{
		while (c < a)
		{
			++n;
			c = 1;
			for (int i = 0; i < n; ++i)
			{
				c = c * 2;
			}
			++k;
		}
		std::cout << k++;
	}
	return EXIT_SUCCESS;
}