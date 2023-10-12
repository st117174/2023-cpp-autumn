#include <iostream>
#include <cmath>

int main(int argc, char argv[])
{
	int a = 0;
	std::cin >> a;
	
	for (int i = 0; i <= abs(a); ++i)
	{
		std::cout << (abs(a) - i) * (a / abs(a))<< " ";
	}

	return EXIT_SUCCESS;
}
