#include "integral.h"
#include<conio.h>
#include<stdio.h>

double f(double x)
{
	return cos(x) - 2 * sin(x);
}

double f1(double x)
{
	return -sin(x) - 2 * cos(x);
}

double fi1(double x)
{
	return x / sqrt(x * x + 9);
}

void main()
{
	double x, a, b, n;

	double hO = h_otimo(f, f1, 0.0);

	printf("h otimo: %g", hO);

	a = 0;
	b = 4;
	n = 16;

	x = simpson(fi1, a, b, n);

	printf("\nx: %g", x);

	getch();

	return;
}