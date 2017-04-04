#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>

class Sorting{
private:
	void maxHeapify(std::vector<int> &lista, const int pos, const int n);
	void merge(int *array, int inicio, int meio, int fim);
	void findMinMax(int* arr, int len, int& mi, int& mx);
	int separa(int *v, int inicio, int fim);
public:
	Sorting();
	// Bubble Sort
	void bubble_sort(std::vector <int> &num);
	// Insert Sort
	void insert_sort(std::vector <int> &array);
	// Merge Sort
	void merge_sort(int *vetor, int posicaoInicio, int posicaoFim);
	// Quick Sort Beginning Pivot
	void quick_sort_beginning_pivot(int vet[], int esq, int dir);
	// Quick Sort Random Pivot
	void quick_sort_random_pivot(int *vetor, int inicio, int fim);
	// Heap Sort
	void heap_sort(std::vector<int> &lista);
	// Counting Sort
	void counting_sort(int* arr, int len);
	// Bucket Sort
	void bucket_sort(int array[], int n);
};

#endif /* SORTING_H */