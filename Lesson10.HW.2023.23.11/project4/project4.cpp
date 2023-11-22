﻿#include <iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv)
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
	return EXIT_SUCCESS;
}

void hanoi(int n, int from, int to)
{
	if (n > 0)
	{
		int tmp = 6 - from - to;
		if (n == 1)
		{
			printf("%d %d %d\n", n, from, to);
		}
		else
		{
			hanoi(n - 1, from, to);
			printf("%d %d %d\n", n, from, tmp);
			hanoi(n - 1, to, from);
			printf("%d %d %d\n", n, tmp, to);
			hanoi(n - 1, from, to);
		}
	}
}