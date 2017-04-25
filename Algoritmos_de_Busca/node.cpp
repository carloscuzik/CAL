#include <iostream>
#include <string>
#include "node.h"

Node::Node(int indice, std::string nome, std::string sobrenome){
    this->indice = indice;
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->esq = NULL;
    this->dir = NULL;
    this->fator_balanceamento = 2;
    this->chave = 0;
}

int Node::getIndice(){
    return this->indice;
}
std::string Node::getNome(){
    return this->nome;
}
std::string Node::getSobrenome(){
    return this->sobrenome;
}
int Node::getFator_balanceamento(){
	return this->fator_balanceamento;
}
int Node::getChave(){
	return this->chave;
}
void Node::setChave(int chave){
	this->chave = chave;
}
void Node::setFator_balanceamento(int fator_balanceamento){
	this->fator_balanceamento = fator_balanceamento;
}
