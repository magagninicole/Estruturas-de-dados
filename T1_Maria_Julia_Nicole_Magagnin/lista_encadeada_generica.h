#ifndef LISTA_ENCADEADA_GENERICA_H_INCLUDED
#define LISTA_ENCADEADA_GENERICA_H_INCLUDED

#include <iostream>


using namespace std;

template<typename tipo>
struct dado{
    tipo dado;
};

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento<tipo> *proximo;
};

template <typename tipo>
struct TLista{
    TElemento<tipo> *inicio;

};

template <typename tipo>
bool incializa_lista(TLista<tipo> *lista){
    lista->inicio=NULL; //Inicializa lista
    return true;
}



   template<typename tipo>
bool insere_fim(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *novo;
    TElemento<tipo> *aux = lista->inicio; //Coloca o in�cio da lista em um auxiliar
    if(lista->inicio != NULL){ //Se houverem elementos na lista
        while(aux->proximo != NULL){ //Auxiliar percorre a lista
            aux=aux->proximo;
        }
        novo = new TElemento<tipo>; //Aloca-se um espa�o para um novo elemento
        novo->elemento = dado; //O elemento do novo dado recebe o dado em quest�o
        novo->proximo = NULL; //O pr�ximo item da lista ser� NULL, uma vez que estamos inserindo no fim

        aux->proximo=novo; //O pr�ximo item, o �ltimo, ser� NULL
        return true;
    }else{ //Caso a lista esteja vazia
        novo = new TElemento<tipo>; //Aloca-se um novo elemento
        novo->elemento = dado; //O elemento do novo dado recebe o dado em quest�o
        novo->proximo = NULL;//O pr�ximo item da lista ser� NULL, uma vez que estamos inserindo no fim
        lista->inicio=novo; //O primeiro item da lista recebe o dado
        return true;
    }

}

template <typename tipo>
bool remove_fim(TLista<tipo> *lista){
    if(lista->inicio == NULL){//Se a lista estiver vazia, n�o h� remo��o
       return false;
    }else{
        TElemento<tipo> *aux = lista->inicio; //Auziliar recebe primeiro elemento da listaa
        if(aux->proximo == NULL){ //Se o segundo item for nulo
            lista->inicio = aux->proximo;  //O in�cio da lista apontar� para o pr�ximo item
            delete aux; //Deleta o item atual
            return true;
        }else{
        TElemento<tipo> *nav = lista->inicio->proximo;//Segundo elemento
            while(nav->proximo != NULL){ //Enquanto o pr�ximo item percorrido for diferente de NULL
            aux = aux->proximo; // Percorre com os dois auxiliares
            nav = nav->proximo;
            }
            aux->proximo = NULL; //Vai estar sendo o pen�ltimo elemento, ent�o aponta para  NULL e assim vira o ultimo
            delete nav;//� deletado o �ltimo eleemnto
            return true;
        }
    }
}

template <typename tipo>
bool insere_inicio(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *novo;
    novo = new TElemento<tipo>; //Aloca-se o novo elemento
    novo->elemento = dado; //Elemento recebe o dado passado por refer�ncia
    if(lista->inicio==NULL){ //Se o primeiro item da lista � nulo
        lista->inicio = novo; //O primeiro item recebe o novo elemento
        return true;
    }else{ //Se houverem elementos na lista
        novo->proximo = lista->inicio; //O pr�xio elemento recebe o in�cio anterior
        lista->inicio= novo; //O in�cio recebe o novo elemento
        return true;
    }
}


template <typename tipo>
bool remove_inicio(TLista<tipo> *lista){
    if(lista->inicio == NULL){ //Se a lista estiver vazia
        return false;
    }else{
        TElemento<tipo> *aux = lista->inicio; //Auxiliar recebe o in�cio da lista
        lista->inicio = aux->proximo;//O in�cio da lista recebe o a posi��o seguinte, usando um auxiliar.
        delete aux; //Deleta o auxiliar que est� no in�cio da lista
        return true;
    }
}

template <typename tipo>
bool insere_pos(TLista<tipo> *lista, tipo dado, int pos){
    if(pos == 0){ //Se a posi��o for 0
        insere_inicio(lista,dado); //Chama a fun��o de inserir no in�cio
        return true;
    }else{
        TElemento<tipo> *aux = lista->inicio; // Um auxiliar recebe o in�cio da lista
       int i=0;
        while(i<pos-1 && aux->proximo != NULL  ){ // Enquanto i for menor que a posi��o -1 e o pr�ximo item n�o for nulo
            aux = aux->proximo; //percorre
            i++;

        }
            TElemento<tipo> *novo = new TElemento<tipo>; //Aloca-se um novo elemento
            novo->elemento = dado; //Esse elemento recebe o dado
            novo->proximo = aux->proximo; //O pr�ximo elemento � igual ao pr�ximo a ser percorrido pelo auxiliar
            aux->proximo = novo; //� adicionado o novo elemento
            return true;
    }
}


