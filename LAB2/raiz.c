#include "raiz.h"

int bissecao(double a, double b, int p, double (*f) (double c), double* r)
{
	int numeroIteracoes = 0;
	double valorA = f(a), valorB = f(b), c, valorC, erro;

	*r = -1.0;

	if (valorA * valorB >= 0.0)
	{
		perror("Não foi possível aplicar o método da bisseção. f(a) * f(b) >= 0");
		return - 1;
	}

	erro = 0.5 * pow(10.0, -p);

	while ((b - a) / 2 > erro)
	{
		c = (a + b) / 2;

		*r = c;

		valorC = f(c);
		if (fabs(valorC) < 1e-15)
			break;

		if (valorA * valorC < 0.0)
			b = c;
		else
			a = c;

		numeroIteracoes++;
	}

	return numeroIteracoes;
}

int IQI(double x0, double x1, double x2, int p, double (*f) (double x), double* r)
{
	double A[3][3] = {0}, Ac[3][3] = {0};

	int numeroIteracoes = 0, maxIteracoes = 100;
	double valorX0 = f(x0), valorX1 = f(x1), valorX2 = f(x2), erro, c, determinanteA, determinanteAc;

	*r = valorX2;

	erro = 0.5 * pow(10.0, -p);

	while(fabs(valorX2) > erro)
	{
		if (numeroIteracoes == maxIteracoes || fabs(*r) >= 1e7)
			return 0;

		A[0][0] = valorX0 * valorX0;
		A[0][1] = valorX0;
		A[0][2] = 1;
		A[1][0] = valorX1 * valorX1;
		A[1][1] = valorX1;
		A[1][2] = 1;
		A[2][0] = valorX2 * valorX2;
		A[2][1] = valorX2;
		A[2][2] = 1;
	
		determinanteA = A[0][0] * ((A[1][1] * A[2][2]) - (A[2][1] * A[1][2])) - 
						A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + 
						A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

		Ac[0][0] = valorX0 * valorX0;
		Ac[0][1] = valorX0;
		Ac[0][2] = x0;
		Ac[1][0] = valorX1 * valorX1;
		Ac[1][1] = valorX1;
		Ac[1][2] = x1;
		Ac[2][0] = valorX2 * valorX2;
		Ac[2][1] = valorX2;
		Ac[2][2] = x2;

		determinanteAc = Ac[0][0] * ((Ac[1][1] * Ac[2][2]) - (Ac[2][1] * Ac[1][2])) - 
						Ac[0][1] * (Ac[1][0] * Ac[2][2] - Ac[2][0] * Ac[1][2]) + 
						Ac[0][2] * (Ac[1][0] * Ac[2][1] - Ac[2][0] * Ac[1][1]);

		c = determinanteAc / determinanteA;

		x0 = x1;
		x1 = x2;
		x2 = c;

		valorX0 = valorX1;
		valorX1 = valorX2;
		valorX2 = f(x2);

		*r = c;

		numeroIteracoes++;
	}

	return numeroIteracoes;
}