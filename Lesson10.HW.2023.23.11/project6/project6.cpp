#include<iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	hanoi(a, 1, 3);
	return EXIT_SUCCESS;
}

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int tmp = 6 - from - to;
		if (n == 1)
		{
			printf("1 %d %d\n", from, to);
		}
		else
		{
			hanoi(n - 1, from, to);
			hanoi(n - 2, to, tmp);
			printf("0 %d %d\n", from, to);
			hanoi(n - 2, tmp, from);
			hanoi(n - 1, from, to);
		}
	}
}