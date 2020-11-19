#ifndef TAD_PILHA_H_INCLUDED
#define TAD_PILHA_H_INCLUDED

#include <iostream>


using namespace std;

template<typename tipo>
struct Data{
    tipo dado;
};

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento<tipo> *baixo;

};

template <typename tipo>
struct TPilha{
    TElemento<tipo> *topo;


};

template<typename tipo>
bool inicia_pilha(TPilha<tipo> *pilha){
    pilha->topo = NULL;
}

template <typename tipo>
bool PUSH(TPilha<tipo>*pilha,tipo dado){
    TElemento<tipo> *novo;
    novo = new TElemento<tipo>;
    novo->elemento = dado;
    if(pilha->topo==NULL){
        pilha->topo = novo;
        return true;
    }else{
        novo->baixo = pilha->topo;
        pilha->topo= novo;
        return true;
    }
}

template <typename tipo>
tipo POP(TPilha<tipo>*pilha){
    TElemento<tipo> *percorre = pilha->topo;
   tipo endereco;
    if(pilha->topo == NULL){
    }else{
    pilha->topo= pilha->topo->baixo;
    endereco = percorre->elemento;
    delete percorre;
    return endereco;
    }

}

#endif // TAD_PILHA_H_INCLUDED
