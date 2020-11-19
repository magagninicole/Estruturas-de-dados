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
    lista->fim = NULL; // Inicializa a lista, deixando nula no início e no fim
    return true;
}

template<typename tipo>
bool insere_fim_duplamente(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *data; //É criado um elemento para o dado
    TElemento<tipo> *percorre = lista->inicio; //É criado um auxiliar para percorrer a lista
    if(lista->inicio != NULL){ //Se a lista estiver inicializada
        data = new TElemento<tipo>; //Aloca-se um espaço na memória para o dado
        data->elemento = dado; //É colocado o dado no espaço de elemento da variável data
        data->anterior = lista->fim; //O anterior ao dado será o fim da lista
        lista->fim->proximo = data->elemento; //E o próximo item ao fim da lista, recebe o dado
        data->proximo = NULL; // O próximo elemento do dado é nulo, a lista chegou ao fim
        return true;
    }else{ //Caso a lista esteja vazia
        data = new TElemento<tipo>; //Aloca-se um espaço na memória para o dado
        data->elemento = dado; //É colocado o dado no espaço de elemento da variável data
        data->proximo = NULL;// O próximo elemento do dado é nulo, a lista chegou ao fim
        data->anterior = NULL;// O  elemento anterior do dado é nulo, já que a lista está vazia
        lista->inicio=data; //O primeiro item recebe o dado
        return true;
    }

}

template<typename tipo>
bool remove_fim_duplamente(TLista<tipo> *lista){ //errada
    if(lista->inicio==NULL){ //Caso a lista estaja vazia
        return false;
    }else{
        TElemento<tipo> *percorre = lista->fim; //Caso contrário, um auxiliar recebe o último item
    if(percorre ->anterior != NULL){ //Se houverem mais itens na lista
        percorre->anterior->proximo = percorre->proximo; //O item atual recebe o próximo
    }else{//Senão
        lista->inicio = percorre->proximo; //O início da lista recebe o próximo item
    }
    lista->fim = percorre->anterior; //O fim da lista recebe o item anterior ao percorrido
    delete percorre; //Deleta-se a variável auxliliar
    return true;
        }
    }


template<typename tipo>
bool insere_inicio_duplamente(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *data;
    data = new TElemento<tipo>;//Aloca-se um espaço na memória para o novo dado
    data->elemento = dado;//Elemento recebe o dado passado por parâmetro
    data->proximo = lista->inicio; //O próximo ao dado será o atual início da lista
    data ->anterior = NULL; //O anterior a isso, é nulo, já que é antes do início da lista
    if(lista->inicio!=NULL){//Se a lista não estiver vazia
        lista->inicio->anterior = data; //O anterior ao início recebe os dados
    }else { //Se estiver
        lista->fim = data; //O fim da lista recebe os dados
    }
    lista->inicio = data; //Lista início recebe o dado
    return true;
}

template<typename tipo>
bool remove_inicio_duplamente(TLista<tipo> *lista){
    TElemento<tipo> *percorre=lista->inicio;
    if(lista->inicio==NULL){ //Se a lista estiver vazia
        return false;
    }else{
        lista->inicio= lista->inicio->proximo; //O primeiro da lista recebe o próximo
        lista ->inicio->anterior = NULL; //O anterior ao início da lista é nulo
        delete percorre;
        return true; //Deleta-se o auxiliar que está com o início da lista
    }
}


template<typename tipo>
bool remove_posicao_duplamente(TLista<tipo> *lista, int pos){
    TElemento<tipo> *percorre = lista -> inicio; //Auxiliar recebe o início da lista
    if(lista->inicio==NULL){
        return false;
    }else{
        for(int i=0; i<pos; i++){ //Percorre-se a lista até chegar na posição
            percorre = percorre->proximo;
        }
      percorre->anterior->proximo = percorre->proximo; //A posição atual é igual a próxima
        delete percorre; //Deleta a posição
           return true;
    }
}

template<typename tipo>
bool insere_posicao_duplamente(TLista<tipo> *lista, int pos, tipo dado){
    TElemento<tipo> *percorre = lista->inicio; //Auxiliar recebe o início da lista
    TElemento<tipo> *data;
    data= new TElemento<tipo>;//Aloca-se um espaço na memória +ara o dado
    data->elemento = dado; //O elemento dado recebe o dado
    if(pos==0){//Se a posição for zero
        lista->inicio = lista->inicio->proximo; //O primeiro da lista recebe o próximo
        lista -> inicio ->proximo->anterior = lista ->inicio; //lista início recebe listá início
        lista ->inicio = data; //lista início recebe o dado
        lista ->inicio->anterior =NULL; // O anterior a lista início é nulo
        return true;
    }else{
        for(int i=0; i<pos-1; i++){ //Para outras posições, percorre-se até encontrar a mesma
            percorre = percorre->proximo;
        }
        data->proximo = percorre->proximo; //O próximo do dado é recebe o próximo item a ser percorrido
        percorre ->proximo = data; //O próximo item recebe o dado
        data->anterior = percorre; //O dado anterior recebe o anterior ao novo dado
        return true;
    }
return false;
}

template <typename tipo>
void bubblesort(TLista<tipo> *lista){
    int i,j;
    for(i=0;i<quantidade_duplamente(lista);i++){//Primeiro for para executar a comparação de cada um dos elementos a serem ordenados
        TElemento<tipo> *percorre = lista->inicio;
        for(j=0;j<quantidade_duplamente(lista)-1;j++){//Segundo for para executar as comparações a cada dois elementos da lista
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
TElemento<tipo>* retorna_elemento(TLista<tipo> *lista, int pos)//Função que retorna o elemento na posição
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
    if (inicio > fim)//Se o início da lista for maior que o fim, retorna nulo
    {
        return;
    }

    tipo temp;
    int cima = fim;
    int baixo = inicio;

    TElemento <tipo> *pivo    = retorna_elemento(lista, inicio); //Variáveis recebem o elemento na posição da lista a fim de comparação
    TElemento <tipo> *elementoBaixo  = retorna_elemento(lista, baixo);
    TElemento <tipo> *elementoCima   = retorna_elemento(lista, cima);

    while (baixo < cima)//Se o elemento "cima" for maior que o elemento "baixo"
    {
        while (elementoBaixo->elemento <= pivo->elemento && baixo < fim) //E o elemento "baixo" for menor ou igual ao pivo e "baixo" menor do que o fim
        {
            baixo++;
            elementoBaixo = elementoBaixo->proximo;//Elemento "baixo" aponta para o próximo
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
            elementoCima->elemento = temp;//É realizada a troca
        }
    }

    temp = pivo->elemento;//É realizada a troca
    pivo->elemento = elementoCima->elemento;
    elementoCima->elemento = temp;

    quickSort(lista, inicio, cima - 1);//Chama a função recursivamente até a lista estar ordenada
    quickSort(lista, cima + 1, fim);
}




#endif // LISTA_DUPLAMENTE_ENCADEADA_GENERICA_H_INCLUDED
