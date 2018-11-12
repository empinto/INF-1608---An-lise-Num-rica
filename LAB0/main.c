#include "matriz.h"

int main(void)
{
	int tamanho = 7;
	int tamanho2 = 9;
	int tamanho3 = 2;
	int tamanhoErro = -1;
	int i;
	int j;
	int aux = 0;

	double resultadoEscalar = 91.0;
	double resultadoEscalarErro = 0.0;

	double* vetor;
	double* vetor2;

	double** matriz;
	double** matriz2;

	vetor = vetcria(tamanho);
	if (vetor == NULL)
		perror("Erro ao criar vetor. Função vetcria() - Teste 1");

	vetlibera(vetor);

	vetor = vetcria(tamanhoErro);
	if (vetor != NULL)
		perror("Erro ao criar vetor. Função vetcria() - Teste 2");

	vetlibera(vetor);

	vetor = vetcria(tamanho2);
	for (i = 0; i < tamanho2; i++)
		vetor[i] = i;

	for(i = 0; i < tamanho2; i++)
		printf("%f\n", vetor[i]);

	vetlibera(vetor);

	vetor = vetcria(tamanho);
	vetor2 = vetcria(tamanho);

	for (i = 0; i < tamanho; i++)
	{
		vetor[i] = i;
		vetor2[i] = i;
	}

	if (escalar(tamanho, vetor, vetor2) != resultadoEscalar)
		perror("Erro ao calcular o produto escalar. Função escalar() - Teste 3");

	vetlibera(vetor);
	vetlibera(vetor2);

	vetor = vetcria(tamanho);
	vetor2 = NULL;

	for (i = 0; i < tamanho; i++)
		vetor[i] = i;

	if (escalar(tamanho, vetor, vetor2) != resultadoEscalarErro)
		perror("Erro ao calcular o produto escalar. Função escalar() - Teste 4");

	vetlibera(vetor);
	vetlibera(vetor2);

	vetor = vetcria(tamanho);

	for (i = 0; i < tamanho; i++)
		vetor[i] = i;

	if (norma2(tamanho, vetor) != sqrt(resultadoEscalar))
		perror("Erro ao calcular a norma 2. Função norma2() - Teste 5");

	vetlibera(vetor);

	matriz = matcria(tamanho3, tamanho3);
	if (matriz == NULL)
		perror("Erro ao criar matriz. Função matcria() - Teste 6");

	matlibera(tamanho3, matriz);

	matriz = matcria(tamanhoErro, tamanho3);
	if (matriz != NULL)
		perror("Erro ao criar matriz. Função matcria() - Teste 7");

	matlibera(tamanhoErro, matriz);

	matriz = matcria(tamanho3, tamanho3);

	for (i = 0; i < tamanho3; i++)
	{
		for (j = 0; j < tamanho3; j++)
			matriz[i][j] = i + j + aux;

		aux++;
	}

	for (i = 0; i < tamanho3; i++)
	{
		for (j = 0; j < tamanho3; j++)
			printf("%.2f\t", matriz[i][j]);

		printf("\n");
	}

	matlibera(tamanho3, matriz);

	matriz = matcria(tamanho3, tamanho3);
	matriz2 = matcria(tamanho3, tamanho3);

	aux = 0;
	for (i = 0; i < tamanho3; i++)
	{
		for (j = 0; j < tamanho3; j++)
			matriz[i][j] = i + j + aux;

		aux++;
	}

	transposta(tamanho3, tamanho3, matriz, matriz2);

	for (i = 0; i < tamanho3; i++)
	{
		for (j = 0; j < tamanho3; j++)
			printf("%.2f\t", matriz[i][j]);

		printf("\n");
	}

	printf("\n");

	for (i = 0; i < tamanho3; i++)
	{
		for (j = 0; j < tamanho3; j++)
			printf("%.2f\t", matriz2[i][j]);

		printf("\n");
	}

	matlibera(tamanho3, matriz);
	matlibera(tamanho3, matriz2);
}