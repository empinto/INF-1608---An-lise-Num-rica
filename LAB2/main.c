#include "raiz.h"
#include<conio.h>
#include<stdlib.h>

double f(double x)
{
	return cos(x) - x * x * x + x;
}

double g(double m)
{
	return 0.653333 * m * (1.0 - exp(-135.0 / m)) - 35.0;
}

int main()
{
	double x0, x1, x2;
	int precisao = 6, iteracoesBissecao, iteracoesIQI;
	double* raizBissecao;
	double* raizIQI;

	raizBissecao = (double*) malloc(sizeof(double));
	raizIQI = (double*) malloc(sizeof(double));
	if (raizBissecao == NULL || raizIQI == NULL)
	{
		perror("Não foi possível alocar memória para executar os testes");
		return 0;
	}

	x0 = 0.0;
	x1 = 23.0;

	iteracoesBissecao = bissecao(x0, x1, precisao, f, raizBissecao);

	x2 = 120.0;

	iteracoesIQI = IQI(x0, x1, x2, precisao, f, raizIQI);

	printf("f(x) = cos(x) - x ^ 3 + x \nRaiz bissecao: %g \tIteracoes: %d\nRaiz IQI: %g \tIteracoes: %d", 
		*raizBissecao, iteracoesBissecao, *raizIQI, iteracoesIQI);

	printf("\n\n");

	*raizBissecao = 0.0;
	*raizIQI = 0.0;

	x0 = 40.0;
	x1 = 80.0;

	iteracoesBissecao = bissecao(x0, x1, precisao, g, raizBissecao);

	iteracoesIQI = IQI(x0, x1, x2, precisao, g, raizIQI);

	printf("g(x) = 0.653333 * m * (1 - exp(-135 / m)) - 35 \nRaiz bissecao: %g \tIteracoes: %d\nRaiz IQI: %g \tIteracoes: %d",
		*raizBissecao, iteracoesBissecao, *raizIQI, iteracoesIQI);

	_getch();

	free(raizBissecao);
	free(raizIQI);

	return 0;
}