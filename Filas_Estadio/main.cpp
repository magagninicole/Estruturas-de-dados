#include "FilaEstadio_TAD.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

using namespace std;

struct Pessoa{
 int tipo; //Normal ou socio
 int permanencia; //Tempo que a pessoa vai esperar na fila


};


void embaralha_fila(Pessoa pessoa[], int pessoas){ //Fun��o para embaralhar as pessoas na fila, a fim de que fiquem misturadas entre tempos
    int qtdPessoas = pessoas; //Vari�vel recebe a quantidade de pessoas
    int embaralha;
    Pessoa aux;
    int i=0;
    while (i < pessoas) { //Enquanto n�o atingir o n�mero m�ximo de pessoas
        embaralha = qtdPessoas - (rand() % pessoas + 1); // A vari�vel embaralha recebe um valor aleat�rio ao n�mero de pessoas
        aux = pessoa[embaralha]; //O auxiliar recebe a pessoa nessa posi��o
        pessoa[embaralha] = pessoa[i]; // A pessoa nessa posi��o, recebe a pessoa na posi��o i
        pessoa[i] = aux; // A pessoa na posi��o i, recebe a pessoa na posi��o embaralha, fazendo uma troca
        i++;
    }
}
int menor_fila(TFila<int> Fila[], int guiches){//Fun��o para verificar a menor fila
    int menor = tamanho_fila(Fila[0]); // Chama a fun��o de tamanho de fila para a fila 0 e coloca ela como menor
    int escolha=0; //Receber� a posi��o correspondente a menor fila
    for(int i=0; i<guiches; i++){
        if(menor > tamanho_fila(Fila[i])){ //Se menor for maior que o tamanho da fila atual
            menor = tamanho_fila(Fila[i]); // Temos uma nova menor
            escolha = i; // � salva a fila correspondente a menor fila
        }
    }
    return escolha; //Retorna a menor fila
}

void inserir_fila(TFila<int> guiche_n[], TFila<int> guiche_socio[], int pessoas, int guiche_normal, int guiche_st,Pessoa pessoa[], int &pessoaN, int &pessoaS){ //Fun��o de inserir na fila
    int fila; // Recebe a menor fila
    int normal; //Recebe a quantidade de pessoas normais
    int socio_t; //Recebe a quantidade de s�cios
    int normalN; //Auxiliar para porcentagem
    int socio_tempo;//Auxiliar para porcentagem
    int normal_tempo;//Auxiliar para porcentagem
    pessoaN=0; //Contador de pessoas normais
    pessoaS=0; //Contador s�cio torcedor

    socio_t = pessoas *0.05; //5% das pessoas s�o s�cios
    normal = pessoas - socio_t;//O resto s�o dormais

    for(int i=0; i<pessoas;i++){
        if(i< normal && guiche_normal>0){ //Caso hajam guiches normais e as pessoas sejam at� 95%
            pessoaN = pessoaN+1; //Soma quantidade de pessoas normais
            pessoa[i].tipo = 1; //95% das pessoas s�o fila normal
        }else if(i>=normal && guiche_st>0){ //Caso haja guiche s�cio e sejam at� 5% das pessoas
             pessoaS=pessoaS+1;
            pessoa[i].tipo = 0; //5% das pessoas s�o socio-torcedoras
        }else if(guiche_st<=0){ //Caso n�o haja guiche s�cio, todas as pessoas ir�o pela fila normal
            pessoaN=pessoaN+1;
            pessoa[i].tipo=1;
    }
}


    socio_tempo = pessoaN + (pessoaS*0.85); //Calcula 85% dos s�cios, levando em conta que eles est�o no fim do vetor pessoa
    normal_tempo = pessoaN*0.25; //Calcula 25% das pessoas normais
    normalN = pessoaN*0.55; //Calcula 55% das pessoas normais, que ser� reduzido pelos 25%, totalizando 30% das pessoas

    for(int i=0; i<pessoas;i++){
        if(pessoa[i].tipo==0){ //Se for socio
            if(i<=socio_tempo){//85% das pessoas v�o ser inseridas em 1 tempo na fila de s�cio
                    pessoa[i].permanencia = 1;//INSERE COM UMA UNIDADE DE TEMPO
            }else{//Outras 15% em 2 tempos
                 pessoa[i].permanencia = 2;//INSERE COM DUAS UNIDADES DE TEMPO
            }
        }else if(pessoa[i].tipo == 1){ //Se for normal
            if(i<normal_tempo){//25% s�o inseridos com 1 tempo
                     pessoa[i].permanencia = 1;//INSERE COM UMA UNIDADE DE TEMPO
            }else if(i>=normal_tempo && i<normalN){//30% s�o inseridos em 2 tempos
                 pessoa[i].permanencia = 2;//INSERE COM DUAS UNIDADE DE TEMPO
            }else{//OS outros 45% s�o inseridos em 3 tempos
                pessoa[i].permanencia = 3;//INSERE COM TRES UNIDADE DE TEMPO
            }
        }
    }

    embaralha_fila(pessoa,pessoas); //Embaralha a fila
    for(int i=0;i<pessoas;i++){
        if(pessoa[i].tipo==0){ //Se forem s�cios
            fila = menor_fila(guiche_socio,guiche_st); //Verifica a menor fila
            QUEUE(guiche_socio[fila],pessoa[i].permanencia); //Adiciona na menor fila de s�cios
        }else if(pessoa[i].tipo==1){ //Se forem normais
            fila = menor_fila(guiche_n,guiche_normal); //Verifica a menor fila
            QUEUE(guiche_n[fila],pessoa[i].permanencia);//Adiciona na menor fila do guiche normal
        }
    }
}


