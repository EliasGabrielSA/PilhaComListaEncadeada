#include <stdio.h>
#include <stdlib.h>
#include "pilha_le.h"

void inicializa(Pilha *p) {
    p->topo = NULL;
    p->tam = 0;
}

Pilha *criaPilha(){
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    if(novo != NULL) {
        inicializa(novo);
        return novo;
    }
    return NULL;
}

No *criaNovoNo(int info) {
    No *novo = (No*) malloc(sizeof(No));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}

short int vazia(Pilha *p) {
    return (p->topo == NULL);
}

void empilha(Pilha *p, int info) {
    No *novo = criaNovoNo(info);
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

int desempilha(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *aux = p->topo;
    int info = aux->info;
    p->topo = aux->prox;
    free(aux);
    p->tam--;
    return info;
}

int tamanho(Pilha *p) {
    return p->tam;
}

void imprime(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    No *aux = p->topo;
    while (aux != NULL) {
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

void libera(Pilha *p) {
    No *aux = p->topo;
    while (aux != NULL) {
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(p);
}