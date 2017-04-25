#include "arvore_avl.h"

Arvore_AVL::Arvore_AVL(){
    this->topo = NULL;
}

int Arvore_AVL::gera_chave(std::string nome, std::string sobrenome){
    int i;
    int soma = 0;
    for(i=0;i<(int)nome.length();i++){
        soma += nome[i] * (i+1);
    }
    int t_n = nome.length();
    for(i=0;i<(int)sobrenome.length();i++){
        soma += sobrenome[i] * (i+1+t_n);
    }
    return soma;
}

void Arvore_AVL::inserir(int indice, std::string nome, std::string sobrenome){
    int chave = gera_chave(nome, sobrenome);
    Node *novo_node = new Node(indice, nome, sobrenome);
    novo_node->setChave(chave);
    Node *aux = this->topo;
    Node *ant = this->topo;
    while(aux != NULL){
        ant = aux;
        if(chave < aux->getChave()){
            aux = aux->esq;
        }else if(chave > aux->getChave()){
            aux = aux->dir;
        }else{
            std::cout << "não rolo miga, ja tem um desse" << std::endl;
            return;
        }
    }
    if(ant==NULL){
        this->topo = novo_node;
        // std::cout << "coloca no topo" << std::endl;
        return;
    }
    if(chave < ant->getChave()){
        ant->esq = novo_node;
    }else if(chave > ant->getChave()){
        ant->dir = novo_node;
    }
}

int Arvore_AVL::buscar(std::string nome, std::string sobrenome){
    int chave = gera_chave(nome, sobrenome);
    Node *aux = this->topo;
    while(aux != NULL){
        if(chave < aux->getChave()){
            aux = aux->esq;
        }else if(chave > aux->getChave()){
            aux = aux->dir;
        }else{
            return aux->getIndice();
        }
    }
    return -1;
}

void Arvore_AVL::show(){
}