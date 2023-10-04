#include <iostream>

int power(int k)
{
	int c = 1;
	for (int i = 0; i < k; i++)
	{
		c = c * 2;
	}
	return c;
}

int main(int argc, char**)
{
	int a = 0;
	std::cin >> a;
	int k = 0;
	for (int i = 0; power(i) < a; ++i)
	{
		++k;
	}
	std::cout << k;
}