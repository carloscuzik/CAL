#include "lista_encadiada.h"

Lista_encadiada::Lista_encadiada(){
    this->topo = NULL;
    this->calda = NULL;
}

void Lista_encadiada::inserir(int indice, std::string nome, std::string sobrenome){
    Node *novo_node = new Node(indice, nome, sobrenome);
    if(this->topo==NULL){
        this->topo = novo_node;
        this->calda = novo_node;
    }else{
        this->calda->dir = novo_node;
        novo_node->esq = this->calda;
        this->calda = novo_node;
    }
}

int Lista_encadiada::buscar(std::string nome, std::string sobrenome){
    Node *aux = this->topo;
    while(aux!=NULL){
        if(aux->getNome()==nome && aux->getSobrenome()==sobrenome){
            return aux->getIndice();
        }
        aux = aux->dir;
    }
    return -1;
}

void Lista_encadiada::show(){
    Node *aux = this->topo;
    while(aux!=NULL){
        std::cout << aux->getIndice() << " - " << aux->getNome() << " - " << aux->getSobrenome() << std::endl;
        aux = aux->dir;
    }
}