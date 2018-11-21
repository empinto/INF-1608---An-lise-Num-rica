#include "metiter.h"
#include<conio.h>
#include<math.h>

int main()
{
	int n = 2, numIter;
	double** A;
	double* b;
	double* x;
	double tol = pow(10.0, -7);

	x = vetcria(n);
	b = vetcria(n);
	A = matcria(n, n);

	x[0] = 0;
	x[1] = 0;

	b[0] = 5;
	b[1] = 5;

	A[0][0] = 3;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 2;

	numIter = Jacobi(n, A, b, x, tol);

	printf("Jacobi: \tNum Iter: %d\t x: [%g %g]\n", numIter, x[0], x[1]);

	x[0] = 0;
	x[1] = 0;

	numIter = GaussSeidel(n, A, b, x, tol);

	printf("Gaus-Seidel: \tNum Iter: %d\t x: [%g %g]\n", numIter, x[0], x[1]);

	_getch();

	matlibera(n, A);
	vetlibera(b);
	vetlibera(x);

	return 0;
}