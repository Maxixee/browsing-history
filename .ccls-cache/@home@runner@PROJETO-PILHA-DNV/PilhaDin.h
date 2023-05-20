//Arquivo PilhaDin.h


typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, char *url);
int insere_Pilha(Pilha* pi, char *url);
int remove_Pilha(Pilha* pi, Pilha *aux);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);
void imprimir_arquivo();
void navegacao_privada();
void imprime_topo(Pilha*);
int menu();
