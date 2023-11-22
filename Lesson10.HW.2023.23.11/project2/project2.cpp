#include <iostream>

void hanoiRep(int n, int from, int to);

int main(int argc, char* argv)
{
	int n = 0;
	std::cin >> n;
	hanoiRep(n, 1, 3);
	return EXIT_SUCCESS;
}

void hanoiRep(int n, int from, int to)
{
	if (n > 0)
	{
		if (from + to == 4)
		{
			hanoiRep(n, from, 2);
			hanoiRep(n, 2, to);
		}
		else
		{
			int tmp = 6 - from - to;
			hanoiRep(n - 1, from, tmp);
			printf("%d %d %d\n", n, from, to);
			hanoiRep(n - 1, tmp, to);
		}
	}
 }