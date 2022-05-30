#ifndef LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED
#define LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED
#include<iostream>

using namespace std;

template<typename tipo>
struct Dado{
    tipo dado;
};

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento *proximo;
    TElemento *anterior;
};

template<typename tipo>
struct TLista{
    TElemento<tipo> *inicio;
    TElemento<tipo> *fim;
};

template<typename tipo>
bool inicializa_duplamente(TLista<tipo> *lista){
    lista->inicio = NULL;
    lista->fim = NULL; // Inicializa a lista, deixando nula no in�cio e no fim
    return true;
}

template<typename tipo>
bool insere_fim_duplamente(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *data; //� criado um elemento para o dado
    TElemento<tipo> *percorre = lista->inicio; //� criado um auxiliar para percorrer a lista
    if(lista->inicio != NULL){ //Se a lista estiver inicializada
        data = new TElemento<tipo>; //Aloca-se um espa�o na mem�ria para o dado
        data->elemento = dado; //� colocado o dado no espa�o de elemento da vari�vel data
        data->anterior = lista->fim; //O anterior ao dado ser� o fim da lista
        lista->fim->proximo = data->elemento; //E o pr�ximo item ao fim da lista, recebe o dado
        data->proximo = NULL; // O pr�ximo elemento do dado � nulo, a lista chegou ao fim
        return true;
    }else{ //Caso a lista esteja vazia
        data = new TElemento<tipo>; //Aloca-se um espa�o na mem�ria para o dado
        data->elemento = dado; //� colocado o dado no espa�o de elemento da vari�vel data
        data->proximo = NULL;// O pr�ximo elemento do dado � nulo, a lista chegou ao fim
        data->anterior = NULL;// O  elemento anterior do dado � nulo, j� que a lista est� vazia
        lista->inicio=data; //O primeiro item recebe o dado
        return true;
    }

}

template<typename tipo>
bool remove_fim_duplamente(TLista<tipo> *lista){ //errada
    if(lista->inicio==NULL){ //Caso a lista estaja vazia
        return false;
    }else{
        TElemento<tipo> *percorre = lista->fim; //Caso contr�rio, um auxiliar recebe o �ltimo item
    if(percorre ->anterior != NULL){ //Se houverem mais itens na lista
        percorre->anterior->proximo = percorre->proximo; //O item atual recebe o pr�ximo
    }else{//Sen�o
        lista->inicio = percorre->proximo; //O in�cio da lista recebe o pr�ximo item
    }
    lista->fim = percorre->anterior; //O fim da lista recebe o item anterior ao percorrido
    delete percorre; //Deleta-se a vari�vel auxliliar
    return true;
        }
    }


template<typename tipo>
bool insere_inicio_duplamente(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *data;
    data = new TElemento<tipo>;//Aloca-se um espa�o na mem�ria para o novo dado
    data->elemento = dado;//Elemento recebe o dado passado por par�metro
    data->proximo = lista->inicio; //O pr�ximo ao dado ser� o atual in�cio da lista
    data ->anterior = NULL; //O anterior a isso, � nulo, j� que � antes do in�cio da lista
    if(lista->inicio!=NULL){//Se a lista n�o estiver vazia
        lista->inicio->anterior = data; //O anterior ao in�cio recebe os dados
    }else { //Se estiver
        lista->fim = data; //O fim da lista recebe os dados
    }
    lista->inicio = data; //Lista in�cio recebe o dado
    return true;
}

template<typename tipo>
bool remove_inicio_duplamente(TLista<tipo> *lista){
    TElemento<tipo> *percorre=lista->inicio;
    if(lista->inicio==NULL){ //Se a lista estiver vazia
        return false;
    }else{
        lista->inicio= lista->inicio->proximo; //O primeiro da lista recebe o pr�ximo
        lista ->inicio->anterior = NULL; //O anterior ao in�cio da lista � nulo
        delete percorre;
        return true; //Deleta-se o auxiliar que est� com o in�cio da lista
    }
}


template<typename tipo>
bool remove_posicao_duplamente(TLista<tipo> *lista, int pos){
    TElemento<tipo> *percorre = lista -> inicio; //Auxiliar recebe o in�cio da lista
    if(lista->inicio==NULL){
        return false;
    }else{
        for(int i=0; i<pos; i++){ //Percorre-se a lista at� chegar na posi��o
            percorre = percorre->proximo;
        }
      percorre->anterior->proximo = percorre->proximo; //A posi��o atual � igual a pr�xima
        delete percorre; //Deleta a posi��o
           return true;
    }
}

