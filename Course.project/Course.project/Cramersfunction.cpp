#include <iostream>
#include "Cramer.h"

double determinant(double matrix[][100], int n)
{
    double submatrix[100][100];

    if (n == 1) {
        return matrix[0][0];
    }
    else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        double det = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k < i) {
                        submatrix[j - 1][k] = matrix[j][k];
                    }
                    else if (k > i) {
                        submatrix[j - 1][k - 1] = matrix[j][k];
                    }
                }
            }
            det += pow(-1, i) * matrix[0][i] * determinant(submatrix, n - 1);
        }
        return det;
    }
}

void initializeMatrix(double matrix[][100], int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void initializeColumn(double column[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> column[i];
    }
}

void showSystem(double matrix[][100], double column[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            std::cout << "x_" << j + 1 << "*" << matrix[i][j] << " + ";
        }
        std::cout << "x_" << n << "*" << matrix[i][n - 1] << " = " << column[i] << std::endl;
    }
}

void colChange(double matrix[][100], double column[100], double matrixI[][100], int i, int n)
{
    for (int j = 0; j < n; ++j)
    {
        for (int k = 0; k < n; ++k)
        {
            if (k != i)
            {
                matrixI[j][k] = matrix[j][k];
            }
            if (k == i)
            {
                matrixI[j][k] = column[j];
            }
        }
    }
}

bool check(double matrix[][100], int  n)
{
    if (determinant(matrix, n) != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void solutionAA(double matrix[][100], double column[100], int n, int i)
{
    double matrixI[100][100];
    colChange(matrix, column, matrixI, i, n);
   std::cout << "x_" << i + 1 << " = " << determinant(matrixI, n) / determinant(matrix, n) << std::endl<< std::endl;
}

void wholeSolution(double matrix[][100], double column[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        solutionAA(matrix, column, n, i);
    }
}