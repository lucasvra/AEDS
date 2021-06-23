#ifndef FILA_H
#define FILA_H

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} elemento;

typedef struct fila
{
    elemento* inicio;
    elemento *fim;
    int qtd;
} Fila;


Fila* cria_fila();
void libera_fila(Fila* fila);
int consulta_fila(Fila* fila, int* valor);
int insere_fila(Fila* fila, int valor);
int remove_fila(Fila* fila);
int fila_vazia(Fila* fila);
int tamanho_fila(Fila* fila);

#endif