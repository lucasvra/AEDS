#ifndef LISTA_H
#define LISTA_H

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} elemento;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* lista);

int head(Lista* lista);
Lista* tail(Lista* lista);

void insere_lista_inicio(Lista* lista, int valor);
void insere_lista_final(Lista* lista, int valor);
void remove_lista_inicio(Lista* lista);
void remove_lista_final(Lista* lista);

int lista_vazia(Lista* lista);

int tamanho_lista(Lista* lista);

void mostra_lista(Lista* lista);

int busca_posicao(Lista* lista, int posicao);



#endif