#include<stdio.h>

void main()
{
    int x = recebeInt("Digite um número: ");
    printf("o numero e %d", x);
}

int recebeInt(char* msg)
{
    int resultado = 0;
    printf(msg);
    scanf("%d", &resultado);
    return resultado;
}