#include<stdio.h>

// AEDs - Algoritmos e Estruturas de Dados
// Exercícios
// 1) Encontre a soma dos múltiplos de 3 ou 5 menores que 1000. (Resposta: 233.168)
// 2) Encontre a soma dos números pares da sequência de fibonnaci menores ou iguais a 4 milhões. (Resposta: 4.613.732)
// 3) Escreva um programa que imprime Fizz se o número é múltiplo de 3, Buzz se o número é múltiplo de 5 e 
//    FizzBuzz caso seja multiplo de 3 e 5.

int main()
{
    Questao1();
    Questao2();
    Questao3();

    return 0;
}

void Questao1()
{
    int acumulador = 0, i;
    for(i = 0; i < 1000; i++)
    {
        if(i % 3 == 0 || i % 5 == 0) acumulador += i; 
    }

    printf("Questao 1: %d\n", acumulador);
}

void Questao2()
{
    // fib(n) = fib(n-1) + fib(n-2)
    int n1 = 1, n2 = 0;
    int acumulador = 0;

    while(n1 < 4000000)
    {
        if(n1 % 2 == 0) acumulador += n1;

        int aux = n1;
        n1 += n2;
        n2 = aux;
    }

    printf("Questao 2: %d\n", acumulador);
}

void Questao3()
{
    for(int i = 0; i < 100; i++)
    {
        if(i % 3 == 0) printf("Fizz");
        if(i % 5 == 0) printf("Buzz");
        if(i % 3 != 0 && i % 5 != 0) printf("%d", i);

        printf("\n");
    }
}