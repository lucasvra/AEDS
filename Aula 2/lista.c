#include"lista.h"
#include<stdlib.h>
#include<stdio.h>

Lista* cria_lista()
{
    Lista* lista = malloc(sizeof(Lista));
    if(lista != NULL) *lista = NULL;

    return lista;
}

void libera_lista(Lista* lista)
{
    if(lista == NULL) return;

    elemento* aux;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
    free(lista);
}

int head(Lista* lista)
{
    if(lista == NULL || *lista == NULL) exit(1);

    return (*lista)->dado;
}

Lista* tail(Lista* lista)
{
    if(lista == NULL || *lista == NULL) exit(1);
    Lista* tail = malloc(sizeof(Lista));
    *tail = (*lista)->proximo;
    return tail;
}

void insere_lista_inicio(Lista* lista, int valor)
{
    if(lista == NULL) exit(1);

    elemento* elem = malloc(sizeof(elemento));
    if(elem == NULL) exit(1);

    elem->dado = valor;
    elem->proximo = *lista;
    *lista = elem;
}

void insere_lista_final(Lista* lista, int valor)
{
    if(lista == NULL) exit(1);
    elemento* elem = malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = NULL;

    if(*lista == NULL)
    {
        *lista = elem;
    }
    else
    {
        elemento* aux = *lista;
        while (aux->proximo != NULL) aux = aux->proximo;
        
        aux->proximo = elem;
    }
}

int lista_vazia(Lista* lista)
{
    return (lista == NULL || *lista == NULL) ? 1 : 0;
}

int tamanho_lista(Lista* lista)
{
    if(lista_vazia(lista)) return 0;
    int tam = 0;
    elemento* elem = *lista;
    while (elem != NULL)
    {
        tam++;
        elem = elem->proximo;
    }

    return tam;    
}

void mostra_lista(Lista* lista)
{
    if(lista_vazia(lista)) return;

    elemento* elem = *lista;
    int posicao = 0;

    while (elem != NULL)
    {
        printf("[%d]: %d\n", posicao, elem->dado);
        elem = elem->proximo;
        posicao++;
    }
}

int busca_posicao(Lista* lista, int posicao)
{
    if(lista_vazia(lista)) exit(1);
    if(posicao >= tamanho_lista(lista)) exit(1);

    elemento* elem = *lista;
    while (posicao > 0)
    {
        elem = elem->proximo;
        posicao--;
    }

    return elem->dado;    
}

void remove_lista_inicio(Lista* lista)
{
    if(lista_vazia(lista)) return;
    elemento* elem = *lista;
    *lista = (*lista)->proximo;
    free(elem);
}

void remove_lista_final(Lista* lista)
{
    if(lista_vazia(lista)) return;
    elemento *anterior, *elem = *lista;
    while (elem->proximo != NULL)
    {
        anterior = elem;
        elem = elem->proximo;
    }

    // a lista só tem um elemento
    if(elem == *lista) *lista = elem->proximo;
    else // a lista tem mais de um elemento
    {
        anterior->proximo = elem->proximo;
        free(elem);
    }
    
}