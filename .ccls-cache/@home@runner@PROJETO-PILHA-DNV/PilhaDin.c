#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento{
    char url[100];
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, char *url){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    strcpy(url, (*pi)->url);
    return 1;
}

int insere_Pilha(Pilha* pi, char *url){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    strcpy(no->url, url);
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi, Pilha *aux){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    *aux = no;
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("https://%s\n",no->url);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

void imprimir_arquivo() {
  FILE *arq = fopen("historico.txt", "r+");
  if (arq == NULL) {
    printf("ERRO NA ABERTURA DO ARQUIVO");
  }

  char n[100];

  while (fread(&n, 100 * sizeof(char), 1, arq)) {
    printf("\nhttps://%s\n", n);
    printf("======================================");
  }

  fclose(arq);
}

void navegacao_privada() {
  char link[100];

  printf("\n[!] VOCE ESTA USANDO UMA ABA ANONIMA PARA FAZER ESTA NAVEGACAO [!]\n");
  printf("\n[!]----- APOS FECHAR ESTA ABA SEU HISTORICO NAO FICARA SALVO -----[!]\n");

  printf("\nhttps://");
  scanf(" %[^\n]", link);
}

void imprime_topo(Pilha *pi){
  if(pi == NULL)
    return;
  Elem* no = *pi;
  printf("-------------------------------\n");
  printf("PAGINA ATUAL..: https://%s\n",no->url);
  printf("-------------------------------\n");
}

int menu(){
  
  int escolha;
  
  printf("\n==========MENU==========\n");
  printf("[1] PESQUISAR\n");
  printf("[2] VOLTAR\n");
  printf("[3] AVANÇAR\n");
  printf("[4] MOSTRAR HISTORICO ATUAL\n");
  printf("[5] MOSTRAR HISTORICO TOTAL\n");
  printf("[6] NAVEGAR ANONIMAMENTE\n");
  printf("[0] SAIR\n");
  scanf("%d", &escolha);

  return escolha;
}