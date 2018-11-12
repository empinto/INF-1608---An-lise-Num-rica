#include "taylor.h"
#include<math.h>
#include<conio.h>

int main()
{
	double valorAprox, valorFunc, i;

	for (i = 0.0; i <= 3.14; i += 0.00005)
	{
		valorAprox = tcos(i);
		valorFunc = cos(i);

		printf("f(%g) -> \ttcos=%g \tcos=%g \ttcos-cos=%g \ttcos_erro=%g \n", i, valorAprox, valorFunc, valorAprox - valorFunc, tcos_erro(i));
	}

	printf("\n\n");

	for (i = 1.0; i <= 2.0; i += 0.00005)
	{
		valorAprox = tsqrt(i);
		valorFunc = sqrt(i);

		printf("f(%g) -> \ttsqrt=%g \tsqrt=%g \ttsqrt-sqrt=%g \ttsqrt_erro=%g \n", i, valorAprox, valorFunc, valorAprox - valorFunc, tsqrt_erro(i));
	}

	_getch();

	return 0;
}