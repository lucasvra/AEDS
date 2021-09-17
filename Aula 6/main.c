#include<stdio.h>
#include<stdlib.h>
#include"lista.h"
#include"grafo.h"

void mostra_array(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d] %d\n", i, arr[i]);
}

int main()
{
    int nv = 6;
    Grafo* g = cria_grafo(nv);

    for(int i = 0; i < 5; i++)
        insere_aresta(g, i, (i+1)%5, 10);

    insere_aresta(g, 1, 5, 1);
    insere_aresta(g, 5, 3, 1);

    int* dfs = busca_em_profundidade(g, 5);
    mostra_array(dfs, nv);

    int* bfs = busca_em_largura(g, 0);
    mostra_array(bfs, nv);
    
    int* caminho = menor_caminho_dijkstra(g, 0);
    mostra_array(caminho, nv);

    libera_grafo(g);
    free(dfs);
    free(bfs);
    free(caminho);
}

