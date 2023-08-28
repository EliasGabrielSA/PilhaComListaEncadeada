#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct pilha_le {
    No *topo;
    int tam;
} Pilha;

void inicializa(Pilha *p);
Pilha *criaPilha();
No *criaNovoNo(int info);
short int vazia(Pilha *p);
void empilha(Pilha *p, int info);
int desempilha(Pilha *p);
int tamanho(Pilha *p);
void imprime(Pilha *p);
void libera(Pilha *p);