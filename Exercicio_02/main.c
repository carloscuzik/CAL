#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "biblioteca.h"

// Atividade 01

// Escreva duas versões do algoritmo de fibonacci: a
// versão “ruim” apresentada e uma versão “boa”
// usando vetores. Faça uma comparação de tempo de
// execução com valores entre 25 e 60.

// Qual a complexidade da versão “boa” do algoritmo?

// int main(){
// 	struct timeval inicio, final;
//     double tempo_real;
//     unsigned long long int res;
// 	int n;
// 	printf("Digite  número: ");
// 	scanf("%i",&n);
//     printf("Para a entrada %i, temos os seguintes resultados:\n\n",n);

//     /******FIBONACCI RUIM******/
	
// 	printf("--------------------\n");
// 	printf("Implementação RUIM\n");
// 	printf("--------------------\n\n");
	
// 	gettimeofday(&inicio, NULL);
// 	res = fiboncci_ruim(n);
// 	gettimeofday(&final, NULL);
	
// 	printf("resultado: %lli\n",res);
//     tempo_real = (1 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000000.0);
//     printf("tempo: %lf segundos\n",tempo_real);

//     /******FIBONACCI BOA******/

//     printf("--------------------\n");
// 	printf("Implementação BOA\n");
// 	printf("--------------------\n\n");
	
// 	gettimeofday(&inicio, NULL);
// 	res = fiboncci_boa(n);
// 	gettimeofday(&final, NULL); 
	
// 	printf("resultado: %lli\n",res);
//     tempo_real = (1 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000000.0);
//     printf("tempo: %lf segundos\n",tempo_real);
// 	return 0;
// }

// Atividade 01

// Elabore um algoritmo recursivo para calcular a raiz
// quadrada de um número real (positivo) qualquer.
// Após implementar o algoritmo escreva a relação de
// recorência e a respectiva complexidade do 
// algoritmo para o pior caso.

int main(){
	double n;
	printf("Digite  número: ");
	scanf("%lf",&n);
	printf("Raiz de %lf é: %lf\n",n,raiz_metodo_babilonico(n));

	return 0;
}