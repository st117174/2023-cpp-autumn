#include <iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	std::cin >> a;
	long long n = 1;
	long long k = 0;
	for (n = 1; n * n <= a; n++)
	{
		if (a % n == 0)
		{
			k++;
		}
		if (a % n == 0 && a / n != n)
		{
			k++ ;
		}
	}
	std::cout << k << std::endl;
	return EXIT_SUCCESS;
}