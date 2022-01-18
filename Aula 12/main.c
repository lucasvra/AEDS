#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

const int n = 10000;
float *s, *v;

const int C = 10*n;

void Vizinhanca(int* solC, int* solV)
{
    for(int i = 0; i < n; i++)
        solV[i] = solC[i];

    int ind = rand()%n;
    if(solV[ind] == 0) solV[ind] = 1;
    else solV[ind] = 0;
}

float FuncaoObjetivo(int* sol)
{
    float val = 0, peso = 0;
    for(int i = 0; i < n; i++)
    {
        val += v[i] * sol[i];
        peso += s[i] * sol[i];
    }

    return peso > C ? -1000000 : val;
}

float Peso(int* sol)
{
    int peso = 0;
    for(int i = 0; i < n; i++)
        peso += s[i] * sol[i];
    return peso;
}

void Recozimento(int* s0)
{
    int* solC = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) solC[i] = s0[i];


    int* solV = malloc(n*sizeof(int));
    float T = 500; // Temperatura

    int it = 0;

    while (it < 10*n)
    {
        Vizinhanca(solC, solV);
        
        float valC = FuncaoObjetivo(solC);
        float valV = FuncaoObjetivo(solV);

        float deltaVal = valV - valC;

        if(deltaVal > 0 || exp(deltaVal/T) > ((rand()/(float)RAND_MAX)))
        {
            for(int i = 0; i < n; i++) solC[i] = solV[i];
        }

        T = 0.9 * T;
        it++;
    }

    for(int i = 0; i < n; i++) s0[i] = solC[i];
    free(solC);
    free(solV);
}



void main()
{
    srand(100);
    //srand(time(0));
    s = malloc(n*sizeof(float));
    v = malloc(n*sizeof(float));
    int* sol = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        s[i] = (int)(50 * ((rand()/(float)RAND_MAX)));
        v[i] = (int)(100 * ((rand()/(float)RAND_MAX)));
        sol[i] = 0;

        //printf("%d elemento -> peso = %f, valor = %f\n", i, s[i], v[i]);
    }

    Recozimento(sol);

    //printf("solucao: ");
    //for(int i = 0; i < n; i++) printf("%i, ", sol[i]);
    printf("\nvalor: %f | peso: %f de %d\n", FuncaoObjetivo(sol), Peso(sol), C);

    free(s);
    free(v);
}