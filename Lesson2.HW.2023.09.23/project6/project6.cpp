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
		l = n * 2 / k;
		p = n * 2 % k;
		if (p == 0)
		{
			a = m * l;
		}
		else if (p != 0)
		{
			a = m * (1 + l);
		}
	}
	std::cout << a << std::endl;
	return EXIT_SUCCESS;
}