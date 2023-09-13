#include <iostream>

int main(int argc, char* argv[])
{
	int v, t;
	std::cin >> v >> t;
	std::cout << ((v*t)%109+109)%109+1;
	return 0;
}