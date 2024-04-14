#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv)
{
	FILE* f = fopen("in.txt", "r");

	f = fopen("in.txt", "r");
	int sum = 1;
	while (!feof(f))
	{
		char c = 0;
		fscanf(f, "%c", &c);
		if ((c == '\n') || (c == ' '))
		{
			++sum;
		}
	}
	fclose(f);

	f = fopen("in.txt", "r");
	int maxlen = 0;
	int curlen = 0;
	int mxStartInd = 1;
	int mxEndInd = 1;
	int curStart = 1;
	int curEnd = 1;
	int count = 0;
	while (!feof(f))
	{

		char c = 0;
		fscanf(f, "%c", &c);
		++count;

		if ((c != '.') && (c != '?') && (c != '!'))
		{
			++curlen;
			maxlen = (curlen > maxlen) ? curlen : maxlen;
		}
		else
		{
			curEnd = count;
			mxEndInd = (curlen >= maxlen) ? curEnd : mxEndInd;
			mxStartInd = (curlen >= maxlen) ? curStart : mxStartInd;
			curlen = 0;
			curStart = count + 1;
		}
	}
	fclose(f);

	int ind = 0;
	int s = 0;
	char* arr = (char*)malloc(sizeof(char) * maxlen);
	f = fopen("in.txt", "r");
	while (!feof(f))
	{

		char c = 0;
		fscanf(f, "%c", &c);
		++ind;
		if (ind >= (mxStartInd + 1) && ind <= mxEndInd)
		{
			*(arr + s) = c;
			++s;
		}
	}
	fclose(f);


	
	f = fopen("out.txt", "w");
	fprintf(f, "%d \n", sum);
	for (int i = 0; i < maxlen; ++i)
	{
		fprintf(f, "%c", *(arr + i));
	}
	fclose(f);

	return EXIT_SUCCESS;
}