// main.cpp
#include <iostream>
#include <fstream>
#include "cramer.h"
#include <cstdlib>



int main(int argc, char* argv[]) {
    int n;
    std::cout << "Enter the number of variables: ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cerr << "The number of variables must be more than zero!";
    }

    CMatrix A(n);
   CVector b(n);
    double* solutions = new double[n];

   
    std::cout << "Enter the coefficients of matrix A:" << std::endl;
    A.initializeMatrix();
    

    std::cout << "Enter the constants vector b:" << std::endl;
    b.initializeVector();
    

    std::ofstream outfile("solution.tex");
        outfile << "\\documentclass{article}\n\\usepackage{amsmath}\n\\begin{document}\n";
        outfile << "\\section*{Solution of the System of Linear Equations:}\n";
        outputSystemLaTeX(outfile, A, b);

    double detA = 0;
   detA = A.det(); 

    if (detA == 0) {
        outfile << "\\text{The determinant of matrix of coefficients equals to zero. The system is unsolvable}\n";
        outfile << "\\end{document}\n";
        outfile.close();
        std::cerr << "The system does not have a unique solution." << std::endl;
    }

    else if (detA != 0)
    {
        solveSystem(A, b, solutions, n);

        outfile << "\\section*{Solution using Cramer's Method:}\n";
        outputSolutionStepsLaTeX(outfile, A, b, solutions);
        outfile << "\\section*{Answer:}\n";
        outfile << "\\begin{equation}\n\\left\\{\\begin{array}{r}\n";
        for (int i = 0; i < n; ++i) {
            outfile << "x_{" << i + 1 << "} = " << solutions[i] << "\\\\\n";
        }
        outfile << "\\end{array}\\right.\n\\end{equation}\n";
        outfile << "\\end{document}\n";
        outfile.close();

        std::cout << "Solution written to solution.tex" << std::endl<< std::endl;

        std::cout << "Solution:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << "x_" << i + 1 << " = " << solutions[i] << std::endl;
        }
    }

    std::string fName = "solution.tex";

    std::string command = "pdflatex " + fName;

    int result = std::system(command.c_str());
    if (result == 0) {
        std::cout << "\n\nPDF file with compiled LaTeX code was generated and saved successfully.\n";
    }
    else {
        std::cout << "\n\nPDF was not generated due to the error.\n";
    }

    


    delete[] solutions;

    return EXIT_SUCCESS;
}