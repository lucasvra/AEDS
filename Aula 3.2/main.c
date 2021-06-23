#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main()
{
    Pilha* pilha = cria_pilha();

    for(int i = 0; i < 10; i++)
    {
        insere_pilha(pilha, 2*i);
    }

    int valor = 0;
    while (tamanho_pilha(pilha) > 0)
    {
        acessa_topo(pilha, &valor);
        printf("valor: %d\n",valor);
        remove_pilha(pilha);
    }
    
    return 0;
}

