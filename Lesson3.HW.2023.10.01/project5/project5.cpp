#include <iostream>

int symm(int a)
{
	int x = 0;
	int n = 0;
	while (a > 0)
	{
		n *= 10;
		x = (a % 10);
		n += x;

		a = a / 10;
	}
	return n;
}
int main(int argc, char* argv[])
{
	int k = 0;
	std::cin >> k;
	int x = 1;
	int n = 0;
	while (x <= k)
	{
		if (x == symm(x))
		{
			n++;
		}
		x++;
	}
	std::cout << n;
	return EXIT_SUCCESS;
}