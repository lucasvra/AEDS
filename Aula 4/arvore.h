#ifndef ARVORE_H
#define ARVORE_H

typedef struct no
{
    int dado;
    struct no* esq;
    struct no* dir;
} No;

typedef No* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* arvore);
int insere_arvore(Arvore* arvore, int valor);
int remove_arvore(Arvore* arvore, int valor);
int consulta_arvore(Arvore* arvore, int valor);
int altura_arvore(Arvore* arvore);
int arvore_vazia(Arvore* arvore);


#endif