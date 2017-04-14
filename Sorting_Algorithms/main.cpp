#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <sys/time.h>
#include "sorting.h"

#define bubblesort   0
#define insertsort   1
#define mergesort    2
#define quicksort_B  3
#define quicksort_R  4
#define heapsort     5
#define countingsort 6
#define bucketsort   7

#define crescente 10
#define decrescente 20
#define random 30
#define random_e 40

//funções para uso de vetores(vector<int>) na estrutura de c++
void imprime_array(std::vector <int> &array);
void ordem_crescente_array(std::vector <int> &array, int n);
void ordem_decrescente_array(std::vector <int> &array, int n);
void ordem_random_array(std::vector <int> &array, int n);
void ordem_random_e_array(std::vector <int> &array, int n);

//funções para uso de vetores na estrutura de c
void imprime_vetor(int vetor[], int n);
void ordem_crescente_vetor(int *vetor, int n);
void ordem_decrescente_vetor(int *vetor, int n);
void ordem_random_vetor(int *vetor, int n);
void ordem_random_e_vetor(int *vetor, int n);

using namespace std;

int main(int argc, char **argv){
	struct timeval inicio, final;
    double tempo_real;
	srand((unsigned)time(NULL));
	Sorting *sort;
	sort = new Sorting();
	int type_sort; // o tipo de ordenação
	int type_order; // o tipo de organização dos dados inicial
	int size;

	if(argc==1){
		printf("1\n");
	}
	if(argc==2){
		printf("1\n");
	}
	if(argc==3){
		printf("1\n");
	}

	if(argc==4){
		type_sort = atoi(argv[1]);
		type_order = atoi(argv[2]);
		size = atoi(argv[3]);
	}else{
		printf("Missing argument\n");
		return EXIT_FAILURE;
	}

	int *vetor;
	std::vector<int> array;
	
	if(type_sort==bubblesort || type_sort==insertsort || type_sort==heapsort){
		if(type_order==crescente){
			ordem_crescente_array(array, size);
		}else if(type_order==decrescente){
			ordem_decrescente_array(array, size);
		}else if(type_order==random){
			ordem_random_array(array, size);
		}else if(type_order==random_e){
			ordem_random_e_array(array, size);
		}else{
			printf("Paremetro de tipo de ordenação inicial esta errado\n");
		}
	}else{
		//printf("Usando vetor de int do C\n");
		vetor = (int*) calloc(sizeof(int),size);
		if(type_order==crescente){
			ordem_crescente_vetor(vetor,size);
		}else if(type_order==decrescente){
			ordem_decrescente_vetor(vetor,size);
		}else if(type_order==random){
			ordem_random_vetor(vetor,size);
		}else if(type_order==random_e){
			ordem_random_e_vetor(vetor,size);
		}else{
			printf("Paremetro de tipo de ordenação inicial esta errado\n");
		}
	}

	//captura o tempo inicial
	gettimeofday(&inicio, NULL);
	if(type_sort == bubblesort){
		sort->bubble_sort(array);
	}else if(type_sort == insertsort){
		sort->insert_sort(array);
	}else if(type_sort == mergesort){
		sort->merge_sort(vetor, 0, size-1);
	}else if(type_sort == quicksort_B){
		sort->quick_sort_beginning_pivot(vetor, 0, size-1);
	}else if(type_sort == quicksort_R){
		sort->quick_sort_random_pivot(vetor, 0, size-1);
	}else if(type_sort == heapsort){
		sort->heap_sort(array);
	}else if(type_sort == countingsort){
		sort->counting_sort(vetor, size);
	}else if(type_sort == bucketsort){
		sort->bucket_sort(vetor, size);
	}
	//captura o tempo final
	gettimeofday(&final, NULL);

	tempo_real = (1 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000000.0);

	std::vector<int> size_vector;
	size_vector.push_back(25000);
	size_vector.push_back(50000);
	size_vector.push_back(75000);
	size_vector.push_back(100000);
	size_vector.push_back(1000000);
	
	printf(" %lf\n",size, tempo_real);

	return 0;
}

void imprime_array(std::vector <int> &array){
	int i;
	for(i=0;i<(int)array.size()-1;i++){
		std::cout << array[i] << " - ";
	}
	if((int)array.size() != 0){
		std::cout << array[i] << std::endl;
	}
}

void imprime_vetor(int vetor[], int n){
	int i;
	for(i=0;i<n-1;i++){
		std::cout << vetor[i] << " - ";
	}
	std::cout << vetor[i] << std::endl;
}

void ordem_crescente_vetor(int *vetor, int n){
	int i;
	for(i=0;i<n;i++){
		vetor[i] = i+1;
	}
}

void ordem_decrescente_vetor(int *vetor, int n){
	int i;
	for(i=0;i<n;i++){
		vetor[i] = n-i;
	}
}

void ordem_random_vetor(int *vetor, int n){
	int i;
	for(i=0;i<n;i++){
		vetor[i] = rand() % n;
	}
}

void ordem_random_e_vetor(int *vetor, int n){
	int i;
	for(i=0;i<n;i++){
		vetor[i] = rand() % n;
	}
	vetor[rand()%n] = 100000000;
}

void ordem_crescente_array(std::vector <int> &array, int n){
	int i;
	for(i=0;i<n;i++){
		array.push_back(i+1);
	}
}

void ordem_decrescente_array(std::vector <int> &array, int n){
	int i;
	for(i=0;i<n;i++){
		array.push_back(n-i);
	}
}

void ordem_random_array(std::vector <int> &array, int n){
	int i;
	for(i=0;i<n;i++){
		array.push_back(rand() % n);
	}
}

void ordem_random_e_array(std::vector <int> &array, int n){
	int i;
	for(i=0;i<n;i++){
		array.push_back(rand() % n);
	}
	array[rand()%n] = 100000000;
}