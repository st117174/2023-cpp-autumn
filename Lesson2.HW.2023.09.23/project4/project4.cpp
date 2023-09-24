#include <iostream>;
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	e = n / 60;
	n -= 60 * e;
	if (n >= 36)
	{
		e++;
	}
	else if (n <= 35 && n >= 20)
	{
		d++;
		n -= 20;
		c = n / 10;
		n -= 10 * c;
		if (n == 9)
		{
			c = 1;
		}
		if (n != 9)
		{
			b = n / 5;
			n -= 5 * b;
			a = n;
		}
	}
	else if (n <= 19)
	{
		if (n == 19 || n == 18)
		{
			d++;
		}
		else if (n != 19 && n != 18)
		{
			c = n / 10;
		n -= c * 10;
		if (n == 9)
		{
			c++;
		}
		else if (n != 9)
		{
			if (n < 5)
			{
				a = n;
			}
			else if (n > 5)
			{
				b++;
				n -= 5;
				a = n;
			}
		}
	}
	}
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	return EXIT_SUCCESS;
}