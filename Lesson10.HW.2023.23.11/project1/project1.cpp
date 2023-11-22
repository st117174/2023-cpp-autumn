#include <iostream>

int main(int argc, char* argv)
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 2);
	return EXIT_SUCCESS;
}

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		if (n == 1)
		{
			printf("1 %d %d\n", from, to);
		}
		else
		{
			int tmp = 6 - from - to;
			hanoi(n - 1, from, tmp);
			printf("%d %d %d\n", n, from, to);
			hanoi(n - 1, tmp, to);
		}
	}
}