#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int n = 0;
	int m = 0;
	if (a == 100)
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		n = a / 10;
		m = a % 10;
		switch (n)
		{ 
		case 1:
			std::cout << "X";
			break;
		case 2:
			std::cout << "XX";
			break;
		case 3:
			std::cout << "XXX";
			break;
		case 4:
			std::cout << "XL";
			break;
		case 5:
			std::cout << "L";
			break;
		case 6:
			std::cout << "LX";
			break;
		case 7:
			std::cout << "LXX";
			break;
		case 8:
			std::cout << "LXXX";
			break;
		case 9:
			std::cout << "XC";
			break;
		}
		switch (m)
		{
		case 1:
			std::cout << "I";
			break;

		case 2:
			std::cout << "II";
			break;
		case 3:
				std::cout << "III";
				break;
		case 4:
			std::cout << "IV";
			break;
		case 5:
			std::cout << "V";
			break;
		case 6:
			std::cout << "VI";
			break;
		case 7:
			std::cout << "VII";
			break;
		case 8:
			std::cout << "VIII";
			break;
		case 9:
			std::cout << "IX";
			break;
		}
	}
	return EXIT_SUCCESS;
}