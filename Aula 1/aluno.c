#include"aluno.h"
#include<stdio.h>

void CriaAluno(Aluno* aluno, char* nome, int matricula, int idade)
{
    aluno->idade = idade;
    aluno->matricula = matricula;
    aluno->nome = nome;
}

char* GetNome(Aluno* aluno)
{
    return aluno->nome;
}
int GetMatricula(Aluno* aluno)
{
    return aluno->matricula;
}
int GetIdade(Aluno* aluno)
{
    return aluno->idade;
}

void SetNome(Aluno* aluno, char* nome)
{
    aluno->nome = nome;
}
void SetMatricula(Aluno* aluno, int matricula)
{
    aluno->matricula = matricula;
}
void SetIdade(Aluno* aluno, int idade)
{
    aluno->idade = idade;
}

void PrintAluno(Aluno* aluno)
{
    printf("O aluno %s tem matricula %d e %d anos\n", aluno->nome, aluno->matricula, aluno->idade);
}