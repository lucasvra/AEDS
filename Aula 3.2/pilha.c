#include<stdlib.h>
#include"pilha.h"

Pilha* cria_pilha()
{
    Pilha*pilha = malloc(sizeof(Pilha));
    if(pilha != NULL) *pilha = NULL;

    return pilha;
}

void libera_pilha(Pilha* pilha)
{
    if(pilha == NULL) return;

    elemento* aux;
    while ((*pilha) != NULL)
    {
        aux = *pilha;
        *pilha = (*pilha)->proximo;
        free(aux);
    }
    free(pilha);        
}

int acessa_topo(Pilha* pilha, int* valor)
{
    if(pilha_vazia(pilha)) return 1;
    *valor = (*pilha)->dado;
    return 0;
}

int insere_pilha(Pilha* pilha, int valor)
{
    if(pilha == NULL) return 1;
    elemento* elem = malloc(sizeof(elemento));

    if(elem == NULL) return 1;

    elem->dado = valor;
    elem->proximo = *pilha;
    *pilha = elem;
    return 0;
}

int remove_pilha(Pilha* pilha)
{
    if(pilha_vazia(pilha)) return 1;

    elemento* aux = *pilha;
    *pilha = aux->proximo;
    free(aux);
    return 0;
}

int tamanho_pilha(Pilha* pilha)
{
    if(pilha == NULL) return 0;
    int contador = 0;
    elemento* elem = *pilha;
    while (elem != NULL)
    {
        contador++;
        elem = elem->proximo;
    }
    return contador;
}

int pilha_vazia(Pilha* pilha)
{
    if(pilha == NULL) return 1;
    if(*pilha == NULL) return 1;
    return 0;
}