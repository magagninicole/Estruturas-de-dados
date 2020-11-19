#ifndef HASH_ENCADEADA_H_INCLUDED
#define HASH_ENCADEADA_H_INCLUDED

template<typename tipo>
struct Hash_Encadeada {
    tipo dado;
    Hash_Encadeada *prox;
};

template <typename tipo, int TAM>
void inicializa_encadeado(Hash_Encadeada<tipo> *tabela[]) {
    for(int i=0; i<TAM; i++) {
        tabela[i] = NULL;
    }
}

int hashing(int chave, int TAM){
    return (chave%TAM);
}

template <typename tipo, int TAM>
bool insere_encadeado(Hash_Encadeada<tipo> *tabela[], tipo dado) {
    int pos = hashing(dado, TAM);
    Hash_Encadeada<tipo> *aux = new Hash_Encadeada<int>;
    aux->dado = dado;
    aux->prox = tabela[pos];
    tabela[pos] = aux;
    return true;
}

template <typename tipo, int TAM>
bool remove_encadeado(Hash_Encadeada<tipo> *tabela[], int chave){
    int pos = hashing(chave, TAM);
    if(tabela[pos] != NULL){
        if(tabela[pos]->dado == chave){
            tabela[pos]=tabela[pos]->prox;
            return true;
        }
    }else{
        Hash_Encadeada<tipo> *aux = tabela[pos]->prox;
        Hash_Encadeada<tipo> *ant = tabela[pos];
        while(aux != NULL && aux->dado != chave){
            ant = aux;
            aux = aux->prox;
        }
        if(aux!= NULL){
            ant->prox = aux->prox;
            delete aux;
            return true;
        }else{
            return false;///Não há o elemento na tabela
        }
    }
}
void imprime(Hash_encadeada *tabela[]){
    int i;
    cout<<"\n\nPOSICAO\tCHAVE\n";
    for(i=0;i<TAM;i++){
        if(tabela[i] == NULL)
            cout<<i<<"\t"<<" "<<"\n--------------\n";
        else{
            Hash_encadeada *Percorre;
            Percorre= tabela[i];
            cout<<i<<"\t"<<Percorre->chave;
            while(Percorre->proximo != NULL){
                cout<<" -> "<<Percorre->proximo->chave;
                Percorre = Percorre->proximo;
            }
            cout<<"\n--------------\n";
        }
    }
}


#endif // HASH_ENCADEADA_H_INCLUDED
