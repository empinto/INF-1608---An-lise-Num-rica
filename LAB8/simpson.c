#include "simpson.h"

double DoubleSimpson (double a, double b, double (*f) (double x), double* v)
{
	double h = b - a;
	double c = (a + b) / 2.0;
	double aux, erro;
	double Sab, Sac, Scb;

	Sab = (h / 6.0) * (f(a) + 4.0 * f(c) + f(b));
		
	h = c - a;
	aux = c;
	c = (a + c) / 2.0;

	Sac = (h / 6.0) * (f(a) + 4.0 * f(c) + f(aux));

	c = aux;
	h = b - c;
	c = (c + b) / 2.0;
		
	Scb = (h / 6.0) * (f(aux) + 4.0 * f(c) + f(b));

	erro = fabs(Sab - Sac - Scb) / 15.0;
 
	*v = Sac + Scb - erro;

	return erro;
}

double AdaptiveSimpson (double a, double b, double (*f) (double x), double tol)
{
	double v;
	double erro = DoubleSimpson(a, b, f, &v);
	double m = (a + b) / 2.0;

	if (erro > tol)
		return AdaptiveSimpson(a, m, f, tol / 2.0) + AdaptiveSimpson(m, b, f, tol / 2.0);

	return v;
}

double Quadratura2 (double a, double b, double (*f) (double x))
{
	return 1.0 * f(((b - a) * (-sqrt(1.0 / 3.0)) + b + a) / 2.0) * ((b - a) / 2.0) + 
		1.0 * f(((b - a) * (sqrt(1.0 / 3.0)) + b + a) / 2.0) * ((b - a) / 2.0);
}

double Quadratura3 (double a, double b, double (*f) (double x))
{
	return (5.0 / 9.0) * f(((b - a) * (-sqrt(3.0 / 5.0)) + b + a) / 2.0) * ((b - a) / 2.0) +
		(8.0 / 9.0) * f(((b - a) * (0.0) + b + a) / 2.0) * ((b - a) / 2.0) + 
		(5.0 / 9.0) * f(((b - a) * (sqrt(3.0 / 5.0)) + b + a) / 2.0) * ((b - a) / 2.0);
}