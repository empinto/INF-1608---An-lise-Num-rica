#include "mmq.h"
#include <stdio.h>

void MMQ (int m, int n, double** A, double* b, double* x)
{
	int i, j;

	int* permutacao = (int*) malloc(m * sizeof(int));

	double* AtxB = vetcria(n);

	double** At = matcria(n, m);
	double** AtxA = matcria(n, n);

	transposta(m, n, A, At);
	
	multmm(n, m, n, At, A, AtxA);

	fatoracao(n, AtxA, permutacao);

	multmv(n, m, At, b, AtxB);

	substituicao(n, AtxA, permutacao, AtxB, x);

	free(permutacao);
	vetlibera(AtxB);
	matlibera(n, At);
	matlibera(n, AtxA);
}

double RMSE(int m, int n, double** A, double* b, double* x)
{
	int i;

	double erro = 0;

	double* r = vetcria(m);
	double* Axx = vetcria(m);

	multmv(m, n, A, x, Axx);

	for (i = 0; i < m; i++)
		r[i] = b[i] - Axx[i];

	erro = norma2(m, r) / sqrt((double)m);

	vetlibera(Axx);
	vetlibera(r);

	return erro;
}

double periodico(int n, double* t, double* v, double* c)
{
	int i, coluna = 5;

	double erro;

	double** A = matcria(n, coluna);

	for(i = 0; i < n; i++)
	{
		A[i][0] = 1;
		A[i][1] = t[i];
		A[i][2] = sin(2 * PI * t[i]);
		A[i][3] = cos(2 * PI * t[i]);
		A[i][4] = cos(4 * PI * t[i]);
	}

	MMQ(n, coluna, A, v, c);

	erro = RMSE(n, coluna, A, v, c);

	matlibera(n, A);

	return erro;
}