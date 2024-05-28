// cramer.cpp
#include "Cramer.h"
#include <cmath>
#include <iostream>

CVector::CVector(int size) : n(size) {
    elements = new double[n];
}

CVector::CVector(const CVector& other) : n(other.n) {
    elements = new double[n];
    for (int i = 0; i < n; ++i) {
        elements[i] = other.elements[i];
    }
}

CVector::~CVector() {
    delete[] elements;
}

double& CVector::operator[](int index) {
    return elements[index];
}

const double& CVector::operator[](int index) const {
    return elements[index];
}

int CVector::size() const {
    return n;
}

CMatrix::CMatrix(int size) : n(size) {
    elements = new double* [n];
    for (int i = 0; i < n; ++i) {
        elements[i] = new double[n];
    }
}

CMatrix::CMatrix(const CMatrix& other) : n(other.n) {
    elements = new double* [n];
    for (int i = 0; i < n; ++i) {
        elements[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            elements[i][j] = other.elements[i][j];
        }
    }
}

CMatrix::~CMatrix() {
    for (int i = 0; i < n; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

double* CMatrix::operator[](int index) {
    return elements[index];
}

const double* CMatrix::operator[](int index) const {
    return elements[index];
}

int CMatrix::size() const {
    return n;
}

double CMatrix::det() const {
    return determinant(elements, n);
}



double determinant(double** matrix, int n)
{
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

void CMatrix::initializeMatrix()
{
    for (int i = 0; i < n; ++i) {

        for (int j = 0; j < n; ++j) {
            std::cout << "Enter coefficient for x_" << j + 1 << " in equation " << i + 1 << ": ";
            std::cin >> elements[i][j];
        }
    }
    std::cout << std::endl;
}

void CVector::initializeVector()
{
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter constant for equation " << i + 1 << ": ";
        std::cin >> elements[i];
    }
    std::cout << std::endl;
}

void CMatrix::replaceColumn(CVector b, int colIndex) {

    for (int i = 0; i < n; ++i) {
        elements[i][colIndex] = b[i];
    }

}

void outputSystemLaTeX(std::ofstream& outfile, CMatrix A, CVector b) {
    int n = A.size();
    outfile << "\\begin{equation}\n\\left\\{\\begin{array}{" << std::string(n, 'r') << "}\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0 && A[i][j] >= 0) outfile << "+";
            outfile << A[i][j] << "x_{" << j + 1 << "} ";
        }
        outfile << " = " << b[i] << " \\\\\n";
    }
    outfile << "\\end{array}\\right.\n\\end{equation}\n";
}

void outputSolutionStepsLaTeX(std::ofstream& outfile, CMatrix A, CVector b, double* solutions) {
    int n = A.size();
    double detA = A.det();
    outfile << "\\begin{equation}\n\\text{Determinant of } A: \\; \\Delta = ";
    latexDet(outfile, A);
    outfile << " = " << detA << "\n\\end{equation}\n";

    for (int i = 0; i < n; ++i) {
        CMatrix Ai(n);
        for (int j = 0; j < n; ++j) {

            for (int k = 0; k < n; ++k) {
                Ai[j][k] = A[j][k];
            }
        }
        Ai.replaceColumn(b, i);
        double detAi = Ai.det();
        outfile << "\\begin{equation}\n\\Delta_{" << i + 1 << "} = ";
        latexDet(outfile, Ai);
       outfile << " = " << detAi << "\n\\end{equation}\n";
        outfile << "\\begin{equation}\nx_{" << i + 1 << "} = \\frac{\\Delta_{" << i + 1 << "}}{\\Delta} = \\frac{" << detAi << "}{" << detA << "} = " << solutions[i] << "\n\\end{equation}\n";

    }
}

void solveSystem(CMatrix A, CVector b, double* solutions, int n) {
    double detA = A.det();
    for (int i = 0; i < n; ++i) {
        CMatrix Ai = A;
        Ai.replaceColumn(b, i);
        solutions[i] = Ai.det() / detA;
    }
}

void latexDet(std::ofstream& outfile, CMatrix A)
{
    int n = A.size();
    outfile << "det\\begin{vmatrix}\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            outfile << A[i][j] << " & ";
        }
        outfile << A[i][n - 1] << "\\" << "\\" << std::endl;
    }
    outfile << "\\end{vmatrix}";
}