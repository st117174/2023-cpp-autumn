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

	int max = *a;
	int min = *a;
	int ma = 0;
	int mi = 0;

	for (int i = 0; n > i; ++i)
	{
		if (*(a + i) >= max)
		{
			ma = i;
			max = *(a + i);
		}

		else if (*(a + i) < min)
		{
			mi = i;
			min = *(a + i);
		}
	}

	int b = *(a + ma);
	int l = *(a + mi);
	*(a + ma) = l;
	*(a + mi) = b;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	
	free(a);
	return EXIT_SUCCESS;
}
