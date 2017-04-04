#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sys/time.h>
#include "sorting.h"

Sorting::Sorting(){
	//adasdas
}
// Bubble Sort
void Sorting::bubble_sort(std::vector <int> &num){
	int i, j, flag = 1;
	int temp;
	int numLength = num.size(); 
	for(i = 1; (i <= numLength) && flag; i++){
		flag = 0;
		for (j=0; j < (numLength -1); j++){
			if (num[j+1] < num[j]){ 
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
				flag = 1;
			}
		}
	}
	return;
}
// Insert Sort
void Sorting::insert_sort(std::vector <int> &array){
	for(int i = 1; i < (int)array.size(); i++) {
		int key = array[i];
		int j = i - 1;
		while((j >= 0) && (array[j] > key)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	return;
}
// Merge Sort
void Sorting::merge_sort(int *vetor, int posicaoInicio, int posicaoFim){
    int i, j, k, metadeTamanho, *vetorTemp;
    if(posicaoInicio == posicaoFim){
    	return;
    }
    metadeTamanho = (posicaoInicio + posicaoFim) / 2;
    merge_sort(vetor, posicaoInicio, metadeTamanho);
    merge_sort(vetor, metadeTamanho + 1, posicaoFim);
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));
    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}
// Quick Sort Beginning Pivot
void Sorting::quick_sort_beginning_pivot(int vet[], int esq, int dir){
	int pivo = esq;
	int i,ch,j;
	for(i=esq+1;i<=dir;i++){
		j = i;
		if(vet[j] < vet[pivo]){
			ch = vet[j];
			while(j > pivo){
				vet[j] = vet[j-1];
				j--;
			}
			vet[j] = ch;
			pivo++;
		}
	}
	if(pivo-1 >= esq){
		quick_sort_beginning_pivot(vet,esq,pivo-1);
	}
	if(pivo+1 <= dir){
		quick_sort_beginning_pivot(vet,pivo+1,dir);
	}
}
// Quick Sort Random Pivot
int Sorting::separa(int *v, int inicio, int fim) {
    int pivo = v[(rand() % (fim-inicio))+inicio], i, j = inicio, valor;
    for(i=inicio; i<fim; i++) {
        if(v[i] < pivo){
            valor = v[i];
            v[i] = v[j];
            v[j] = valor;
            j++;
        }
    }
    if(pivo <= v[j]) {
        v[fim] = v[j];
        v[j] = pivo;
    }
    return j;
}

void Sorting::quick_sort_random_pivot(int *vetor, int inicio, int fim) {
    if(inicio >= fim)
        return;
    int pivoIndex = separa(vetor, inicio, fim);
    quick_sort_random_pivot(vetor, inicio, pivoIndex-1);
    quick_sort_random_pivot(vetor, pivoIndex+1, fim);
}
// Heap Sort
void Sorting::heap_sort(std::vector<int> &lista){
    int tam = static_cast<int>( lista.size() ), i;
    for( i = tam/2 - 1; i >= 0; --i ){
       maxHeapify(lista, i , tam );
    }
    std::vector<int>::reverse_iterator elem;
    for( elem = lista.rbegin(); elem != lista.rend(); elem++ ){
       std::iter_swap( elem, lista.begin() );
       maxHeapify( lista, 0, --tam );
    }
}

void Sorting::maxHeapify(std::vector<int> &lista, const int pos, const int n ){
    int max = 2 * pos + 1;
    if( max < n ){
       if( (max+1) < n && lista.at(max) < lista.at(max+1) ){
          ++max;
       }
       if( lista.at(max) > lista.at(pos) ){
          std::swap( lista[max], lista[pos] );
          maxHeapify( lista, max, n );
       }
    }
}
// Counting Sort
void Sorting::counting_sort(int* arr, int len ){
	int mi, mx, z = 0; 
	findMinMax( arr, len, mi, mx );
	int nlen = ( mx - mi ) + 1; int* temp = new int[nlen];
	memset( temp, 0, nlen * sizeof( int ) );
	for( int i = 0; i < len; i++ ){
		temp[arr[i] - mi]++;
	}
	for( int i = mi; i <= mx; i++ ){
		while( temp[i - mi] ){
			arr[z++] = i;
			temp[i - mi]--;
		}
	}
	delete [] temp;
}

void Sorting::findMinMax( int* arr, int len, int& mi, int& mx ){
	mi = arr[0];
	mx = 0;
	for( int i = 0; i < len; i++ ){
		if( arr[i] > mx ){
			mx = arr[i];
		}
		if( arr[i] < mi ){
			mi = arr[i];
		}
	}
}
// Bucket Sort
void Sorting::bucket_sort(int array[], int n){
    int i, j;
    int count[n];
    for (i = 0; i < n; i++){
        count[i] = 0;
    }
    for (i = 0; i < n; i++){
        (count[array[i]])++;
    }
    for (i = 0, j = 0; i < n; i++){
        for(; count[i] > 0; (count[i])--){
            array[j++] = i;
        }
    }
}