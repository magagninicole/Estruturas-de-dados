#ifndef LISTA_ESTATICA_GENERICA_H_INCLUDED
#define LISTA_ESTATICA_GENERICA_H_INCLUDED
#include<iostream>


using namespace std;

template<typename tipo>
struct data{
    tipo dado;
};

template<typename tipo,int MAX>
struct TLista{
    data <tipo> elementos[MAX];
    int tamanho;
};

template<typename tipo, int MAX>
 bool inicializa_lista(TLista <tipo, MAX> &lista){
    lista.tamanho=0; //Coloca o tamanho da lista como zero
    return true;
}

template<typename tipo,int MAX>
bool insere_fim(TLista<tipo, MAX> &lista, tipo dado){
    if(lista.tamanho < MAX){
    lista.elementos[lista.tamanho].dado = dado; //Insere o dado no "lista.tamanho", ou seja, na �ltima posi��o
    lista.tamanho++; // Soma mais um no tamanho da lista
    return true;
}
else {

    return false;
}
}

template<typename tipo,int MAX>
bool remove_fim(TLista<tipo, MAX> &lista){
    if(lista.tamanho > 0){ //Se a lista n�o est� vazia
        lista.tamanho--;//Diminui o tamanho da lista, tirando o �ltimo item
        return true;
    }else{

    return false;
    }

    }

template<typename tipo,int MAX>
bool remove_inicio(TLista<tipo,MAX> &lista){

    if(lista.tamanho > 0){
        for(int i=0; i< lista.tamanho-1;i++){
            lista.elementos[i] = lista.elementos[i+1]; //Passa o elemento atual para a pr�xima posi��o
            return true;
        }
        lista.tamanho--; //Diminui o tamanho da lista

}
return false;
}

template<typename tipo,int MAX>
bool insere_inicio(TLista<tipo,MAX> &lista,tipo dado){
        if(lista.tamanho > 0){
        for(int i=0; i< lista.tamanho;i++){
            lista.elementos[i] = lista.elementos[i-1]; //Passa o elemento atual para a frente
        }
        lista.elementos[0].dado = dado; //Adiciona o elemento na primeira posi��o da lista
        lista.tamanho++; // Aumenta o tamanho da lista

        return true;
}

return false;
}


template<typename tipo,int MAX>
bool insere_posicao(TLista<tipo,MAX> &lista,  tipo dado, int posicao){
    if((lista.tamanho<MAX)and (posicao <=lista.tamanho)){ //Se a lista estiver dentro do n�mero de elementos definito
        for(int i = lista.tamanho - 1; i+1>posicao; i--){
            lista.elementos[i+1].dado = lista.elementos[i].dado; //O pr�ximo elemento � igual ao anterior, passa "um para tr�s"

        }

        lista.elementos[posicao].dado = dado; //Insere o dado na posi��o
        lista.tamanho++; //Aumenta o tamanho da lista


         return true;
    }else{
return false;
    }
}

template<typename tipo,int MAX>
bool remove_posicao(TLista<tipo,MAX> &lista, tipo dado, int posicao){
    if(lista.tamanho >0|| (posicao <= lista.tamanho)){ //Se a lista n�o � nula e a posi��o � menor que o tamanho da lista
        for(int i=posicao; i< lista.tamanho-1;i++){
            lista.elementos[i].dado = lista.elementos[i+1].dado; //Passa os elementos para a frente
            lista.tamanho--; //Diminui o tamanho da lista
            return true;
        }
    }
    return false;
}
template<typename tipo,int MAX>
void bubblesort(TLista<tipo,MAX> &lista){
    int i, j, cond;
    tipo temp;
    cond = 1;

    for(i= lista.tamanho - 1;(i>=1) &&(cond =1); i--){ //Enquanto i maior ou igual a 1 e a condi��o � verdadeira
        cond =0;
            for(j=0;j<i;j++){ // De j igual a zero at� j sendo o tamanho da lista -1
                    if(lista.elementos[j+1].dado < lista.elementos[j].dado){
                        temp = lista.elementos[j].dado;
                        lista.elementos[j].dado =lista.elementos[j+1].dado;
                        lista.elementos[j+1].dado = temp;
                        cond=1;
                    }

            }
    }
}

template<typename tipo,int MAX>
void quicksort(TLista<tipo, MAX> &lista,int inicio, int fim){//Quick Sort
    int i, j, pivo;
    if(inicio<fim){
        pivo=inicio;
        i=inicio;
        j=fim;
        while(i<j){
            while(lista.elementos[i].dado<=lista.elementos[pivo].dado&&i<fim)
                i++;
            while(lista.elementos[j].dado>lista.elementos[pivo].dado)
                j--;
            if(i<j){
                swap(lista.elementos[i].dado,lista.elementos[j].dado);
            }
        }
        swap(lista.elementos[pivo].dado,lista.elementos[j].dado);
        quicksort(lista,inicio,j-1);
        quicksort(lista,j+1,fim);
    }
}



#endif // LISTA_ESTATICA_GENERICA_H_INCLUDED
