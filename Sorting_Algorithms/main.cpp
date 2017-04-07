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


	// if(type_sort == bubblesort){
	// 	printf("Bubble Sort:   ");
	// }else if(type_sort == insertsort){
	// 	printf("Insert Sort:   ");
	// }else if(type_sort == mergesort){
	// 	printf("Merge Sort:    ");
	// }else if(type_sort == quicksort_B){
	// 	printf("Quick B Sort:  ");
	// }else if(type_sort == quicksort_R){
	// 	printf("Quick R Sort:  ");
	// }else if(type_sort == heapsort){
	// 	printf("Heap Sort:     ");
	// }else if(type_sort == countingsort){
	// 	printf("Counting Sort: ");
	// }else if(type_sort == bucketsort){
	// 	printf("Bucket Sort:   ");
	// }

	// if(type_order==crescente){
	// 	printf("Crescente   - ");
	// }else if(type_order==decrescente){
	// 	printf("Decrescente - ");
	// }else if(type_order==random){
	// 	printf("Random      - ");
	// }else if(type_order==random_e){
	// 	printf("Random-E    - ");
	// }
	
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

	// printf("%9i := ",size);

	//captura o tempo inicial
	gettimeofday(&inicio, NULL);
	if(type_sort == bubblesort){
		// printf("Ordenado por Bubble Sort\n");
		sort->bubble_sort(array);
	}else if(type_sort == insertsort){
		// printf("Ordenado por Insert Sort\n");
		sort->insert_sort(array);
	}else if(type_sort == mergesort){
		// printf("Ordenado por Merge Sort\n");
		sort->merge_sort(vetor, 0, size-1);
	}else if(type_sort == quicksort_B){
		// printf("Ordenado por Quick B Sort\n");
		sort->quick_sort_beginning_pivot(vetor, 0, size-1);
	}else if(type_sort == quicksort_R){
		// printf("Ordenado por Quick R Sort\n");
		sort->quick_sort_random_pivot(vetor, 0, size-1);
	}else if(type_sort == heapsort){
		// printf("Ordenado por Heap Sort\n");
		sort->heap_sort(array);
	}else if(type_sort == countingsort){
		// printf("Ordenado por Counting Sort\n");
		sort->counting_sort(vetor, size);
	}else if(type_sort == bucketsort){
		printf("Ordenado por Bucket Sort\n");
		sort->bucket_sort(vetor, size);
	}
	//captura o tempo final
	gettimeofday(&final, NULL);

	// if(type_sort==bubblesort || type_sort==insertsort || type_sort==heapsort){
	//  	imprime_array(array);
	// }else{
	//  	imprime_vetor(vetor,size);
	// }

	tempo_real = (1 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000000.0);
	// cout << tempo_real << "(s)" << endl;
	// printf("%lf(s)\n",tempo_real);
	
	// if(type_sort == bubblesort){


	// 	printf("\\begin{tikzpicture}\n");
	// 	printf("\t\\begin{axis}[\n");
 //        printf("\t\tybar, \n");
 //        printf("\t\tenlargelimits=0.15, \n");
 //        printf("\t\tlegend style={at={(0.5,-0.15)},\n");
 //        printf("\t\tanchor=north,\n");
 //        printf("\t\tlegend columns=-1},\n"); 
 //        printf("\t\tylabel={tempo (s)}, \n");
 //        printf("\t\tsymbolic x coords={1,2,3,4,5,6,7,8},\n"); 
 //        printf("\t\txtick=data, \n");
 //        printf("\t\tnodes near coords,\n"); 
 //        printf("\t\tnodes near coords align={vertical}, ]\n");
 //        printf("\t\t\\addplot coordinates {\n");

	// 	printf("\t\t(1,%lf)\n", tempo_real);
	// }else if(type_sort == insertsort){
	// 	printf("\t\t(2,%lf)\n", tempo_real);
	// }else if(type_sort == mergesort){
	// 	printf("\t\t(3,%lf)\n", tempo_real);
	// }else if(type_sort == quicksort_B){
	// 	printf("\t\t(4,%lf)\n", tempo_real);
	// }else if(type_sort == quicksort_R){
	// 	printf("\t\t(5,%lf)\n", tempo_real);
	// }else if(type_sort == heapsort){
	// 	printf("\t\t(6,%lf)\n", tempo_real);
	// }else if(type_sort == countingsort){
	// 	printf("\t\t(7,%lf)\n", tempo_real);
	// 	if(type_order==40){
	// 		printf("\t\t};\n");
	// 		printf("\t\t\\legend{");
	// 		if(type_order==crescente){
	// 			printf("Crescente");
	// 		}else if(type_order==decrescente){
	// 			printf("Decrescente");
	// 		}else if(type_order==random){
	// 			printf("Random");
	// 		}else if(type_order==random_e){
	// 			printf("Random-E");
	// 		}
	// 		printf("::%i}\n",size);
	// 		printf("\t\\end{axis}\n");
	// 		printf("\\end{tikzpicture}\n\n");
	// 	}
	// }else if(type_sort == bucketsort){
	// 	printf("\t\t(8,%lf)\n", tempo_real);
	// 	printf("\t\t};\n");
	// 	printf("\t\t\\legend{");
	// 	if(type_order==crescente){
	// 		printf("Crescente");
	// 	}else if(type_order==decrescente){
	// 		printf("Decrescente");
	// 	}else if(type_order==random){
	// 		printf("Random");
	// 	}else if(type_order==random_e){
	// 		printf("Random-E");
	// 	}
	// 	printf("::%i}\n",size);
	// 	printf("\t\\end{axis}\n");
	// 	printf("\\end{tikzpicture}\n\n");
	// }

	std::vector<int> size_vector;
	size_vector.push_back(25000);
	size_vector.push_back(50000);
	size_vector.push_back(75000);
	size_vector.push_back(100000);
	size_vector.push_back(1000000);

	if(size==size_vector[0]){
		if(type_sort == bubblesort){
			printf("Highcharts.chart('container', {\n");

		    printf("\ttitle: {\n");
		    printf("\t\ttext: 'Gráfico para comparação dos tempode de execução com diferentes tamanhos de vetores'\n");
		    printf("\t},\n");
		    
		    printf("\txAxis: {\n");
		    printf("\t\tcategories: [");
		    int i;
	    	for(i=0;i<(int)size_vector.size()-1;i++){
	    		printf("%i,",size_vector[i]);
	    	}
	    	printf("%i",size_vector[i]);
		    printf("]\n");
		    printf("\t},\n");

		    printf("\tyAxis: {\n");
		    printf("\t\ttitle: {\n");
		    printf("\t\t\ttext: 'Tempo (s)'\n");
		    printf("\t\t}\n");
		    printf("\t},\n");
		    printf("\tlegend: {\n");
		    printf("\t\tlayout: 'vertical',\n");
		    printf("\t\talign: 'right',\n");
		    printf("\t\tverticalAlign: 'middle'\n");
		    printf("\t},\n");

		    printf("\tplotOptions: {\n");
		    printf("\t},\n");

		    printf("\tseries: [\n");
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Bubble Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == insertsort){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Insert Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == mergesort){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Merge Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == quicksort_B){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Quick B Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == quicksort_R){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("\tQuick R Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == heapsort){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Heap Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == countingsort){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Counting Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}else if(type_sort == bucketsort){
		    printf("\t{\n");
		    printf("\t\tname: '");
			printf("Bucket Sort");
			printf("',\n");
			printf("\t\tdata: [");
		}
		printf("%lf,",tempo_real);
	}

	int i;
	for(i=1;i<(int)size_vector.size()-1;i++){
		//printf("%i,",size_vector[i]);
		if(size==size_vector[i]){
			printf("%lf,",tempo_real);
		}
	}

	if(size==size_vector[size_vector.size()-1]){
		printf("%lf]\n",tempo_real);
		if(type_sort==bucketsort || (type_sort==countingsort && type_order==random_e)){
		printf("\t}]\n");
		printf("});\n\n");
		}else{
			printf("\t},\n");
		}
	}

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