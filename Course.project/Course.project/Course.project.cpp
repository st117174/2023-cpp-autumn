#include <iostream>
#include "Cramer.h"

int main(int argc, char* argv[])
{
	std::cout << "CALCULATOR FOR SOLVING OF SYSTEM OF LINEAR EQUATIONS BY CRAMER'S RULE" << std::endl << "------------------------------------------------" << std::endl << std::endl;
	std::cout << "Please enter the number of unknowns:" << std::endl;
	int n = 0;
	std::cin >> n;

	std::cout << std::endl << std::endl << "Input the matrix of coefficients:" << std::endl;
	double matrix[100][100];
	initializeMatrix(matrix, n);
	std::cout << std::endl;

	if (check(matrix, n))
	{
		std::cout << determinant(matrix, n) << std::endl;
		std::cout << "The determinant of the matrix of coefficients equals to zero, so that the system cannot be solved!";
	}

	else if (!check(matrix, n))
	{
		std::cout << "Please input the vector b:" << std::endl;
		double vectorB[100];
		initializeColumn(vectorB, n);
		std::cout << std::endl;

		std::cout << "The system of linear equations looks like this:" << std::endl;
		showSystem(matrix, vectorB, n);
		std::cout << std::endl << std::endl << std::endl;

		wholeSolution(matrix, vectorB, n);
	}
	
	
	
	
	return EXIT_SUCCESS;
}