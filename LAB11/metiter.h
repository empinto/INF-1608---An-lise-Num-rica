#include "matriz.h"
#include<stdio.h>
#include<string.h>

int Jacobi (int n, double** A, double* b, double* x, double tol);

int GaussSeidel(int n, double** A, double* b, double* x, double tol);