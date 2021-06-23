#include"fila.h"
#include<stdlib.h>

Fila* cria_fila()
{
    Fila* fila = malloc(sizeof(Fila));
    if(fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->qtd = 0;
    }

    return fila;
}

void libera_fila(Fila* fila)
{
    if(fila != NULL)
    {
        elemento* aux;
        while (fila->inicio != NULL)
        {
            aux = fila->inicio;
            fila->inicio = fila->inicio->proximo;
            free(aux);
        }
        free(fila);
    }
}

int consulta_fila(Fila* fila, int* valor)
{
    if(fila_vazia(fila)) return 1;

    *valor = fila->inicio->dado;
    return 0;
}

int insere_fila(Fila* fila, int valor)
{
    if(fila == NULL) return 1;
    elemento* elem = malloc(sizeof(elemento));
    elem->dado = valor;
    elem->proximo = NULL;

    if(fila->fim == NULL) fila->inicio = elem;
    else fila->fim->proximo = elem;
    fila->fim = elem;
    fila->qtd++;

    return 0;
}

int remove_fila(Fila* fila)
{
    if(fila_vazia(fila)) return 1;
    elemento *aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
    
    if(fila->inicio == NULL) fila->fim = NULL;

    fila->qtd--;
    return 0;
}

int fila_vazia(Fila* fila)
{
    if(fila == NULL) return 1;
    if(fila->qtd == 0) return 1;
    return 0;
}

int tamanho_fila(Fila* fila)
{
    if(fila == NULL) return 0;
    return fila->qtd;
}