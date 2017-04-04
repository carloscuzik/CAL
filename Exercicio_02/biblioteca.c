#include <stdlib.h>
#include "biblioteca.h"

unsigned long long int fiboncci_ruim(int n){
	if(n==1 || n==2)
		return 1;
	return fiboncci_ruim(n-1) + fiboncci_ruim(n-2);
}
unsigned long long int fiboncci_boa(int n){
	unsigned long long int *vetor = aloca_vetor_int(n);
	vetor[0] = 1;
	vetor[1] = 1;
	int i;
	for(i=2;i<n;i++)
		vetor[i] = vetor[i-1] + vetor[i-2];
	return vetor[n-1];
}
unsigned long long int *aloca_vetor_int(int n){
	unsigned long long int *vetor_new;
	vetor_new = (unsigned long long int*) calloc(n,sizeof(unsigned long long int));
	return vetor_new;
}

//exercício da raiz

double raiz_metodo_babilonico(double n){
	double r = acha_inteiro_mais_proximo(n);
	return raiz_metodo_babilonico_recursao(n,r);
	//return raiz_metodo_babilonico_recursao(n,media(r,n/r));
}
double raiz_metodo_babilonico_recursao(double n,double r){
	printf("oi\n");
	if(modulo(n-(r*r)) <= 0.00001)
		return r;
	return raiz_metodo_babilonico_recursao(n,media(r,n/r));
}
int acha_inteiro_mais_proximo(double n){
	if(n<1)
		return 1;
	int i = 1;
	while(i*i<n)
		i++;
	return i-1;
}
double media(double a, double b){
	return (a+b)/2;
}
double modulo(double n){
	if(n<0)
		return -n;
	return n;
}