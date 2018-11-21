#include "interp.h"
#include<conio.h>
#include<stdlib.h>

double fatorial(double x)
{
	if (x == 0)
		return 1;

	return (x * fatorial(x - 1));
}

void main()
{
	double a = 0.0, b = PI / 2, j, valorNewton, valorCos, limChebyshev;
	int n = 6, i;

	double* xi = vetcria(n);
	double* bi = vetcria(n);

	Chebyshev(n, a, b, xi);

	NewtonCoef(n, xi, cos, bi);

	for (i = 0; i < n; i++)
		printf("Amostra x%d: %g\n", i, xi[i]);

	printf("\n");

	for (i = 0; i < n; i++)
		printf("Coeficiente b%d: %g\n", i, bi[i]);

	printf("\n");

	limChebyshev = (pow((b - a) / 2, n) / pow(2, n - 1)) * (1 / fatorial(n));

	for (j = a; j < b; j += 0.15)
	{
		valorNewton = NewtonAval(n, xi, bi, j);
		valorCos = cos(j);

		printf("NewtonAval: %g \tcos: %g \tNewtonAval - cos: %g \tLim. Chebyshev: %g\n", valorNewton, valorCos, fabs(valorNewton - valorCos), limChebyshev);
	}

	vetlibera(xi);

	vetlibera(bi);

	getch();
}