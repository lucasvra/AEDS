#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

int main()
{
    Arvore* arv = cria_arvore();

    insere_arvore(arv, 50);
    insere_arvore(arv, 10);
    insere_arvore(arv, 100);

    printf("%d\n", consulta_arvore(arv, 100));

    remove_arvore(arv, 100);

    printf("%d\n", consulta_arvore(arv, 100));
    printf("%d\n", consulta_arvore(arv, 5));

    libera_arvore(arv);

    return 0;
}
