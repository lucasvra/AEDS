#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"lista.h"
#include"arvore.h"

Arvore* cria_arvore()
{
    Arvore* raiz = malloc(sizeof(Arvore));
    if(raiz != NULL) *raiz = NULL;
    return raiz;
}

void libera_no(No* no)
{
    if(no == NULL) return;
    libera_no(no->esq);
    libera_no(no->dir);
    libera_lista(no->dado.consultas);
    free(no);
    no = NULL;
}

void libera_arvore(Arvore* arvore)
{
    if(arvore == NULL) return;
    libera_no((*arvore));
    free(arvore);
}

No* remove_no(No* no)
{
    No *n1, *n2;
    if(no->esq == NULL)
    {
        n2 = no->dir;
        libera_lista(no->dado.consultas);
        free(no);
        return n2;
    }
    n1 = no;
    n2 = no->esq;
    while (n2->dir != NULL)
    {
        n1 = n2;
        n2 = n2->dir;
    }
    if(n1 != no)
    {
        n1->dir = n2->esq;
        n2->esq = no->esq;
    }
    n2->dir = no->dir;
    libera_lista(no->dado.consultas);
    free(no);
    return n2;
}

int arvore_vazia(Arvore* arvore)
{
    if(arvore == NULL) return 1;
    if(*arvore == NULL) return 1;
    return 0;
}

int busca_paciente(Arvore* arvore, char* valor)
{
    if(arvore_vazia(arvore)) return 0;
    No* atual = *arvore;

    while (atual != NULL)
    {
        if(strcmp(valor, atual->dado.nome) == 0)
        {
            mostra_consultas(atual->dado.consultas);
            return 1;
        }
        if(strcmp(valor, atual->dado.nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }
    return 0;    
}

int busca_data(Arvore* arvore, Data data)
{
    if(arvore_vazia(arvore)) return 0;
    No* atual = *arvore;

    if(contem_data(atual->dado.consultas, data))
    {
        printf("%s\n", atual->dado.nome);
        return busca_data(&(atual->dir), data) || busca_data(&(atual->esq), data) || 1;  
    }
    return busca_data(&(atual->dir), data) || busca_data(&(atual->esq), data);

}

int insere_consulta(Arvore* arvore, Consulta consulta, char* nome)
{
    if(arvore == NULL) return 1;
    No* novo = malloc(sizeof(No));
    if(novo == NULL) return 1;

    Prontuario prontuario;
    prontuario.nome = nome;
    prontuario.consultas = cria_lista();
    insere_lista(prontuario.consultas, consulta);

    novo->dado = prontuario;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*arvore == NULL)
    {
        *arvore = novo;
        return 0;
    }

    No* atual = *arvore;
    No* pai = NULL;

    while(atual != NULL)
    {
        pai = atual;
        if(strcmp(nome, atual->dado.nome) == 0)
        {
            libera_lista(novo->dado.consultas);
            free(novo);

            insere_lista(atual->dado.consultas, consulta);

            return 1;
        }

        if(strcmp(nome, atual->dado.nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }

    if(strcmp(nome, pai->dado.nome) > 0) pai->dir = novo;
    else pai->esq = novo;
    return 0;
}

int remove_prontuario(Arvore* arvore, char* nome)
{
    if(arvore == NULL) return 0;
    No *pai = NULL, *atual = *arvore;

    while (atual != NULL)
    {
        if(strcmp(nome, atual->dado.nome) == 0)
        {
            if(atual == *arvore) *arvore = remove_no(atual);
            else
            {
                if(pai->dir == atual) pai->dir = remove_no(atual);
                else pai->esq = remove_no(atual);
            }
            return 1;
        }
        pai = atual;
        if(strcmp(nome, atual->dado.nome) > 0) atual = atual->dir;
        else atual = atual->esq;
    }
    return 0;
}