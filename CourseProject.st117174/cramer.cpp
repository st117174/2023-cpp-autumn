// cramer.cpp
#include "cramer.h"
#include <cmath>
#include <istream>

double determinant(double** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    double det = 0;
    double** submatrix = new double* [n - 1];
    for (int i = 0; i < n - 1; ++i) {
        submatrix[i] = new double[n - 1];
    }
    for (int x = 0; x < n; ++x) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == x) continue;
                submatrix[subi][subj] = matrix[i][j];
                ++subj;
            }
            ++subi;
        }
        det += (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
    }
    for (int i = 0; i < n - 1; ++i) {
        delete[] submatrix[i];
    }
    delete[] submatrix;
    return det;
}

void replaceColumn(double** matrix, double* column, int colIndex, int n) {
    for (int i = 0; i < n; ++i) {
        matrix[i][colIndex] = column[i];
    }
}

void outputSystemLaTeX(std::ofstream& outfile, double** A, double* b, int n) {
    outfile << "\\begin{equation}\n\\left\\{\\begin{array}{" << std::string(n, 'r') << "}\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0 && A[i][j] >= 0) outfile << "+";
            outfile << A[i][j] << "x_{" << j + 1 << "} ";
        }
        outfile << " &= " << b[i] << " \\\\\n";
    }
    outfile << "\\end{array}\\right.\n\\end{equation}\n";
}

void outputSolutionStepsLaTeX(std::ofstream& outfile, double** A, double* b, double* solutions, int n) {
    double detA = determinant(A, n);
    outfile << "\\begin{equation}\n\\text{Determinant of } A: \\; \\Delta = " << detA << "\n\\end{equation}\n";

    for (int i = 0; i < n; ++i) {
        double** Ai = new double* [n];
        for (int j = 0; j < n; ++j) {
            Ai[j] = new double[n];
            for (int k = 0; k < n; ++k) {
                Ai[j][k] = A[j][k];
            }
        }
        replaceColumn(Ai, b, i, n);
        double detAi = determinant(Ai, n);
        outfile << "\\begin{equation}\n\\Delta_{" << i + 1 << "} = " << detAi << "\n\\end{equation}\n";
        outfile << "\\begin{equation}\nx_{" << i + 1 << "} = \\frac{\\Delta_{" << i + 1 << "}}{\\Delta} = \\frac{" << detAi << "}{" << detA << "} = " << solutions[i] << "\n\\end{equation}\n";
        for (int j = 0; j < n; ++j) {
            delete[] Ai[j];
        }
        delete[] Ai;
    }
}

void solveSystem(double** A, double* b, double* solutions, int n) {
   double detA = determinant(A, n);
    for (int i = 0; i < n; ++i) {
        double** Ai = new double* [n];
        for (int j = 0; j < n; ++j) {
            Ai[j] = new double[n];
            for (int k = 0; k < n; ++k) {
                Ai[j][k] = A[j][k];
            }
        }
        replaceColumn(Ai, b, i, n);
        solutions[i] = determinant(Ai, n) / detA;
        for (int j = 0; j < n; ++j) {
            delete[] Ai[j];
        }
        delete[] Ai;
    }
}