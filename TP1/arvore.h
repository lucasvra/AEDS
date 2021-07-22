#ifndef ARVORE_H
#define ARVORE_H

typedef struct no
{
    Prontuario dado;
    struct no* esq;
    struct no* dir;
} No;

typedef No* Arvore;

Arvore* cria_arvore();
void libera_arvore(Arvore* arvore);
int arvore_vazia(Arvore* arvore);

int busca_paciente(Arvore* arvore, char* valor);
int busca_data(Arvore* arvore, Data data);
int insere_consulta(Arvore* arvore, Consulta consulta, char* nome);
int remove_prontuario(Arvore* arvore, char* nome);
#endif