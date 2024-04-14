#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv)
{
	char* s = (char*)malloc(sizeof(char) * 15);
	FILE* f = fopen("in.txt", "r");
	char* s1 = (char*)malloc(sizeof(char) * 15);

	fscanf(f, "%s", s);
	fscanf(f, "%s", s1);
	fclose(f);
	printf("%s ", s);
	printf("%s", s1);
	return 0;
}