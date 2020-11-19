#ifndef TAD_ARVORE_BINARIA_H_INCLUDED
#define TAD_ARVORE_BINARIA_H_INCLUDED
#include <iostream>

using namespace std;
template<typename tipo>
struct node{
    tipo dado;
    int chave;
    node<tipo>*direita;
    node<tipo>*esquerda;
};

template<typename tipo>
struct TArvore{
    node<tipo>*raiz;
};

template <typename tipo>
bool inicializa_arvore(TArvore<tipo> &Arvore){
    Arvore.raiz = NULL;
    return true;
}

template <typename tipo>
bool insere_arvore(node<tipo> *&No, tipo dado , int chave){
  if(No==NULL){
    No= new node<tipo>;
    No->chave = chave;
    No->dado = dado;
    No->esquerda=NULL;
    No->direita=NULL;
    return true;
  }else{
    if(chave>No->chave){
    insere_arvore(No->direita,dado,chave);
      }else if (chave<No->chave){
        insere_arvore(No->esquerda,dado,chave);
  }else{
    return false;
  }
}
}

template <typename tipo>
tipo busca_arvore(node<tipo> *&No, int pos){
    if(No== NULL){
        return false;

    }

    if(pos == No->chave){
        return No->dado;

    }else{
        if(pos>No->chave){
        busca_arvore(No->direita, pos);
    }else if(pos<No->chave){
        busca_arvore(No->esquerda,pos);
    }

}
}
template<typename tipo>
void arvore_busca_remove(node<tipo> *&No, int chave){
    if(No != NULL){
        if(No->chave == chave){
            remove_arvore(No);
        }
        else{
            if(chave>No->chave){
                arvore_busca_remove(No->direita,chave);
            }
            else{
                arvore_busca_remove(No->esquerda,chave);
            }
        }
    }
}


template<typename tipo>
void remove_arvore(node<tipo> *&No){
    node<tipo> *maior = No->esquerda;
    node<tipo> *apagar;

    if(maior==NULL){
        apagar = No;
        No = No->direita;
        delete apagar;
        return;
    }

    node<tipo> *pai;
    while(maior->direita != NULL){
        pai = maior;
        maior = maior->direita;
    }
    maior ->direita = No ->direita;

    if(pai !=NULL){
        pai->direita = maior->esquerda;
        maior ->esquerda = No ->esquerda;
    }
    apagar = No;
    No = maior;
    delete apagar;
}



#endif // TAD_ARVORE_BINARIA_H_INCLUDED
