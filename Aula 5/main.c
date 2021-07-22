#include<stdio.h>
#include<stdlib.h>

void printSe(int* vetor, int tam, int (*cond)(int))
{
    for(int i = 0; i < tam; i++)
    {
        if((*cond)(vetor[i])) 
            printf("valor %d\n", vetor[i]);
    }
}

int MaiorQue5(int val)
{
    return val > 5;
}

int MultiploDe3(int val)
{
    return val % 3 == 0;
}

int main()
{
    int* aux = malloc(10*sizeof(int));
    for(int i = 0; i < 10; i++) aux[i] = i;
 
    printSe(aux, 10, &MultiploDe3);

    return 0;
}


