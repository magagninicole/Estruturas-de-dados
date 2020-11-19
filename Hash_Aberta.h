#ifndef HASH_ABERTA_H_INCLUDED
#define HASH_ABERTA_H_INCLUDED
template<typename tipo>
struct TabelaH {
    char status;
    tipo dado;
};

template <typename tipo, int TAM>
void inicializa_Tabela(TabelaH<tipo> tabela[]) {
    for(int i=0; i<TAM; i++) {
        tabela[i].status = 'L';
    }
}

int hashing(int chave, int TAM){
    return (chave%TAM);
}

template <typename tipo, int TAM>
bool insere_aberta(TabelaH<tipo> tabela[], tipo dado) {
    bool insere = true;
    int i=0;
    int pos = hashing(dado, TAM);
    while(insere) {
        if(tabela[pos].status=='L'){
            tabela[pos].dado = dado;
            tabela[pos].status = 'O';
            return true;
        }else if(i<TAM){
            pos = hashing(dado+1, TAM);
            i++;
        }else{
            return false;
        }
    }
}

template <typename tipo, int TAM>
bool remove_aberta(TabelaH<tipo> tabela[], int chave){
    bool removido = true;
    int pos = hashing(chave, TAM), i=0;
    while(removido){
        if(tabela[pos].status=='O' && tabela[pos].dado==chave){
            tabela[pos].status= 'R';
            return true;
        }else if(tabela[pos].status=='O' && i<TAM){
            pos = hashing(chave+1, TAM);
            i++;
        }else{
            return false;
        }
    }
}
#endif // HASH_ABERTA_H_INCLUDED
