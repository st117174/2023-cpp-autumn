// cramer.h
#ifndef CRAMER_H
#define CRAMER_H

#include <fstream>

class CVector {
public:
    CVector(int size);
    CVector(const CVector& other);
    ~CVector();
    double& operator[](int index);
    const double& operator[](int index) const;
    int size() const;
    void initializeVector();

private:
    double* elements;
    int n;
};

class CMatrix {
public:
    CMatrix(int size);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    double* operator[](int index);
    const double* operator[](int index) const;
    int size() const;
    double det() const;
    void initializeMatrix();
    void replaceColumn(CVector b, int colIndex);


private:
    double** elements;
    int n;
};



void latexDet(std::ofstream& outfile, CMatrix A);
double determinant(double** matrix, int n);
void outputSystemLaTeX(std::ofstream& outfile, CMatrix A, CVector b);
void outputSolutionStepsLaTeX(std::ofstream& outfile, CMatrix A, CVector b, double* solutions);
void solveSystem(CMatrix A, CVector b, double* solutions, int n);

#endif