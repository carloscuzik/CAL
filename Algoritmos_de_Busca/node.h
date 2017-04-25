#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include "node.h"

class Node{
private:
	std::string nome;
	std::string sobrenome;
	int indice;
	int chave;
	int fator_balanceamento;
public:
	Node *esq;
	Node *dir;
	Node(int indice, std::string nome, std::string sobrenome);
	~Node();
	int getIndice();
	std::string getNome();
	std::string getSobrenome();
	int getFator_balanceamento();
	void setFator_balanceamento(int fator_balanceamento);
	int getChave();
	void setChave(int chave);
};

#endif /* NODE_H */
