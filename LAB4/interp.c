#include "interp.h"

void Chebyshev(int n, double a, double b, double* xi)
{
	int beta = 1, i = 0;

	for(beta = 1; beta <= (2 * n) - 1; beta += 2)
	{
		xi[i] = ((b - a) / 2) * cos((beta * PI) / (2 * n)) + ((a + b) / 2);

		i++;
	}
}

void NewtonCoef(int n, double* xi, double (*f) (double), double* bi)
{
	int i, j;

	double** matriz = matcria(n, n);
	
	for(j = 0; j < n; j++)
	{
		for(i = n-1; i >= 0; i--)
		{
			if (i > j)
				continue;

			if (i == j)
				matriz[i][j] = f(xi[i]);
			else
				matriz[i][j] = (matriz[i+1][j] - matriz[i][j-1]) / (xi[j] - xi[i]);

			if (i == 0)
				bi[j] = matriz[i][j];
		}
	}

	matlibera(n, matriz);
}

double NewtonAval(int n, double* xi, double* bi, double x)
{
	int i;
	double valor = 0.0;

	for (i = n - 1; i >= 0; i--)
	{
		if (i > 0)
			valor = (bi[i] + valor) * (x - xi[i - 1]);
		else
			valor += bi[i];
	}

	return valor;
}