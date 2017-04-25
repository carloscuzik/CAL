#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <iostream>
#include <string>
#include "node.h"

class Arvore_AVL{
private:
	int gera_chave(std::string nome, std::string sobrenome);
public:
	Node *topo;
	Arvore_AVL();
	~Arvore_AVL();
	void inserir(int indice, std::string nome, std::string sobrenome);
	int buscar(std::string nome, std::string sobrenome);
	// int remove(string nome, string sobrenome);
	void show();
};

#endif /* ARVORE_AVL_H */
