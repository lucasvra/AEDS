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

    elemento *aux;
    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->proximo;
        free(aux);
    }
    free(lista);
}

int lista_vazia(Lista* lista)
{
    return (lista == NULL || *lista == NULL);
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

int insere_lista(Lista* lista, Consulta valor)
{
    if(lista == NULL) return 1;
    elemento *elem = malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = NULL;

    if(*lista == NULL)
    {
        *lista = elem;
        return 0;
    }

    elemento* aux = *lista;
    while (aux->proximo != NULL) aux = aux->proximo;
    aux->proximo = elem;
    return 0;
}

void mostra_consultas(Lista* lista)
{
    if(lista_vazia(lista)) return;
    elemento* elem = *lista;
    while (elem != NULL)
    {
        printf("[%02d/%02d/%04d] %s\n", elem->dado.data.dia, elem->dado.data.mes, elem->dado.data.ano, elem->dado.observacao);
        elem = elem->proximo;
    }
}

int contem_data(Lista* lista, Data data)
{
    if(lista_vazia(lista)) return 0;
    elemento* elem = *lista;
    while (elem != NULL)
    {
        if(elem->dado.data.dia == data.dia && elem->dado.data.mes == data.mes && elem->dado.data.ano == data.ano)
            return 1;
        elem = elem->proximo;
    }
    return 0;
}