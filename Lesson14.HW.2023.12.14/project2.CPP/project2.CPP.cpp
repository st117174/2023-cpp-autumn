#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	f = fopen("in.txt", "r");
	int sum = 0;

	while (!feof(f))
	{
		char c = 0;
		fscanf(f, "%c", &c);
		printf("%c", c);
	}

	int ind = 0;
	while (!feof(f))
	{
		++ind;
		char c = 0;
		fscanf(f, "%c", &c);
		if ((c == '\n') || (c == ' '))
		{
			++sum;
		}
		if (ind >= 2 && ind <= 7)
		{
			printf("%c", c);
		}
	}

	

	fclose(f);

	f = fopen("out.txt", "w");
	fprintf(f, "%d", sum);
	fclose(f);

	return EXIT_SUCCESS;
}