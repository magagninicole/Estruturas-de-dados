#ifndef FILAESTADIO_TAD_H_INCLUDED
#define FILAESTADIO_TAD_H_INCLUDED
#include <iostream>

using namespace std;

template<typename tipo>
struct Data{
    tipo dado;
};

template <typename tipo>
struct TElementoF{
    tipo elemento;
    TElementoF<tipo>*proximo;
};

template<typename tipo>
struct TFila{
    TElementoF<tipo>*inicio;
};

template<typename tipo>
bool inicializa_fila(TFila<tipo> &fila){
    fila.inicio = NULL;
    return true;
}
template<typename tipo>
void QUEUE(TFila<tipo> &fila, tipo dado){
    TElementoF<tipo>*data;
    TElementoF<tipo>*percorre = fila.inicio; //Auxiliar recebe in�cio da fila
    if(fila.inicio != NULL){//Se houver itens na fila
    while(percorre->proximo != NULL){ //Enquanto n�o chegar ao fim da fila
        percorre= percorre->proximo;//Percorre a fila
    }
    data = new TElementoF<tipo>; // Aloca o novo dado
    percorre->proximo = data; //O pr�ximo elemento (fim da fila) recebe o dado
    data -> elemento = dado;//O elemento do dado recebe o dado enviado do programa
    data -> proximo = NULL; // O pr�ximo elemento � nulo e o novo fim da fila

    }else{//Se a fila estiver vazia
        data = new TElementoF<tipo>;
        data->elemento = dado; //O elemento recebe o dado enviado do programa
        data->proximo = NULL; // O pr�ximo elemento � nulo e o fim da fila
        fila.inicio=data; //O in�cio da fila recebe o dado
    }
}

template<typename tipo>
tipo DEQUEUE(TFila<tipo> &fila){
    if(fila.inicio==NULL){//Se a fila estiver vazia, n�o � realizada a opera��o

    }else{
        tipo dado = fila.inicio -> elemento; //A vari�vel de retorno recebe o primeiro elemento da fila
        TElementoF<tipo>*apagar = fila.inicio; //A vari�vel apagar recebe o in�cio da fila
        fila.inicio = fila.inicio->proximo; //o in�cio da fila aponta para quem est� atr�s dele na fila
        delete apagar;//Deleta-se o primeiro elemento
        return dado; //Retorna o dado do mesmo
    }
}
template<typename tipo>
tipo primeiro_elemento(TFila<tipo> &fila){ //Fun��o para "pegar" o primeiro elemento da fila
    if(fila.inicio!=NULL){//Se houver elementos na fila
       tipo primeiro = fila.inicio->elemento; //O primeiro elemento � retornado
       return primeiro;
    }else{
        return NULL; //Caso contr�rio, n�o h� retorno
    }
}

template <typename tipo>
int tamanho_fila(TFila<tipo> fila){ //Contador de pessoas na fila
    TElementoF<tipo> *percorre = fila.inicio; //Auxiliar recebe o in�cio da fila
    int cont=0;
    while(percorre!=NULL){//Enquanto o auxiliar n�o chegar ao fim da fila
        percorre = percorre->proximo;//O auxiliar percorre
        cont++;//Contador soma +1 pessoa na fila
    }
    return cont; //Retorna contador
}

template <typename tipo>
void altera_inicio(TFila<tipo> &fila, tipo dado){//Fun��o para alterar o in�cio da fila
    if(fila.inicio!=NULL){ //Se houver elementos na fila
        TElementoF<tipo> *percorre = fila.inicio; //Auxiliar recebe o in�cio da fila
        percorre->elemento=dado; //Primeiro elemento da fila � alterado com o dado vindo do programa
    }
}

#endif // FILAESTADIO_TAD_H_INCLUDED
