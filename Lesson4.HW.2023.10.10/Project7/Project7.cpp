#include <iostream>
#include <cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; n > i; ++i)
	{
		std::cin >> *(a + i);
	}

	int k = 0;

	for (int i = 0; n > i; ++i)
	{
		if (*(a + i) > 0)
		{
			k++;
		}
	}

	int* b = (int*)malloc(sizeof(int) * k);
	int c = 0;

	for (int i = 0; n > i; ++i)
	{
		if (*(a + i) > 0)
		{
			*(b + c) = *(a + i);
			c++;
		}
	}

	for (int i = 0; k > i; ++i)
	{
		std::cout << *(b + i) << " ";
	}
	
	free(a);
	free(b);
	return EXIT_SUCCESS;
}
