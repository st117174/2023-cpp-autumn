#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Arrayjob.h"
int main(int argc, char* argv[])
{
    int len = 0;
    bool exit = 0;
    int* a = nullptr;
    while (!exit)
    {
        {  system("cls");
        printMenu();
        printArray(a, len);
        }
        int choice = 0;
        {
            std::cin >> choice;
        }
        {
            switch (choice)
            {
            case 0:
                exit = true;
                break;
            case 1:
                printArray(a, len);
                system("pause");
                break;
            case 2:
            {
                int element = 0;
                std::cout << "Input element to add: ";
                std::cin >> element;
                addElement(a, len, element);
                break;
            }
            case 3:
            {
                int index = 0;
                std::cout << "Input index to extract: ";
                std::cin >> index;
                std::cout << "Extracted  " << extractElement(a, len, index) << std::endl;
                break;
            }
            case 4:
            {
                sorting(a, len);
            }
            case 5:
            {
                reverse(a, len);
                system("pause");
                break;
            }
            case 6:
            {
                maxnmin(a, len);
            }
            case 7:
            {
                deleterep(a, len);
            }
            case 8:
            {
                std::cout << "Input number of new random elements: ";
                int n = 0;
                std::cin >> n;
                addrnd(a, len, n);
            }
            default:
                std::cout << "Unknown command" << std::endl;
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}