#include <iostream>;
int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	int a = 0;
	int l = 0;
	int p = 0;
	if (n == 0 || m == 0|| k == 0)
	{
		a = 0;
	}
	else if (n <= k)
	{
		a = 2 * m;
	}
	else if (n > k)
	{
		l = n / k;
		p = n % k;
		if (p > 0)
		{
			a = 2 * l * m + m;
		}
		else if (p == 0)
		{
			a = 2 * l * m;
		}
	}
	std::cout << a << std::endl;
	return EXIT_SUCCESS;
}