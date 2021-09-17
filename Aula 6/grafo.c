#include<stdlib.h>
#include<stdio.h>
#include"lista.h"
#include"fila.h"
#include"grafo.h"

Grafo* cria_grafo(int num_vertices)
{
    Grafo* grafo = malloc(sizeof(Grafo));
    grafo->vertices = num_vertices;
    grafo->arestas = cria_lista();
    return grafo;
}

void libera_grafo(Grafo* grafo)
{
    libera_lista(grafo->arestas);
    free(grafo);
}
int insere_aresta(Grafo* grafo, int origem, int destino, int peso)
{
    aresta a;
    a.origem = origem;
    a.destino = destino;
    a.peso = peso;

    return insere_lista_final(grafo->arestas, a);
}

Lista* adjacencia(Grafo* grafo, int vertice)
{
    Lista* lista = grafo->arestas;
    Lista* resultado = cria_lista();

    if(lista_vazia(lista)) return NULL;

    elemento* elem = *lista;

    
    while (elem != NULL)
    {
        if(elem->dado.origem == vertice)
            insere_lista_final(resultado, elem->dado);

        elem = elem->proximo;
    }

    return resultado;
}

int* DFS(Grafo* grafo, int origem, int* visitado)
{
    Lista* adj = adjacencia(grafo, origem);
    visitado[origem] = 1;

    elemento* elem = *adj;

    while (elem != NULL)
    {
        if(visitado[elem->dado.destino] == 0) 
            DFS(grafo, elem->dado.destino, visitado);

        elem = elem->proximo;
    }

    libera_lista(adj);
    return visitado;
}

int* busca_em_profundidade(Grafo* grafo, int origem)
{
    int* visitado = malloc(grafo->vertices*sizeof(int));
    for(int i = 0; i < grafo->vertices; i++) visitado[i] = 0;
    
    return DFS(grafo, origem, visitado);
}

int* busca_em_largura(Grafo* grafo, int origem)
{
    int* visitado = malloc(sizeof(int)* grafo->vertices);
    for(int i = 0; i < grafo->vertices; i++) visitado[i] = 0;

    Fila* F = cria_fila();
    insere_fila(F, origem);

    while (!fila_vazia(F))
    {
        int v = F->inicio->dado;
        remove_fila(F);
        if(visitado[v]) continue;

        visitado[v] = 1;

        Lista* adj = adjacencia(grafo, v);

        elemento* elem = *adj;
        while (elem != NULL)
        {
            insere_fila(F, elem->dado.destino);
            elem = elem->proximo;
        }

        libera_lista(adj);
    }
    
    libera_fila(F);
    return visitado;
}

int* menor_caminho_dijkstra(Grafo* grafo, int origem)
{
    float* dist = malloc(sizeof(float)*grafo->vertices);
    int* anterior = malloc(sizeof(int)*grafo->vertices);
    int* visitado = malloc(sizeof(int)*grafo->vertices);
    int num_visitados = 0;

    for(int i = 0; i < grafo->vertices; i++)
    {
        dist[i] = 999999.0;
        anterior[i] = -1;
        visitado[i] = 0;
    }
    
    dist[origem] = 0;

    while (num_visitados < grafo->vertices)
    {
        int u = 0;
        for(int k = 1; k < grafo->vertices; k++)
        {
            if(visitado[u]) u = k;
            else break;
        }

        for(int k = 1; k < grafo->vertices; k++)
        {
            if(dist[k] < dist[u] && !visitado[k]) u = k;
        }

        printf("menor: %d\n", u);

        visitado[u] = 1;
        num_visitados++;

        Lista* adj = adjacencia(grafo, u);

        elemento* elem = *adj;

        while (elem != NULL)
        {
            int v = elem->dado.destino;
            int w = elem->dado.peso;
            float alt = dist[u] + w;
            printf("\taresta: %d -(%d)-> %d\n", u, w, v);
            if(alt < dist[v])
            {
                dist[v] = alt;
                anterior[v] = u;
            }

            elem = elem->proximo;
        }
        libera_lista(adj);
    }
    
    free(visitado);
    free(dist);

    return anterior;
}