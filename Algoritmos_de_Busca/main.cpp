#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <sys/time.h>

//bibliotecas locais
#include "lista_encadiada.h"
#include "arvore_avl.h"
#include "hash_encadiado.h"

using namespace std;


int main(int argc, char *argv[]){
	FILE *out;
    clock_t ini,fim;
    double t_insert,t_search;
	int type, n, m, i, indice;
	string nome, sobrenome;
	
	if(argc==2){
		type = atoi(argv[1]);
	}else{
		printf("Missing argument\n");
		return EXIT_FAILURE;
	}

	if(type==1){
		cin >> n;
		Lista_encadiada *lista = new Lista_encadiada();
		ini = clock();
		for(i=0;i<n;i++){
			cin >> indice; 
			cin >> nome; 
			cin >> sobrenome; 
			lista->inserir(indice, nome, sobrenome);
		}
		fim = clock();
		t_insert = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		cin >> m;
		ini = clock();
		for(i=0;i<m;i++){
			cin >> nome; 
			cin >> sobrenome; 
			cout << lista->buscar(nome, sobrenome) << endl;
		}
		fim = clock();
		t_search = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		if(n==5000){
			out = fopen("Results/linear.txt", "w");
		}else{
			out = fopen("Results/linear.txt", "a");
		}
		fprintf(out, "%i %lf %lf \n", n, (double)t_insert, (double)t_search);
	}else if(type==2){
		cin >> n;
		Arvore_AVL *avl = new Arvore_AVL;
		ini = clock();
		for(i=0;i<n;i++){
			cin >> indice; 
			cin >> nome; 
			cin >> sobrenome; 
			avl->inserir(indice, nome, sobrenome);
		}
		fim = clock();
		t_insert = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		cin >> m;
		ini = clock();
		for(i=0;i<m;i++){
			cin >> nome; 
			cin >> sobrenome; 
			cout << avl->buscar(nome, sobrenome) << endl;
		}
		fim = clock();
		t_search = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		if(n==5000){
			out = fopen("Results/binario.txt", "w");
		}else{
			out = fopen("Results/binario.txt", "a");
		}
		fprintf(out, "%i %lf %lf \n", n, (double)t_insert, (double)t_search);
	}else if(type==3){
		cin >> n;
		Hash_encadiado *hash = new Hash_encadiado(n);
		ini = clock();
		for(i=0;i<n;i++){
			cin >> indice; 
			cin >> nome; 
			cin >> sobrenome; 
			hash->inserir(indice, nome, sobrenome);
		}
		fim = clock();
		t_insert = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		cin >> m;
		ini = clock();
		for(i=0;i<m;i++){
			cin >> nome; 
			cin >> sobrenome; 
			cout << hash->buscar(nome, sobrenome) << endl;
		}
		fim = clock();
		t_search = ( (double) (fim - ini) ) / CLOCKS_PER_SEC;
		if(n==5000){
			out = fopen("Results/hash.txt", "w");
		}else{
			out = fopen("Results/hash.txt", "a");
		}
		fprintf(out, "%i %lf %lf \n", n, (double)t_insert, (double)t_search);
	}else{
		cout << "não rolo" << endl;
	}
	return 0;
}