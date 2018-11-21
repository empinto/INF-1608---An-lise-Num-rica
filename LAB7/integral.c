#include "integral.h"

double derivada (double (*f) (double x), double x, double h)
{
	return (f(x + h) - f(x - h)) / (2 * h);
}

double h_otimo (double (*f) (double x), double (*fl) (double x), double x)
{
	int i = 0;
	double h, derivadaNumerica, derivadaAnalitica, erro;

	for (i = 12; i > 0; i--)
	{
		h = pow(10.0, -i);

		derivadaNumerica = derivada(f, x, h);
		derivadaAnalitica = fl(x);

		erro = fabs(derivadaNumerica - derivadaAnalitica);

		if (erro <= h)
			break;
	}

	return erro;
}

double simpson (double (*f) (double), double a, double b, int n)
{
	double h = (b - a) / n;
	double meio = (a + b) / 2;


	return (h / 6) * (f(a) + 4 * f(meio) + f(b)); // 0,25 * (0,00 + ___ + )
}