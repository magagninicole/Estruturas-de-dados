#include "tad_arvore_expressao.h"
#include "tad_arvore_binaria.h"

int main()
{

  string expressao;
  bool sair = false;
  int escolha;

  while(!sair){
  system("cls");
  cout<<"Insira a expressao com seus operadores antes de parenteses: ";
  cin>>expressao;

  TArvore<string> arvore;
  inicializa_arvore(arvore);
  monta_arvore(expressao,arvore.raiz);
  imprime(arvore.raiz, 0,32,6,64);
  gotoxy(20,20);

  cout<<endl;
  cout<<endl;

  cout<<"Resultado: "<<executa_arvore(arvore.raiz);

  cout<<endl;
  cout<<endl;

  cout<<"Deseja entrar com outra expressao?  1- NAO 0- SIM  ";
  cin>>escolha;

  if(escolha!=0){
    sair = true;
  }
  }

    return 0;

}
