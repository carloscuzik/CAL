#ifndef HASH_ENCADIADO_H
#define HASH_ENCADIADO_H

#include <iostream>
#include <string>
#include "lista_encadiada.h"
// #include "arvore_avl.h"

class Hash_encadiado{
private:
	int gera_chave(std::string nome, std::string sobrenome);
	int tamanho;
public:
	Lista_encadiada **lista;
	Hash_encadiado(int tamanho);
	~Hash_encadiado();
	void inserir(int indice, std::string nome, std::string sobrenome);
	int buscar(std::string nome, std::string sobrenome);
	// int remove(string nome, string sobrenome);
	void show();
};

#endif /* HASH_ENCADIADO_H */
