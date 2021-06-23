#ifndef PILHA_H
#define PILHA_H

typedef struct elemento
{
    int dado;
    struct elemento* proximo;
} elemento;

typedef elemento* Pilha;

Pilha* cria_pilha();
void libera_pilha(Pilha* pilha);
int acessa_topo(Pilha* pilha, int* valor);
int insere_pilha(Pilha* pilha, int valor);
int remove_pilha(Pilha* pilha);
int tamanho_pilha(Pilha* pilha);
int pilha_vazia(Pilha* pilha);

#endif