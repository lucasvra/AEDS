#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main()
{
    Fila* fila = cria_fila();

    for(int i = 0; i < 10; i++)
    {
        insere_fila(fila, 2*i);
    }

    int valor = 0;
    while (tamanho_fila(fila) > 0)
    {
        consulta_fila(fila, &valor);
        printf("valor: %d\n", valor);
        remove_fila(fila);
    }
    
    return 0;
}