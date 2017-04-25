#ifndef LISTA_ENCADIADA_h
#define LISTA_ENCADIADA_h

#include <iostream>
#include <string>
#include "node.h"

class Lista_encadiada{
private:
public:
	Node *topo;
	Lista_encadiada();
	~Lista_encadiada();
	void inserir(int indice, std::string nome, std::string sobrenome);
	int buscar(std::string nome, std::string sobrenome);
	// int remove(string nome, string sobrenome);
	void show();
};

#endif /* LISTA_ENCADIADA_h */
