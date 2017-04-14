#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void le_resultados(double results[8][5], char name[]);
void imprime_grafico(double results[8][5]);

char type[8][100] = {"Bubble Sort", "Insert Sort", "Merge Sorte", "Quick Sort B", "Quick Sort R", "Heap Sort", "Counting Sort", "Bucket Sort"};

int main(){
	double results[8][5];
	le_resultados(results, "crescente.dat");
	imprime_grafico(results);
	le_resultados(results, "decrescente.dat");
	imprime_grafico(results);
	le_resultados(results, "random_normal.dat");
	imprime_grafico(results);
	le_resultados(results, "random_grande.dat");
	imprime_grafico(results);
	return 0;
}

void le_resultados(double results[8][5], char name[]){
	FILE *in;
	in = fopen(name,"r");
	int i,j;
	double aux;
	for(i=0;i<8;i++){
		for(j=0;j<5;j++){
			fscanf(in,"%lf",&aux);
			results[i][j] = aux;
		}
	}
	fclose(in);
}

void imprime_grafico(double results[8][5]){
	int i,j;



	cout << endl;
	cout << endl;
	cout << "\t\\begin{center}" << endl;
	cout << "\t\t\\begin{tabu} to 0.9\\textwidth {| X[c,2] || X[c] | X[c] | X[c] | X[c] | X[c] |}" << endl;
	cout << "\t\t\t\\hline" << endl;
	cout << "\t\t\t\t \\textbf{Tipo de Ord.} & \\textbf{25000} & \\textbf{50000} & \\textbf{75000} & \\textbf{100000} & \\textbf{1000000} \\\\" << endl;

	for(i=0;i<8;i++){
		cout << "\t\t\t\\hline" << endl;
		cout << "\t\t\t\t" << type[i]; 
		for(j=0;j<5;j++){
			if(results[i][j] == 0){
				cout << " & null";
			}else{
				cout << " & " << results[i][j];
			}
		}
		cout << " \\\\" << endl; 
	}


	cout << "\t\t\t\\hline" << endl;
	cout << "\t\t\\end{tabu}" << endl;
	cout << "\t\\end{center}" << endl;
}