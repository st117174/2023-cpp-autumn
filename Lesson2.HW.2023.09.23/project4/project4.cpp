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
	d = (n - e * 60) / 20;
	c = (n - e * 60 - d * 20) / 10;
	b = (n - e * 60 - d * 20 - c * 10) / 5;
	a = (n - e * 60 - d * 20 - c * 10 - b * 5);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	return EXIT_SUCCESS;
}