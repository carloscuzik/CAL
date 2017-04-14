#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void le_resultados(double results[8][5], char name[]);
void imprime_tabela(double results[8][5]);

char type[8][100] = {"Bubble Sort", "Insert Sort", "Merge Sorte", "Quick Sort B", "Quick Sort R", "Heap Sort", "Counting Sort", "Bucket Sort"};

int main(){
	double results[8][5];
	le_resultados(results, "crescente.dat");
	imprime_tabela(results);
	le_resultados(results, "decrescente.dat");
	imprime_tabela(results);
	le_resultados(results, "random_normal.dat");
	imprime_tabela(results);
	le_resultados(results, "random_grande.dat");
	imprime_tabela(results);
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

void imprime_tabela(double results[8][5]){
	int i,j;

	printf("Highcharts.chart('container', {\n");

	printf("\ttitle: {\n");
	printf("\t\ttext: 'Gráfico para comparação dos tempode de execução com diferentes tamanhos de vetores'\n");
	printf("\t},\n");

	printf("\txAxis: {\n");
	printf("\t\tcategories: [25000,50000,75000,100000,1000000]\n");
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

	for(i=0;i<8;i++){
	printf("\t\tname: '%s',\n",type[i]);
		if(results[i][0] == 0){
			printf("\t\tdata: [null");
		}else{
			printf("\t\tdata: [%lf",results[i][0]);
		}
		for(j=1;j<5;j++){
			if(results[i][j] == 0){
				printf(", null");
			}else{
				printf(", %lf",results[i][j]);
			}
		}
		printf("]\n");
		if(i!=7){
			printf("\t}, {\n");
		}
	}
    printf("\t}]\n");
	printf("});\n");
}