#include "metiter.h"

void DecomporMatriz(int n, double** A, double** L, double** D_1, double** U)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i < j)
			{
				L[i][j] = 0.0;
				D_1[i][j] = 0.0;
				U[i][j] = A[i][j];
			}
			else if (i == j)
			{
				L[i][j] = 0;
				if (A[i][j] != 0.0)
					D_1[i][j] = 1.0 / A[i][j];
				else
					D_1[i][j] = 0.0;

				U[i][j] = 0.0;
			}
			else
			{
				L[i][j] = A[i][j];
				D_1[i][j] = 0.0;
				U[i][j] = 0.0;
			}
		}
	}
}



void SomarMatrizes(int n, double** A, double** B, double** C)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void SubtrairVetores(int n, double* u, double* v, double* w)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		w[i] = u[i] - v[i];
	}
}

int Jacobi (int n, double** A, double* b, double* x, double tol)
{
	double** L;
	double** D_1;
	double** U;

	double** LU;

	double* LUx;

	double* b_LUx;

	double* x1;

	double* x1_x;

	int numIter = 0;
	
	L = matcria(n, n);
	D_1 = matcria(n, n);
	U = matcria(n, n);

	LU = matcria(n, n);

	LUx = vetcria(n);

	b_LUx = vetcria(n);

	x1 = vetcria(n);

	memcpy(x1, x, n * sizeof(double));

	x1_x = vetcria(n);

	DecomporMatriz(n, A, L, D_1, U);

	SomarMatrizes(n, L, U, LU);

	do
	{
		multmv(n, n, LU, x, LUx);

		SubtrairVetores(n, b, LUx, b_LUx);

		multmv(n, n, D_1, b_LUx, x1);

		SubtrairVetores(n, x1, x, x1_x);

		memcpy(x, x1, n * sizeof(double));

		numIter++;
	}
	while (norma2(n, x1_x) > tol);

	matlibera(n, L);
	matlibera(n, D_1);
	matlibera(n, U);

	matlibera(n, LU);

	vetlibera(LUx);
	vetlibera(b_LUx);
	vetlibera(x1);
	vetlibera(x1_x);

	return numIter;
}

int GaussSeidel(int n, double** A, double* b, double* x, double tol)
{
	double** L;
	double** D_1;
	double** U;

	double* Ux;

	double* b_Ux;
	double* b_Ux_Lx1;

	double* x1;

	double* x1_x;

	double* w;

	w = vetcria(n);

	int numIter = 0;

	L = matcria(n, n);
	D_1 = matcria(n, n);
	U = matcria(n, n);
	
	Ux = vetcria(n);

	b_Ux = vetcria(n);
	b_Ux_Lx1 = vetcria(n);

	x1 = vetcria(n);

	x1_x = vetcria(n);

	DecomporMatriz(n, A, L, D_1, U);

	do
	{
		memcpy(x1, x, n * sizeof(double));

		multmv(n, n, U, x, Ux);

		SubtrairVetores(n, b, Ux, b_Ux);

		multmv(n, n, L, x, w);

		memcpy(x, w, n * sizeof(double));

		SubtrairVetores(n, b_Ux, x, b_Ux_Lx1);

		multmv(n, n, D_1, b_Ux_Lx1, x);

		SubtrairVetores(n, x, x1, x1_x);

		numIter++;
	} while (norma2(n, x1_x) > tol);

	matlibera(n, L);
	matlibera(n, D_1);
	matlibera(n, U);

	vetlibera(Ux);
	vetlibera(b_Ux);
	vetlibera(b_Ux_Lx1);
	vetlibera(x1);
	vetlibera(x1_x);

	vetlibera(w);

	return numIter;
}