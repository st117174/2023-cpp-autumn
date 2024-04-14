#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int strlen(char* arr)
{
		int res = 0;
		while (arr[res++] != '\0');
		return res;
}

char* strcatt(char*& str1, char*& str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* str = (char*)malloc(sizeof(char) * (len1 + len2));
	for (int i = 0; i < (len1 + len2); ++i)
	{
		if (i < len1)
		{
			*(str + i) = *(str1 + i);
		}
		else if (i >= len1)
		{
			*(str + i) = *(str2 + (i - len1));
		}
		return str;
	}
}

void strstrr(char* &str1, char* &str2)
{

}

void substrr(char* &str1, char* &str2)
{

}

void strcmpp(char* &str1, char* &str2)
{

}

void strmultt(int a, char*& str)
{

}

int main(int argc, char* argv)
{
	FILE* f = fopen("in.txt", "r");
	int count = 0;
	while (!feof(f))
	{
		char c = 0;
		fscanf(f, "%c", &c);
		count++;
	}
	fclose(f);

	int n = 0;
	printf("Input sizeof string\n");
	scanf("%d", &n);
	printf("Input string");

	char* str = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%c", &*(str + i));
	}
	char* file = (char*)malloc(sizeof(char) * count);

	f = fopen("in.txt", "r");
	int ind = 0;
	while (!feof(f))
	{
		char c = 0;
		fscanf(f, "%c", &c);
		*(file + ind) = c;
		ind++;
	}
	fclose(f);
	
	f = fopen("out.txt", "w");
	fscanf(f, "%s", strcatt(file, str));


	return 0;
}