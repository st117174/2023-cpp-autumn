#include <iostream>
#include <cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	for (int i = 0; i <= n / 2; ++i)
	{
		int c = 0;
		int b = 0;
		c = *(a + i);
		b = *(a + n - i - 1);
		*(a + i) = b;
		*(a + n - i - 1) = c;
	}
	
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);
	return EXIT_SUCCESS;
}
