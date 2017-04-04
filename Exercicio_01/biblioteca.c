#include "biblioteca.h"

//exercício 01 da Potência
unsigned long long int potencia_int_loop(int a, int b){
	int i;
	int res=1;
	for(i=0;i<b;i++){
		res *= a;
	}
	return res;
}

unsigned long long int potencia_int_recusiva(int a, int b){
	if(b==0){
		return 1;
	}
	return a*potencia_int_recusiva(a,b-1);
}

//exercício 02 das Matrizes
int **aloca_matriz_quadrada(int n){
	int **matriz;
	int i;
	matriz = (int**) calloc(n,sizeof(int*));
	for(i=0;i<n;i++){
		matriz[i] = (int*) calloc(n,sizeof(int));
	}
	return matriz;
}

void le_matriz_quadrada(int **matriz, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("matriz[%i][%i]:",i+1,j+1);
			scanf("%i",&matriz[i][j]);
		}
	}
}

int **multiplicacao_de_matrizes_quadradas(int **matriz_a, int **matriz_b, int n){
	int i,j,k;
	int resultado_celula;
	int **matriz_resposta = aloca_matriz_quadrada(n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			resultado_celula = 0;
			for(k=0;k<n;k++){
				resultado_celula += matriz_a[i][k] * matriz_b[k][j];
			}
			matriz_resposta[i][j] = resultado_celula;
		}
	}
	return matriz_resposta;
}

void imprime_matriz_quadrada(int **matriz, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%i ",matriz[i][j]);
		}
		printf("\n");
	}
}
