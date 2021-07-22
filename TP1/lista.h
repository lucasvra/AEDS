#ifndef LISTA_H
#define LISTA_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Consulta
{
    Data data;
    char* observacao;
} Consulta;

typedef struct elemento
{
    Consulta dado;
    struct elemento *proximo;
} elemento;

typedef elemento* Lista;

typedef struct Prontuario
{
    char* nome;
    Lista* consultas;
} Prontuario;

Lista* cria_lista();
void libera_lista(Lista* lista);

int lista_vazia(Lista* lista);
int tamanho_lista(Lista* lista);

int insere_lista(Lista* lista, Consulta valor);
void mostra_consultas(Lista* lista);
int contem_data(Lista* lista, Data data);

#endif