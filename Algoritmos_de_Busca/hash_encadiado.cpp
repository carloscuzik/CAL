#include "hash_encadiado.h"

Hash_encadiado::Hash_encadiado(int tamanho){
    this->tamanho = tamanho;
    this->lista = new Lista_encadiada*[this->tamanho];
}

int Hash_encadiado::gera_chave(std::string nome, std::string sobrenome){
    // int i;
    // int soma = 0;
    // for(i=0;i<(int)nome.length();i++){
    //     soma += nome[i] * (i+1);
    // }
    // int t_n = nome.length();
    // for(i=0;i<(int)sobrenome.length();i++){
    //     soma += sobrenome[i] * (i+1+t_n);
    // }
    // return soma%(this->tamanho);

    std::string str = nome+sobrenome;
    int h = 0;
    for (int i = 0; i < (int) str.length(); i++)
        h = (31 * h + str[i]) % (this->tamanho);
    return h;
}

void Hash_encadiado::inserir(int indice, std::string nome, std::string sobrenome){
    int chave = gera_chave(nome, sobrenome);
    if(this->lista[chave]==NULL){
        this->lista[chave] = new Lista_encadiada();
    }
    this->lista[chave]->inserir(indice, nome, sobrenome);
}

int Hash_encadiado::buscar(std::string nome, std::string sobrenome){
    int chave = gera_chave(nome, sobrenome);
    return this->lista[chave]->buscar(nome, sobrenome);
}