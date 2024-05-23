// cramer.h
#ifndef CRAMER_H
#define CRAMER_H

#include <fstream>

double determinant(double** matrix, int n);
void replaceColumn(double** matrix, double* column, int colIndex, int n);
void outputSystemLaTeX(std::ofstream& outfile, double** A, double* b, int n);
void outputSolutionStepsLaTeX(std::ofstream& outfile, double** A, double* b, double* solutions, int n);
void solveSystem(double** A, double* b, double* solutions, int n);

#endif