void contador_pessoas(Pessoa pessoa [], int pessoas, int &contadorS, int &contadorS_dois, int &contadorN, int &contadorN_dois,int &contadorN_tres){
for(int i=0; i<pessoas;i++){ //Conta quantas pessoas foram adicionadas no inicio da execu��o em cada fila, a fim de provar a m�dia
        if(pessoa[i].tipo == 0){
         if(pessoa[i].permanencia == 1){
            contadorS++;
        }else{
            contadorS_dois++;
        }
    }else if(pessoa[i].tipo ==1){
        if(pessoa[i].permanencia ==1){
            contadorN++;
        }else if(pessoa[i].permanencia ==2){
             contadorN_dois++;
        }else{
            contadorN_tres++;
        }
    }
}
}

void filas(TFila<int>guiche_n[], TFila<int>guiche_socio[], int guiche_st, int guiche_normal){//Fun��o que inicializa as filas

    for(int i=0; i<guiche_st;i++){
        inicializa_fila(guiche_socio[i]); //Inicializa guiches de s�cios
    }
      for(int i=0; i<guiche_normal;i++){
        inicializa_fila(guiche_n[i]); //Inicializa guiches normais
    }

}

void atendimento(TFila<int> guiche_n[], TFila<int> guiche_socio[],int guiche_normal,int guiche_st){ //Fun��o de atendimento
   int saida; //Vari�vel de perman�ncia

    if(guiche_normal!=NULL){ //SE HOUVER PESSOAS NA FILA NORMAL
        for(int i=0;i<guiche_normal;i++){
            if(tamanho_fila(guiche_n[i])!=0){ //SE HOUVER ELEMENTO NA FILA
                saida=primeiro_elemento(guiche_n[i]); //Sa�da recebe o tempo de perman�ncia
                if(saida == 1){//SE A QUANTIDADE DE TEMPO � 1
                    DEQUEUE(guiche_n[i]); //Se o tempo for um, a pessoa j� � retirada
                }else{
                    saida=saida-1; //DIMINUI A QUANTIDADE DE TEMPO
                    altera_inicio(guiche_n[i],saida);//Sen�o, altera o primeiro elemento da fila, mudando seu tempo de perman�ncia em -1
                }
            }
        }
    }
    if(guiche_st!=NULL){ //SE HOUVER ELEMENTO NA FILA DE SOCIO
        for(int i=0;i<guiche_st;i++){
            if(tamanho_fila(guiche_n[i])!=0){ //SE HOUVER ELEMENTO NA FILA
                saida=primeiro_elemento(guiche_socio[i]); //Sa�da recebe o tempo de perman�ncia
                if(saida==1){ //SE A QUANTIDADE DE TEMPO � 1
                    DEQUEUE(guiche_socio[i]);//Se o tempo for um, a pessoa j� � retirada
                }else{
                    saida=saida-1;//DECREMENTA A POSICAO
                    altera_inicio(guiche_socio[i],saida);//Sen�o, altera o primeiro elemento da fila, mudando seu tempo de perman�ncia em -1
                }
            }
        }
    }
}

