#include <iostream>
#include<cstdlib>

int main(int argc, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	int k = 0; 

	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			k++;
		}
		
	}

	free(a);
	std::cout << k;
	return EXIT_SUCCESS;
}
