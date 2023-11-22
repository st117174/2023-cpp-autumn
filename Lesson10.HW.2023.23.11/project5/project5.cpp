#include <iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv)
{
	int n = 0;
	std::cin >> n;

	if (n >= 2)
	{
		if (n % 2 == 0)
		{
			hanoi(n, 1, 3);
			n -= 1;
		}
		else
		{
			hanoi(n, 1, 2);
			n -= 1;
			hanoi(n, 2, 3);
			n -= 1;
			while (n > 0)
			{
				hanoi(n, n % 2 + 2, (n + 1) % 2 + 2);
				n -= 1;
			}
		}
	}
	

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