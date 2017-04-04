#include "biblioteca.h"

int main(){
	/***EXERCICIO 01***/
	/*
	int a,b;
	printf("Digite os valores de a e b respectivamente:\n");
	printf("a: ");
	scanf("%i",&a);
	printf("b: ");
	scanf("%i",&b);
	printf("%lli\n",potencia_int_loop(a,b));
	//printf("%lli\n",potencia_int_recusiva(a,b));
	*/

	/***EXERCICIO 02***/
	int n;
	printf("Digite a ordem das matrizes (n):\n");
	printf("n: ");
	scanf("%i",&n);
	int **matriz_a = aloca_matriz_quadrada(n);
	printf("------------------------\n");
	printf("Matriz A\n");
	printf("------------------------\n");
	le_matriz_quadrada(matriz_a, n);
	int **matriz_b = aloca_matriz_quadrada(n);
	printf("------------------------\n");
	printf("Matriz B\n");
	printf("------------------------\n");
	le_matriz_quadrada(matriz_b, n);
	int **matriz_r = multiplicacao_de_matrizes_quadradas(matriz_a,matriz_b,n);
	printf("------------------------\n");
	printf("Resultado\n");
	printf("------------------------\n");
	imprime_matriz_quadrada(matriz_r,n);
	return 0;
}