template<typename tipo>
bool remove_pos(TLista<tipo> *lista, int pos){
    TElemento<tipo> *aux=lista->inicio;//Um auxiliar recebe lista inicio
    TElemento<tipo> *deletar=lista->inicio->proximo; //� criada uma vari�vel auxiliar que rec�be o segundo elemento da lista
    if(lista->inicio==NULL){
        return false; //Se a lista estiver vazia, � retornado falso
    }else if(pos == 0){//Se a posi��o for 0, � chamado remove in�cio
        remove_inicio(lista);

    }else{
        for(int i=0; i=pos; i++){ //Entre i =0 e at� chegar na posi��o
            aux = aux->proximo; //As vari�veis percorrem a lista
            deletar = deletar->proximo;
        }
        aux ->proximo = deletar->proximo; //Ao chegar na posi��o, a posi��o atual do "deletar", torna-se a do auxiliar
        delete deletar; //Deletamos o valor em "deletar"
           return true;
    }
}
template <typename tipo>
void bubblesort(TLista<tipo> *lista){
    int i,j;
    for(i=0;i<quant_lista(lista);i++){//Primeiro for para executar a compara��o de cada um dos elementos a serem ordenados
        TElemento<tipo> *nav = lista->inicio;
        for(j=0;j<quant_lista(lista)-1;j++){//Segundo for para executar as compara��es a cada dois elementos da lista
            if(nav->elemento > nav->proximo->elemento){//Se um elemento for maior que o outro, troca dados
                tipo aux;
                aux = nav->elemento;
                nav->elemento = nav->proximo->elemento;
                nav->proximo->elemento = aux;
            }
            nav = nav->proximo; //Percorre a lista
        }
    }
}



template <typename tipo> //Contador de elementos
int quant_lista(TLista<tipo>*lista){
    int i=0;
    TElemento<tipo> *aux = lista->inicio;
    while(aux != NULL){
        aux = aux->proximo;
        i++;
    }
    return i;
    }


template <typename tipo>
TElemento<tipo>* retorna_elemento(TLista<tipo> *lista, int pos)//Fun��o que retorna o elemento na posi��o
{
    if (pos < 0 || pos >= quant_lista(lista) || lista->inicio == NULL)
    {
        return NULL;
    }
    else
    {
        int i = 0;
       TElemento<tipo> *aux = lista->inicio;

        while (i < pos && aux != NULL)
        {
            aux = aux->proximo;
            i++;
        }

        return aux;
    }
}

template <typename tipo>
void quickSort(TLista <tipo> *lista, int inicio, int fim) //Quicksort
{
    if (inicio > fim) //Se o in�cio da lista for maior que o fim, retorna nulo
    {
        return NULL;
    }

    tipo temp;
    int cima = fim;
    int baixo = inicio;

    TElemento <tipo> *pivo    = retorna_elemento(lista, inicio); //Vari�veis recebem o elemento na posi��o da lista a fim de compara��o
    TElemento <tipo> *elementoBaixo   = retorna_elemento(lista, baixo);
    TElemento <tipo> *elementoCima     = retorna_elemento(lista, cima);

    while (baixo < cima) //Se o elemento "cima" for maior que o elemento "baixo"
    {
        while (elementoBaixo->elemento <= pivo->elemento && baixo < fim) //E o elemento "baixo" for menor ou igual ao pivo e "baixo" menor do que o fim
        {
            baixo++;
            elementoBaixo = elementoBaixo->proximo; //Elemento "baixo" aponta para o pr�ximo
        }

        while (elementoCima->elemento > pivo->elemento) //Elemento "cima" menor que o elemento pivo
        {
            cima--; //Elemento "cima" diminui
            elementoCima = retorna_elemento(lista, cima); //Elemento "cima" recebe novo elemento "cima"
        }

        if (baixo < cima) //Se elemento "baixo" menor que elemento "cima"
        {
            temp = elementoBaixo->elemento;
            elementoBaixo->elemento = elementoCima->elemento;
            elementoCima->elemento = temp; //� realizada a troca

    }

    temp = pivo->elemento; //� realizada a troca
    pivo->elemento = elementoCima->elemento;
    elementoCima->elemento = temp;

    quickSort(lista, inicio, cima - 1); //Chama a fun��o recursivamente at� a lista estar ordenada
    quickSort(lista, cima + 1, fim);
}


}



#endif // LISTA_ENCADEADA_GENERICA_H_INCLUDED
