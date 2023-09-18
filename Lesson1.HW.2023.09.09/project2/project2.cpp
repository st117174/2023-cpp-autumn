#include <iostream>
int main(int argc, char* argv[]) 
{
	int a;
	std::cin >> a;
	int b = (a + 1) * (abs(a - 1) + 1) / 2;
	std::cout << (b);
	return 0;
}