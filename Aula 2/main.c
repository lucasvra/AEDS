#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int xxxxxx_xxxxx(Lista* lista, int valor)
{
    int num = 0;
    if(lista_vazia(lista)) return num;
    elemento *anterior = NULL, *elem = *lista;
    
    while (elem != NULL)
    {
        if(elem->dado == valor)
        {
            num++;
            if(anterior != NULL) anterior->proximo = elem->proximo;
            else *lista = (*lista)->proximo;

            elemento* aux = elem;
            elem = elem->proximo;
            free(aux);            
        }
        else
        {
            anterior = elem;
            elem = elem->proximo;
        }
    }

    return num;
}

int elemento_pos(Lista* lista, int n)
{
    if(lista_vazia(lista) || n < 0) exit(1);

    elemento *elem = *lista;
    while (elem != NULL && n > 0)
    {
        elem = elem->proximo;
        n--;
    }

    if(n > 0) exit(1);
    return elem->dado;
}

int main()
{
    Lista *lista = cria_lista();

    insere_lista_final(lista, 10);
    insere_lista_final(lista, 20);
    insere_lista_inicio(lista, 30);
    //mostra_lista(lista);

    xxxxxx_xxxxx(lista, 30);
    //mostra_lista(lista);


}

