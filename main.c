#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int main(){

  char url[100];
  int escolha;
  Pilha* pi = cria_Pilha();
  Pilha *aux = cria_Pilha();

  do{
    escolha = menu();
    switch(escolha){
      case 0: //sair
        printf("\nTCHAU TCHAU!!!!!!!!!!!!!!!\n");
      break;
      case 1: //pesquisar
        system("clear");
        FILE *arq = fopen("historico.txt", "a+");
        if(arq == NULL){
          printf("NAO FOI POSSÍVEL CRIAR O ARQUIVO\n");
          exit(1);
        }
        printf("https://");
        scanf(" %[^\n]", url);
        insere_Pilha(pi, url);
        fwrite(&url, 100 * sizeof(char), 1, arq);
        fclose(arq);
      break;
      case 2: //voltar
        system("clear");
        remove_Pilha(pi, aux);
        imprime_topo(pi);
      break;
      case 3: //avançar
        system("clear");
        remove_Pilha(aux, pi);
        imprime_topo(pi);
      break;
      case 4: //historico atual
        system("clear");
        printf("\n==========HISTORICO ATUAL==========\n");
        imprime_Pilha(pi);
      break;
      case 5: //historico total
        system("clear");
        printf("\n==========HISTORICO TOTAL==========\n");
        imprimir_arquivo();
      break;
      case 6: //guia anonima
        system("clear");
        navegacao_privada();
      break;
      default:
        printf("\nOPCAO INVALIDA!!!!!!!!!!!!!!!!!!!!\n");
      break;
    }
  }while(escolha != 0);
  
  return 0;
}

