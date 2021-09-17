#ifndef FILA_H
#define FILA_H

typedef struct elementoI
{
    int dado;
    struct elementoI *proximo;
} elementoI;

typedef struct fila
{
    elementoI* inicio;
    elementoI *fim;
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