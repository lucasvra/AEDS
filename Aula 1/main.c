#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"

int main()
{
    int n = 10;
    Aluno *alunos = malloc(n*sizeof(Aluno));

    for(int i = 0; i < n; i++)
    {
        CriaAluno(&(alunos[i]), "", 2021000000 + i, 15 + i);
    }

    PrintAluno(&(alunos[3]));

    return 0;
}