﻿#include <iostream>

typedef unsigned int uint;

int main(int argc, char**)
{
    uint a = 0;
    std::cin >> a;
    const int BITS = sizeof(uint) * 8;

    {
        for (int i = 0; i < BITS; ++i)
        {
            std::cout << (a >> (31 - i) & 1) << ((i + 1) % 4 == 0 ? " " : "");
        }
        std::cout << std::endl;
    }

    {
        int sumbits = 0;
        for (int i = 0; i < BITS; ++i)
        {
            sumbits += (a >> i) & 1;
        }
        std::cout << sumbits << std::endl << std::endl;
    }

    {
        uint a1 = 0;
        std::cin >> a1;
        uint b = 0;
        std::cin >> b;
        uint c = 0;

        bool up = 0;
        for (int i = 0; i < BITS; ++i)
        {
            bool bitA = ((a1 >> i) & 1);
            bool bitB = ((b >> i) & 1);
            bool current = bitA ^ bitB ^ up;
            up = (bitA & bitB) | (bitA & up) | (bitB & up);
            c = c | ((int)current << i);
        }
        std::cout << a1 << " + " << b << " = " << c << std::endl;
    }

    return EXIT_SUCCESS;
}
