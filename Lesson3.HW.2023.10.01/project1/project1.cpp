#include <iostream>

int main(int argc, char* arv[])
{
	int a = 0;
	std::cin >> a;
	int i = 0;
	int b = 0;
	int k = 0;
	while (i < a)
	{
		b++;
		i++;
		for (int j = 0; j < b; j++)
		{
			std::cout << b << " ";
			k++;
			if (k == a) break;
		}
		if (k == a) break;
	}
	return EXIT_SUCCESS;
}