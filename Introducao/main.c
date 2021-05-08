#include<stdio.h>

struct Pessoa
{
    char* nome;
};

typedef struct Pessoa Pessoa;

int recebeInt(char* msg)
{
    int resultado = 0;
    printf(msg);
    scanf("%d", &resultado);
    return resultado;
}

void main()
{
    int x = recebeInt("Digite um número: ");
    printf("o numero e %d", x);

    Pessoa p;
    p.nome = "TESTE";

    Pessoa *lucas = malloc(sizeof(Pessoa));

    lucas->nome = "TESTE";
}



