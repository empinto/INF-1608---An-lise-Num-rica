#include "sistlinear.h"
#include <stdlib.h>
#include <math.h>
 
void fatoracao (int n, double** a, int* p)
{
	int i, j, m, k, t;
	double f, td;

  for (i=0; i<n; ++i)
    p[i] = i;
  for (j=0; j<n-1; ++j) {
    // find pivô
    m = j;
    for (i=j+1; i<n; ++i)
      if (fabs(a[i][j]) > fabs(a[m][j]))
        m = i;
    // swap lines: j <-> m
    for (k=0; k<n; ++k) {
      td = a[j][k];
      a[j][k] = a[m][k];
      a[m][k] = td;
    }
    // register permutation
    t = p[j];
    p[j] = p[m];
    p[m] = t;
    // elimination
    for (i=j+1; i<n; ++i) {
      f = a[i][j]/a[j][j];
      for (k=j+1; k<n; ++k)
        a[i][k] -= f*a[j][k];
      a[i][j] = f;
    }
  }
}

void substituicao (int n, double** a, int* p, double* b, double* x)
{
	int i, j;
	double s;

  // forward substitution
  for (i=0; i<n; ++i) {
    s = 0;
    for (j=0; j<i; ++j) 
      s += a[i][j]*x[j];
    x[i] = b[p[i]] - s;
  }
  // backward substitution
  for (i=n-1; i>=0; --i) {
    s = 0;
    for (j=i+1; j<n; ++j) 
      s += a[i][j]*x[j];
    x[i] = (x[i] - s) / a[i][i];
  }
}


