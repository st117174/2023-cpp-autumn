#ifndef Cramerh
#define Cramerh

void initializeMatrix(double matrix[][100], int n);
double determinant(double matrix[][100], int n);
void initializeColumn(double column[100], int n);
void showSystem(double matrix[][100], double column[100], int n);
void colChange(double matrix[][100], double column[100], double matrixI[][100], int i, int n);
void wholeSolution(double matrix[][100], double column[100], int n);
bool check(double matrix[][100], int n);
void solutionAA(double matrix[][100], double column[100], int n, int i);

#endif
