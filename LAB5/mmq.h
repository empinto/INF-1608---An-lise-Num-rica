#include "matriz.h"
#include "sistlinear.h"
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

void MMQ (int m, int n, double** A, double* b, double* x);

double RMSE(int m, int n, double** A, double* b, double* x);

double periodico(int n, double* t, double* v, double* c);