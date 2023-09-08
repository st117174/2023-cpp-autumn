#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int c = a / b;
	int d = b / a;
	cout << (a*c + b * d) / (c + d);
	return 0;
}