// main.cpp
#include <iostream>
#include <fstream>
#include "cramer.h"



int main() {
    int n;
    std::cout << "Enter the number of variables: ";
    std::cin >> n;

    double** A = new double* [n];
    double* b = new double[n];
    double* solutions = new double[n];

    for (int i = 0; i < n; ++i) {
        A[i] = new double[n];
    }

    std::cout << "Enter the coefficients of matrix A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Enter coefficient for x_" << j + 1 << " in equation " << i + 1 << ": ";
            std::cin >> A[i][j];
        }
    }

    std::cout << "Enter the constants vector b:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter constant for equation " << i + 1 << ": ";
        std::cin >> b[i];
    }

    std::ofstream outfile("solution.tex");
        outfile << "\\documentclass{article}\n\\usepackage{amsmath}\n\\begin{document}\n";
        outfile << "\\section*{Complete Solution of the System of Linear Equations}\n";
        outputSystemLaTeX(outfile, A, b, n);

    double detA = 0;
   detA = determinant(A, n); 

    if (detA == 0) {
        outfile << "\\text{The determinant of matrix of coefficients equals to zero. The system is unsolvable}\n";
        outfile << "\\end{document}\n";
        outfile.close();
        std::cerr << "The system does not have a unique solution." << std::endl;
    }

    else if (detA != 0)
    {
        solveSystem(A, b, solutions, n);

       
        outfile << "\\section*{Solution using Cramer's Method}\n";
        outputSolutionStepsLaTeX(outfile, A, b, solutions, n);
        outfile << "\\section*{Answer}\n";
        outfile << "\\begin{equation}\n\\left\\{\\begin{array}{r}\n";
        for (int i = 0; i < n; ++i) {
            outfile << "x_{" << i + 1 << "} = " << solutions[i] << "\\\\\n";
        }
        outfile << "\\end{array}\\right.\n\\end{equation}\n";
        outfile << "\\end{document}\n";
        outfile.close();

        std::cout << "Solution written to solution.tex" << std::endl;

        std::cout << "Solution:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "x_" << i + 1 << " = " << solutions[i] << std::endl;
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] solutions;

    return 0;
}