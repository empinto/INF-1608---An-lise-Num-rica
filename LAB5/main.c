#include "mmq.h"
#include <conio.h>

void printfResultado(char item, int n, double* x, double erro)
{
	int i;

	printf("%c)\n(", item);

	for (i = 0; i < n; i++)
		printf("%g\t", x[i]);

	printf(")\t - Erro: %g\n\n", erro);
}

void main()
{
	int m = 5, n = 3;

	double erro = 0;

	double* b = vetcria(m);
	double* x = vetcria(n);

	double* t, *v, *c;

	double** A = matcria(m, n);

	A[0][0] = 3;
	A[0][1] = -1;
	A[0][2] = 2;
	A[1][0] = 4;
	A[1][1] = 1;
	A[1][2] = 0;
	A[2][0] = -3;
	A[2][1] = 2;
	A[2][2] = 1;
	A[3][0] = 1;
	A[3][1] = 1;
	A[3][2] = 5;
	A[4][0] = -2;
	A[4][1] = 0;
	A[4][2] = 3;

	b[0] = 10;
	b[1] = 10;
	b[2] = -5;
	b[3] = 15;
	b[4] = 0;

	MMQ(m, n, A, b, x);

	erro = RMSE(m, n, A, b, x);

	printfResultado('a', n, x, erro);

	vetlibera(b);
	vetlibera(x);

	matlibera(m, A);

	n = 4;

	b = vetcria(m);
	x = vetcria(n);

	A = matcria(m, n);

	A[0][0] = 4;
	A[0][1] = 2;
	A[0][2] = 3;
	A[0][3] = 0;
	A[1][0] = -2;
	A[1][1] = 3;
	A[1][2] = -1;
	A[1][3] = 1;
	A[2][0] = 1;
	A[2][1] = 3;
	A[2][2] = -4;
	A[2][3] = 2;
	A[3][0] = 1;
	A[3][1] = 0;
	A[3][2] = 1;
	A[3][3] = -1;
	A[4][0] = 3;
	A[4][1] = 1;
	A[4][2] = 3;
	A[4][3] = -2;

	b[0] = 10;
	b[1] = 0;
	b[2] = 2;
	b[3] = 0;
	b[4] = 5;

	MMQ(m, n, A, b, x);

	erro = RMSE(m, n, A, b, x);

	printfResultado('b', n, x, erro);

	vetlibera(b);
	vetlibera(x);

	matlibera(m, A);

	n = 24;
	m = 5;

	t = vetcria(n);
	v = vetcria(n);
	c = vetcria(m);

	t[0] = 0.0 / 24.0;
	t[1] = 1.0 / 24.0;
	t[2] = 2.0 / 24.0;
	t[3] = 3.0 / 24.0;
	t[4] = 4.0 / 24.0;
	t[5] = 5.0 / 24.0;
	t[6] = 6.0 / 24.0;
	t[7] = 7.0 / 24.0;
	t[8] = 8.0 / 24.0;
	t[9] = 9.0 / 24.0;
	t[10] = 10.0 / 24.0;
	t[11] = 11.0 / 24.0;
	t[12] = 12.0 / 24.0;
	t[13] = 13.0 / 24.0;
	t[14] = 14.0 / 24.0;
	t[15] = 15.0 / 24.0;
	t[16] = 16.0 / 24.0;
	t[17] = 17.0 / 24.0;
	t[18] = 18.0 / 24.0;
	t[19] = 19.0 / 24.0;
	t[20] = 20.0 / 24.0;
	t[21] = 21.0 / 24.0;
	t[22] = 22.0 / 24.0;
	t[23] = 23.0 / 24.0;
			
	v[0] = 13.75;
	v[1] = 14.51;
	v[2] = 14.49;
	v[3] = 13.98;
	v[4] = 12.69;
	v[5] = 11.05;
	v[6] = 8.83;
	v[7] = 5.66;
	v[8] = 4.68;
	v[9] = 7.79;
	v[10] = 10.11;
	v[11] = 12.33;
	v[12] = 13.64;
	v[13] = 14.32;
	v[14] = 14.53;
	v[15] = 13.83;
	v[16] = 12.08;
	v[17] = 10.60;
	v[18] = 8.13;
	v[19] = 5.6;
	v[20] = 4.72;
	v[21] = 6.45;
	v[22] = 9.08;
	v[23] = 12.09;

	erro = periodico(n, t, v, c);

	printfResultado('c', m, c, erro);

	vetlibera(t);
	vetlibera(v);
	vetlibera(c);

	getch();
}