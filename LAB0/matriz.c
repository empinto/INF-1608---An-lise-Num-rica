#include "matriz.h"

double* vetcria(int n)
{
	if (n < 0)
		return NULL;

	return (double*)malloc(n * sizeof(double));
}

void vetlibera(double* v)
{
	free(v);
}

double escalar(int n, double* v, double* w)
{
	double produtoEscalar = 0.0;

	int i;

	if (v == NULL || w == NULL)
	{
		perror("Não é possível calcular o produto escalar pois pelo menos um dos vetores é nulo.");
		return produtoEscalar;
	}

	for(i = 0; i < n; i++)
		produtoEscalar += v[i] * w[i];

	return produtoEscalar;
}

double norma2(int n, double* v)
{
	double norma2 = 0.0;
	double expoente = 2.0;

	int i;

	for(i = 0; i < n; i++)
		norma2 += pow(v[i], expoente);

	return sqrt(norma2);
}

double** matcria(int m, int n)
{
	double** matriz;
	int i;

	if (m < 0)
		return NULL;

	matriz = (double**)malloc(m * sizeof(double*));

	if (matriz == NULL)
		return matriz;

	for(i = 0; i < m; i++)
		matriz[i] = vetcria(n);

	return matriz;
}

void matlibera(int m, double** A)
{
	int i;

	for(i = 0; i < m; i++)
		vetlibera(A[i]);

	free(A);
}

void transposta(int m, int n, double** A, double** T)
{
	int i;
	int j;

	if (A == NULL || T == NULL)
	{
		perror("Não é possível calcular a transposta pois pelo menos uma das matrizes é nula.");
		return;
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			T[j][i] = A[i][j];
	}
}

void multmv(int m, int n, double** A, double* v, double* w)
{
	int i;

	if (A == NULL || v == NULL || w == NULL)
	{
		perror("Não é possível calcular a multiplicação matriz * vetor pois pelo menos um deles ou o vetor resultado é nulo.");
		return;
	}

	for(i = 0; i < m; i++)
		w[i] = escalar(n, A[i], v);
}

void multmm(int m, int n, int q, double** A, double** B, double** C)
{
	int i;
	int j;
	int k;

	double produto = 0.0;

	if (A == NULL || B == NULL || C == NULL)
	{
		perror("Não é possível calcular a multiplicação matriz * matriz pois pelo menos uma delas ou a matriz resultado é nula.");
		return;
	}

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < q; j++)
		{
			for(k = 0; k < n; k++)
				produto += A[i][k] * B[k][j];

			C[i][j] = produto;
			produto = 0.0;
		}
	}
}