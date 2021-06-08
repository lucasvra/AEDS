#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno
{
    char* nome;
    int matricula;
    int idade;
} Aluno;

void CriaAluno(Aluno* aluno, char* nome, int matricula, int idade);

char* GetNome(Aluno* aluno);
int GetMatricula(Aluno* aluno);
int GetIdade(Aluno* aluno);

void SetNome(Aluno* aluno, char* nome);
void SetMatricula(Aluno* aluno, int matricula);
void SetIdade(Aluno* aluno, int idade);

void PrintAluno(Aluno* aluno);

#endif