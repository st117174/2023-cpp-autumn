#include <iostream>;
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	int x = 0;
	if (a > b)
	{
		x = a;
		a = b;
		b = x;
	}
	if (a > c)
	{
		x = a;
		a = c;
		c = x;
	}
	if (b >= c)
	{
		x = b;
		b = c;
		c = x;
	}
	std::cout << a << " " << b << " " << c << std::endl;
	return EXIT_SUCCESS;

}
