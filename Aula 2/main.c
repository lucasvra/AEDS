#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main()
{
    Lista* lst = cria_lista();
    insere_lista_inicio(lst, 10);
    insere_lista_inicio(lst, 20);
    insere_lista_final(lst, 30);

    mostra_lista(lst);

    //remove_lista_final(lst);
    //remove_lista_inicio(lst);

    lst = tail(lst);

    printf("A lista possui %d elementos\n", tamanho_lista(lst));
    printf("O 1o elemento é %d\n", busca_posicao(lst, 0));
    mostra_lista(lst);

    libera_lista(lst);
    return 0;
}