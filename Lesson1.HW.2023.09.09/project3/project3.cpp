﻿#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int b = a / 10;
	int c = b * (b + 1);
	cout << c * 100 + 25;
	return 0;
}