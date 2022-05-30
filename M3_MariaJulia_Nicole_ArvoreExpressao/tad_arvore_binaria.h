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
    Arvore.raiz = NULL; //Inicia a �rvore em NULL
    return true;
}

template <typename tipo>
bool insere_arvore(node<tipo> *&No, tipo dado , int chave){
  if(No==NULL){ //Se o n� recebido for nulo
    No= new node<tipo>; //Aloca posi��o
    No->chave = chave; //A chave do n� recebe a chave
    No->dado = dado; //Dado recebe o dado
    No->esquerda=NULL; //A esquerda e a direita seguem nulos
    No->direita=NULL; //Garantindo encadeamento
    return true;
  }else{
    if(chave>No->chave){ //Se a chave for maior que a chave do n�
    insere_arvore(No->direita,dado,chave); //Chama recursivamente a direita
      }else if (chave<No->chave){ //Se for menor
        insere_arvore(No->esquerda,dado,chave); //Chama recursivamente a esquerda
  }else{
    return false; //Sen�o, retorna false
  }
}
}


#endif // TAD_ARVORE_BINARIA_H_INCLUDED
