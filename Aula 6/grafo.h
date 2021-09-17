#ifndef GRAFO_H
#define GRAFO_H

typedef struct Grafo{
    int vertices;
    Lista* arestas;
} Grafo;

Grafo* cria_grafo(int num_vertices);
int insere_aresta(Grafo* grafo, int origem, int destino, int peso);
void libera_grafo(Grafo* grafo);
Lista* adjacencia(Grafo* grafo, int vertice);

int* busca_em_profundidade(Grafo* grafo, int origem);
int* busca_em_largura(Grafo* grafo, int origem);
int* menor_caminho_dijkstra(Grafo* grafo, int origem);

#endif