template<typename tipo>
bool insere_posicao_duplamente(TLista<tipo> *lista, int pos, tipo dado){
    TElemento<tipo> *percorre = lista->inicio; //Auxiliar recebe o in�cio da lista
    TElemento<tipo> *data;
    data= new TElemento<tipo>;//Aloca-se um espa�o na mem�ria +ara o dado
    data->elemento = dado; //O elemento dado recebe o dado
    if(pos==0){//Se a posi��o for zero
        lista->inicio = lista->inicio->proximo; //O primeiro da lista recebe o pr�ximo
        lista -> inicio ->proximo->anterior = lista ->inicio; //lista in�cio recebe list� in�cio
        lista ->inicio = data; //lista in�cio recebe o dado
        lista ->inicio->anterior =NULL; // O anterior a lista in�cio � nulo
        return true;
    }else{
        for(int i=0; i<pos-1; i++){ //Para outras posi��es, percorre-se at� encontrar a mesma
            percorre = percorre->proximo;
        }
        data->proximo = percorre->proximo; //O pr�ximo do dado � recebe o pr�ximo item a ser percorrido
        percorre ->proximo = data; //O pr�ximo item recebe o dado
        data->anterior = percorre; //O dado anterior recebe o anterior ao novo dado
        return true;
    }
return false;
}

template <typename tipo>
void bubblesort(TLista<tipo> *lista){
    int i,j;
    for(i=0;i<quantidade_duplamente(lista);i++){//Primeiro for para executar a compara��o de cada um dos elementos a serem ordenados
        TElemento<tipo> *percorre = lista->inicio;
        for(j=0;j<quantidade_duplamente(lista)-1;j++){//Segundo for para executar as compara��es a cada dois elementos da lista
            if(percorre->elemento > percorre->proximo->elemento){//Se um elemento for maior que o outro, troca dados
                tipo aux;
                aux = percorre->elemento;
                percorre->elemento = percorre->proximo->elemento;
                percorre->proximo->elemento = aux;
            }
            percorre = percorre->proximo;//Percorre a lista
        }
    }
}


template<typename tipo>
int quantidade_duplamente(TLista<tipo> *lista){ //Contador de itens na lista
    TElemento<tipo> *percorre= lista->inicio;
    int cont=0;
    if(lista->inicio == NULL){
        return 0;
    }else{
        while(percorre!= NULL){
            percorre = percorre ->proximo;
            cont++;
        }
        return cont;
    }
}

template <typename tipo>
TElemento<tipo>* retorna_elemento(TLista<tipo> *lista, int pos)//Fun��o que retorna o elemento na posi��o
{
    if (pos < 0 || pos >= quantidade_duplamente(lista)|| lista->inicio == NULL)
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
void quickSort(TLista<tipo> *lista, int inicio, int fim) //QuickSort
{
    if (inicio > fim)//Se o in�cio da lista for maior que o fim, retorna nulo
    {
        return;
    }

    tipo temp;
    int cima = fim;
    int baixo = inicio;

    TElemento <tipo> *pivo    = retorna_elemento(lista, inicio); //Vari�veis recebem o elemento na posi��o da lista a fim de compara��o
    TElemento <tipo> *elementoBaixo  = retorna_elemento(lista, baixo);
    TElemento <tipo> *elementoCima   = retorna_elemento(lista, cima);

    while (baixo < cima)//Se o elemento "cima" for maior que o elemento "baixo"
    {
        while (elementoBaixo->elemento <= pivo->elemento && baixo < fim) //E o elemento "baixo" for menor ou igual ao pivo e "baixo" menor do que o fim
        {
            baixo++;
            elementoBaixo = elementoBaixo->proximo;//Elemento "baixo" aponta para o pr�ximo
        }

        while (elementoCima->elemento > pivo->elemento)//Elemento "cima" menor que o elemento pivo
        {
            cima--;//Elemento "cima" diminui
            elementoCima = elementoCima->anterior;//Elemento "cima" recebe o elemento "cima" anterior (cima--)
        }

        if (baixo < cima)//Se elemento "baixo" menor que elemento "cima"
        {
            temp = elementoBaixo->elemento;
            elementoBaixo->elemento = elementoCima->elemento;
            elementoCima->elemento = temp;//� realizada a troca
        }
    }

    temp = pivo->elemento;//� realizada a troca
    pivo->elemento = elementoCima->elemento;
    elementoCima->elemento = temp;

    quickSort(lista, inicio, cima - 1);//Chama a fun��o recursivamente at� a lista estar ordenada
    quickSort(lista, cima + 1, fim);
}




#endif // LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED
