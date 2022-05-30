#ifndef TAD_ARVORE_EXPRESSAO_H_INCLUDED
#define TAD_ARVORE_EXPRESSAO_H_INCLUDED
#include "tad_arvore_binaria.h"
#include <iostream>
#include <string>
#include<windows.h>

using namespace std;
void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void contagem_parenteses(string &expressao){ // Contagem de parenteses a fim de checar se todos os parenteses presentes na string
    //podem ser removidos
  int parenteses=0;
  if(expressao.size() <= 2){ //Se a expressão tiver menos de 3 elementos, retorna saindo da funcao
    return;
}
  for(int pos = expressao.size()-1; pos>=0; pos--){ //Decrementa a posição até achar um parenteses
    if(expressao.at(pos)==')'){
      parenteses++; //parenteses = parenteses + 1_
    }else if(expressao.at(pos)=='('){
      parenteses--; //Quando há fechamento, decrementa a o número de parenteses
   }
    if(parenteses == 0 && pos!= 0){
      return; //Quando ainda há string para percorrer, mas parenteses = 0, retorna
       //Apenas quando a variavel "parenteses" se encontra em 0 e não há mais string para percorrer,os parenteses podem ser removidos
    }else if(parenteses ==0 && pos == 0){ //Nesse caso
      expressao = expressao.substr(1, expressao.size()-2); //É criada uma substring com os valores da expressão a partir do segundo até o penúltimo
      //Removendo assim as posições dos parenteses
    }
  }
}

int prioridade(string expressao){//Separa os operadores por prioridade, a fim de escolher a raiz da árvore
  for(int pos = expressao.size()-1; pos >= 0; pos--){ //Passa pelos elementos da expressão decrementando
    if(expressao.at(pos)=='+' || expressao.at(pos)=='-'){ //A expressão "at" pega o caracter na string, se for + ou -, entra no if
      if(expressao.at(pos)=='-' && pos-1 < 0){ //Se o caracter for  "-" e i-1 for menor que zero(ou seja, estiver na primeira posição)
        break;
      }else{
        return pos; //retorna a posição de menor prioridade na expressão
      }
    }
      else if(expressao.at(pos)==')'){ //Caso encontre parênteses
      while(expressao.at(pos)!='(') {
        pos--; //Apenas decrementa até chegar ao fechamento do mesmo
      }
    }
  }
  //Caso não encontre nenhum sinal de menor prioridade em + e -, passa aos operadores de maior prioridade / e  *
for(int pos = expressao.size()-1; pos >= 0; pos--){
  if(expressao.at(pos)=='*' || expressao.at(pos)=='/'){ //Caso encontre na string "/" ou "*"
      return pos;//Retorna a posição

    }else if(expressao.at(pos)==')'){ //Checa os parenteses
      while(expressao.at(pos)!='('){
        pos--;
      }
    }
  }
  return 0; //Caso não hajam operadores na expressão
}

void monta_arvore(string expressao, node<string> *&No, int chave = 0){
  if(expressao.empty() == true){ //Se a expressão for vazia
    return;
  }
  contagem_parenteses(expressao);
  int sinal = prioridade(expressao); //Sinal recebe a posição do sinal
  string valor, esquerda, direita; //Serve para verificar se o que há na string é apenas um valor ou ainda uma expressão
  if(sinal==0){ //Se não houver operador, a string segue igual
    valor = expressao;
  } else{
    valor = string(1, expressao.at(sinal)); //Caso seja encontrado um operador, é criada uma string de uma posição para armazená-lo
  }
  insere_arvore(No,valor,sinal+chave); //Chama a inserção na árvore binária, enviando o nó e a chave que é o sinal encontrado
  if (sinal != 0) { //Se houver um sinal
    esquerda = expressao.substr(0,sinal);//Divide a string do ponto 0 até encontrar o sinal
    direita = expressao.substr(sinal+1,expressao.size());  //Divide a string, apartir do sinal, até seu fim
    monta_arvore(esquerda,No->esquerda, 0); //Chama recursivamente montar árvore, passando o nó a esquerda e a chave sendo 0
    monta_arvore(direita,No->direita, sinal+1);//Chama recursivamente, passando o nó a direita e a chave a partir da posição do sinal + 1
  }
}

double executa_arvore(node<string>* No){ //Executa a árvore recursivamente
double esquerda, direita;
  if (No == NULL) return 0; //Se o nó estiver vazio, retorna 0
  if (No->dado.at(0) >= '0' && No->dado.at(0) <= '9' || No->dado.at(0)=='-' && No->dado.size()>1) {//O desvio confere se o nó é apenas de um valor
    //sendo ele negativo ou positivo
    return std::stod(No->dado, 0); //Converte a string em variável double, para que consigamos efetuar o cálculo
  }else{ //Caso contrário
    esquerda = executa_arvore(No->esquerda); //Chama a função recursivamente mandando o nó a esquerda e a direita
    direita = executa_arvore(No->direita);

    switch(No->dado.at(0)){ //Caso o dado seja um dos sinais, realiza a operação, usando os nós a esquerda e a direita
      case '+': return esquerda+direita;
      case '-': return esquerda-direita;
      case '*': return esquerda*direita;
      case '/': return esquerda/direita;
    }
  }
}


void imprime(node<string>* No, int altura,int largura, int padding,int larguraInicial){//Impressão em grafo
    if(No== NULL){ // Se o nó estiver vazio, não imprime
        return ;
    }
    larguraInicial = larguraInicial/2; // Divide a largura inicial por 2
    gotoxy(largura,altura*2 + padding); //Calcula a posição do nó
    cout<< "|"<< No->dado << "|"; //Imprime o nó

    if(No->direita!=NULL){ //Se nó direita diferente de null
        gotoxy(3+largura,altura*2 + padding+1);
        cout<< "\\";
        imprime(No->direita, altura+1, int(largura+ larguraInicial/2),padding, larguraInicial); //Chama recursivamente

    }
    if(No->esquerda!=NULL){ //Se nó direita diferente de null
        gotoxy(-1+largura,altura*2 + padding+1);
        cout<< "/";
        imprime(No->esquerda, altura+1, int(largura-larguraInicial/2),padding, larguraInicial); //Chama recursivamente
    }


}


#endif // TAD_ARVORE_EXPRESSAO_H_INCLUDED
