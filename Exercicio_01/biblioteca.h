#include <stdio.h>
#include <stdlib.h>

//exercício 01 da Potência
unsigned long long int potencia_int_loop(int a, int b);
unsigned long long int potencia_int_recusiva(int a, int b);

//exercício 02 das Matrizes
int **aloca_matriz_quadrada(int n);
void le_matriz_quadrada(int **matriz, int n);
int **multiplicacao_de_matrizes_quadradas(int **matriz_a, int **matriz_b, int n);
void imprime_matriz_quadrada(int **matriz, int n);