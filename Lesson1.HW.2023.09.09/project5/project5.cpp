﻿#include <iostream>
using namespace std;
int main()
{
	int v, t;
	cin >> v >> t;
	cout << ((v*t)%109+109)%109+1;
	return 0;
}