void media_fila(TFila<int>guiche_n[], TFila<int>guiche_socio[], int guiche_normal,int guiche_st,float mediaS[], float mediaN[]){
 for(int i=0; i<guiche_normal;i++){
        mediaN[i] = mediaN[i] + tamanho_fila(guiche_n[i]); //Media = media atual + tamanho atual da fila
    }
    for (int i=0;i<guiche_st;i++){
        mediaS[i] = mediaS[i] + tamanho_fila(guiche_socio[i]);

    }

}
int main(){
    setlocale(LC_ALL,"portuguese");
    int guiche_st, guiche_normal, pessoas, pessoa_tempo, tempo;
    bool sair = true; // A vari�vel sair come�a em 1, significando que o programa ser� executado

while(sair != 0){ //Enquanto n�o for digitado 0, o programa executa
      system("cls"); //Limpa a tela para a pr�xima execu��o
    //Entrada de dados
    cout<<"Digite o numero de guiches socio torcedor: ";
    cin>>guiche_st;
    cout<<"Digite o numero de guiches normais: ";
    cin>>guiche_normal;
    while(guiche_normal <=0){//Garanta que haja pelo menos um guiche normal
         cout<<endl;
         cout<<"� necess�rio ter pelo menos um guiche normal";
         cout<<endl;
         cout<<"Digite o numero de guiches normais: ";
         cin>>guiche_normal;
    }
    cout<<"Digite quantas pessoas estao aguardando na fila: ";
    cin>>pessoas;
    cout<<"Digite quantas pessoas procuram o guiche a cada unidade de tempo: ";
    cin>>pessoa_tempo;
    cout<<"Digite o tempo de simulacao: ";
    cin>>tempo;

    //Declara��o de vari�veis vetores
    TFila<int>*guiche_socio = new TFila<int>[guiche_st];
    TFila<int>*guiche_n = new TFila<int>[guiche_normal];
    TElementoF<int>*percorre = new TElementoF<int>;
    Pessoa *pessoa = new Pessoa[pessoas];
    float *mediaS = new float[guiche_st];
    float*mediaN = new float[guiche_normal];
    int contadorS=0, contadorS_dois=0, contadorN=0,contadorN_dois=0,contadorN_tres=0, pessoaN =0, pessoaS=0; // Auxiliares de contador de pessoas



    for(int i=0; i<guiche_normal;i++){ //Inicia as m�dias em 0
        mediaN[i] = 0;
    }


    for(int i=0; i<guiche_st;i++){//Inicia as m�dias em 0
        mediaS[i] = 0;
    }

    filas(guiche_n,guiche_socio, guiche_st,guiche_normal);//Inicializa as filas

    inserir_fila(guiche_n,guiche_socio,pessoas,guiche_normal,guiche_st,pessoa,pessoaN,pessoaS);//Insere a primeira "leva" de pessoas na fila
    contador_pessoas(pessoa, pessoas, contadorS,contadorS_dois,contadorN,contadorN_dois,contadorN_tres); //Conta quantas pessoas foram adicionadas

    //SIMULA��O
    system("cls");

int tempo_aux=0;

    while(tempo_aux<tempo){ //Enquanto estiver dentro do n�mero de simula��es desejadas
        //impressao normal
        for(int i=0; i<guiche_normal;i++){
            percorre = guiche_n[i].inicio; //Percorre recebe o in�cio da fila a fim de imprimi-la
            cout<<endl;
            cout<<"Guiche normal "<<i<<":";
            for(int j=0; j<tamanho_fila(guiche_n[i]);j++){
                while(percorre !=NULL){
                    cout<<" |"<<percorre->elemento<<"| "; //Imprime o primeiro elemento
                    percorre = percorre->proximo;//Vai para o pr�ximo
                }

            }
            cout<<" (Pessoas na fila: "<<tamanho_fila(guiche_n[i])<<")";//Imprime a quantidade de pessoas na fila
            cout<<endl;
            cout<<endl;
        }
        //impressao socio
        for(int i=0; i<guiche_st;i++){
            percorre = guiche_socio[i].inicio;
            cout<<"Guiche socio torcedor "<<i<<": ";
            for(int j=0; j<tamanho_fila(guiche_socio[i]);j++){
                while(percorre!=NULL){
                    cout<<" |"<<percorre->elemento<<"| ";
                    percorre = percorre->proximo;
                }
            }

           cout<<" (Pessoas na fila: "<<tamanho_fila(guiche_socio[i])<<")";//Imprime a quantidade de pessoas na fila
            cout<<endl;
            cout<<endl;
        }

    media_fila(guiche_n,guiche_socio,guiche_normal,guiche_st,mediaS, mediaN); //Chama o c�lculo da m�dia
    atendimento(guiche_n,guiche_socio,guiche_normal,guiche_st); //Chama a fun��o de atendimento
    inserir_fila(guiche_n,guiche_socio,pessoa_tempo,guiche_normal,guiche_st,pessoa,pessoaN,pessoaS); //Ap�s o primeiro tempo, insere novas pessoas na fila


    tempo_aux++; //Aumenta o tempo em +1 at� chegar no tempo desejado de simula��o

    getch();
    system("cls");
    }

    for(int i =0; i<guiche_st;i++){ //Faz a divis�o da m�dia pelo tempo de execu��o
        mediaS[i] = (mediaS[i]/tempo);
    }
      for(int i =0; i<guiche_normal;i++){
        mediaN[i] = (mediaN[i]/tempo);
    }

    cout<<"Media de pessoas esperando por fila de socio torcedor: "<<endl;
    for(int i=0; i<guiche_st;i++){
        cout<<"Media de pessoas esperando na fila por tempo guiche s�cio "<<i<<" :"<<mediaS[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Media de pessoas esperando por fila normal: "<<endl;
     for(int i=0; i<guiche_normal;i++){
        cout<<"Media de pessoas esperando na fila por tempo guiche normal "<<i<<" :"<<mediaN[i]<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<"Socio-torcedores de 1 tempo de permanencia na fila inicial: "<<contadorS;
    cout<<endl;
    cout<<"Socio-torcedores de 2 tempos de permanencia na fila inicial: "<<contadorS_dois;
    cout<<endl;
    cout<<"torcedores normais de 1 tempo de permanecia na fila inicial: "<<contadorN;
    cout<<endl;
    cout<<"torcedores normais de 2 tempos de permanencia na fila inicial: "<<contadorN_dois;
    cout<<endl;
    cout<<"torcedores normais de 3 tempos de permanencia na fila inicial: "<<contadorN_tres;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Deseja executar novamente o programa? 1- SIM  0- NAO"<<endl;
    cin>>sair;
}
    return 0;

}

