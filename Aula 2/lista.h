#ifndef LISTA_H
#define LISTA_H

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} elemento;

typedef elemento* Lista;

typedef struct Lista2
{
    elemento* inicio;
} Lista2;

Lista* cria_lista();
void libera_lista(Lista* lista);

int lista_vazia(Lista* lista);
int tamanho_lista(Lista* lista);

int insere_lista_inicio(Lista* lista, int valor);
int insere_lista_final(Lista* lista, int valor);
int remove_lista_inicio(Lista* lista);
int remove_lista_final(Lista* lista);

void mostra_lista(Lista* lista);

#endif