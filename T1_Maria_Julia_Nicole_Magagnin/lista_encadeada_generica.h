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
    TElemento<tipo> *aux = lista->inicio; //Coloca o início da lista em um auxiliar
    if(lista->inicio != NULL){ //Se houverem elementos na lista
        while(aux->proximo != NULL){ //Auxiliar percorre a lista
            aux=aux->proximo;
        }
        novo = new TElemento<tipo>; //Aloca-se um espaço para um novo elemento
        novo->elemento = dado; //O elemento do novo dado recebe o dado em questão
        novo->proximo = NULL; //O próximo item da lista será NULL, uma vez que estamos inserindo no fim

        aux->proximo=novo; //O próximo item, o último, será NULL
        return true;
    }else{ //Caso a lista esteja vazia
        novo = new TElemento<tipo>; //Aloca-se um novo elemento
        novo->elemento = dado; //O elemento do novo dado recebe o dado em questão
        novo->proximo = NULL;//O próximo item da lista será NULL, uma vez que estamos inserindo no fim
        lista->inicio=novo; //O primeiro item da lista recebe o dado
        return true;
    }

}

template <typename tipo>
bool remove_fim(TLista<tipo> *lista){
    if(lista->inicio == NULL){//Se a lista estiver vazia, não há remoção
       return false;
    }else{
        TElemento<tipo> *aux = lista->inicio; //Auziliar recebe primeiro elemento da listaa
        if(aux->proximo == NULL){ //Se o segundo item for nulo
            lista->inicio = aux->proximo;  //O início da lista apontará para o próximo item
            delete aux; //Deleta o item atual
            return true;
        }else{
        TElemento<tipo> *nav = lista->inicio->proximo;//Segundo elemento
            while(nav->proximo != NULL){ //Enquanto o próximo item percorrido for diferente de NULL
            aux = aux->proximo; // Percorre com os dois auxiliares
            nav = nav->proximo;
            }
            aux->proximo = NULL; //Vai estar sendo o penúltimo elemento, então aponta para  NULL e assim vira o ultimo
            delete nav;//É deletado o último eleemnto
            return true;
        }
    }
}

template <typename tipo>
bool insere_inicio(TLista<tipo> *lista, tipo dado){
    TElemento<tipo> *novo;
    novo = new TElemento<tipo>; //Aloca-se o novo elemento
    novo->elemento = dado; //Elemento recebe o dado passado por referência
    if(lista->inicio==NULL){ //Se o primeiro item da lista é nulo
        lista->inicio = novo; //O primeiro item recebe o novo elemento
        return true;
    }else{ //Se houverem elementos na lista
        novo->proximo = lista->inicio; //O próxio elemento recebe o início anterior
        lista->inicio= novo; //O início recebe o novo elemento
        return true;
    }
}


template <typename tipo>
bool remove_inicio(TLista<tipo> *lista){
    if(lista->inicio == NULL){ //Se a lista estiver vazia
        return false;
    }else{
        TElemento<tipo> *aux = lista->inicio; //Auxiliar recebe o início da lista
        lista->inicio = aux->proximo;//O início da lista recebe o a posição seguinte, usando um auxiliar.
        delete aux; //Deleta o auxiliar que está no início da lista
        return true;
    }
}

template <typename tipo>
bool insere_pos(TLista<tipo> *lista, tipo dado, int pos){
    if(pos == 0){ //Se a posição for 0
        insere_inicio(lista,dado); //Chama a função de inserir no início
        return true;
    }else{
        TElemento<tipo> *aux = lista->inicio; // Um auxiliar recebe o início da lista
       int i=0;
        while(i<pos-1 && aux->proximo != NULL  ){ // Enquanto i for menor que a posição -1 e o próximo item não for nulo
            aux = aux->proximo; //percorre
            i++;

        }
            TElemento<tipo> *novo = new TElemento<tipo>; //Aloca-se um novo elemento
            novo->elemento = dado; //Esse elemento recebe o dado
            novo->proximo = aux->proximo; //O próximo elemento é igual ao próximo a ser percorrido pelo auxiliar
            aux->proximo = novo; //É adicionado o novo elemento
            return true;
    }
}


template<typename tipo>
bool remove_pos(TLista<tipo> *lista, int pos){
    TElemento<tipo> *aux=lista->inicio;//Um auxiliar recebe lista inicio
    TElemento<tipo> *deletar=lista->inicio->proximo; //É criada uma variável auxiliar que recébe o segundo elemento da lista
    if(lista->inicio==NULL){
        return false; //Se a lista estiver vazia, é retornado falso
    }else if(pos == 0){//Se a posição for 0, é chamado remove início
        remove_inicio(lista);

    }else{
        for(int i=0; i=pos; i++){ //Entre i =0 e até chegar na posição
            aux = aux->proximo; //As variáveis percorrem a lista
            deletar = deletar->proximo;
        }
        aux ->proximo = deletar->proximo; //Ao chegar na posição, a posição atual do "deletar", torna-se a do auxiliar
        delete deletar; //Deletamos o valor em "deletar"
           return true;
    }
}
template <typename tipo>
void bubblesort(TLista<tipo> *lista){
    int i,j;
    for(i=0;i<quant_lista(lista);i++){//Primeiro for para executar a comparação de cada um dos elementos a serem ordenados
        TElemento<tipo> *nav = lista->inicio;
        for(j=0;j<quant_lista(lista)-1;j++){//Segundo for para executar as comparações a cada dois elementos da lista
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
TElemento<tipo>* retorna_elemento(TLista<tipo> *lista, int pos)//Função que retorna o elemento na posição
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
    if (inicio > fim) //Se o início da lista for maior que o fim, retorna nulo
    {
        return NULL;
    }

    tipo temp;
    int cima = fim;
    int baixo = inicio;

    TElemento <tipo> *pivo    = retorna_elemento(lista, inicio); //Variáveis recebem o elemento na posição da lista a fim de comparação
    TElemento <tipo> *elementoBaixo   = retorna_elemento(lista, baixo);
    TElemento <tipo> *elementoCima     = retorna_elemento(lista, cima);

    while (baixo < cima) //Se o elemento "cima" for maior que o elemento "baixo"
    {
        while (elementoBaixo->elemento <= pivo->elemento && baixo < fim) //E o elemento "baixo" for menor ou igual ao pivo e "baixo" menor do que o fim
        {
            baixo++;
            elementoBaixo = elementoBaixo->proximo; //Elemento "baixo" aponta para o próximo
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
            elementoCima->elemento = temp; //É realizada a troca

    }

    temp = pivo->elemento; //É realizada a troca
    pivo->elemento = elementoCima->elemento;
    elementoCima->elemento = temp;

    quickSort(lista, inicio, cima - 1); //Chama a função recursivamente até a lista estar ordenada
    quickSort(lista, cima + 1, fim);
}


}



#endif // LISTA_ENCADEADA_GENERICA_H_INCLUDED
