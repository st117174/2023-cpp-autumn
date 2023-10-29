#ifndef Arrayjobh
#define Arrayjobh

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void printMenu();
void contractArray(int*& a, int& len);
int extractElement(int*& a, int& len, int index);
void reverse(int* a, int len);
void sorting(int*& a, int& len);
void maxnmin(int*& a, int len);
void deleterep(int*& a, int& len);
void addrnd(int*& a, int& len, int n);

#endif