#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main()
{
    Lista *lista = cria_lista();

    insere_lista_final(lista, 10);
    mostra_lista(lista);

    insere_lista_final(lista, 20);
    insere_lista_inicio(lista, 30);
    mostra_lista(lista);

    remove_lista_final(lista);
    mostra_lista(lista);
}