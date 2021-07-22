#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"arvore.h"

#define MAX_STR 300

void limpa_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
}

int menu()
{
    int escolha = 0;
    while (1)
    {

#ifdef _WIN32
        system("cls");
#else
        printf("\e[1;1H\e[2J");
#endif
        printf("Escolha uma das opções:\n");
        printf("\t1) Consultar Paciente\n");
        printf("\t2) Consultar Data\n");
        printf("\t3) Inserir Consulta\n");
        printf("\t4) Remover Prontuario\n");
        printf("\t5) Sair\n");
        printf("[ ]\b\b");
        
        scanf("%1d", &escolha);
        limpa_entrada();

        if(escolha > 0 && escolha < 6) return escolha;

        printf("Essa opcao nao existe, desculpe :[ \n");
    }
}

Data recebe_data()
{
    while (1)
    {
        Data data;
        printf("Digite uma data no formato DD/MM/AAAA: ");
        scanf("%2d/%2d/%4d", &data.dia, &data.mes, &data.ano);
        limpa_entrada();

        if(data.ano < 1900 
           || data.mes < 1 
           || data.mes > 12 
           || data.dia < 1 
           || data.dia > 31 
           || (data.mes == 2 && data.dia > 28) 
           || ((data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) && data.dia > 30)
          )
        {
            printf("Data inválida, tente novamente :[\n");
            continue;
        }
        return data;
    }
    
}

void consultar_paciente(Arvore* prontuarios)
{
    char paciente[MAX_STR];

    printf("Digite o nome do paciente a buscar:\n");
    fgets(paciente, MAX_STR, stdin);

    int resultado = busca_paciente(prontuarios, paciente);

    if(!resultado) printf("Nenhum registro encontrado\n");

    printf("Pressione qualquer tecla pra continuar...\n");   
    getchar(); 
}

void consultar_data(Arvore* prontuarios)
{
    Data data = recebe_data();
    int resultado = busca_data(prontuarios, data);

    if(!resultado) printf("Nenhum registro encontrado\n");

    printf("Pressione qualquer tecla pra continuar...\n");  
    getchar();  
}

void inserir_consulta(Arvore* prontuarios)
{
    Data data = recebe_data();
    char paciente[MAX_STR], obs[MAX_STR];
    
    printf("Digite o nome do paciente\n");
    fgets(paciente, MAX_STR, stdin);

    char* paciente_ptr = malloc(strlen(paciente)*sizeof(char));
    strcpy(paciente_ptr, paciente);

    printf("Digite a observacao\n");
    fgets(obs, MAX_STR, stdin);

    char* obs_ptr = malloc(strlen(obs)*sizeof(char));
    strcpy(obs_ptr, obs);

    Consulta consulta;
    consulta.data = data;
    consulta.observacao = obs_ptr;

    insere_consulta(prontuarios, consulta, paciente_ptr);

    printf("Pressione qualquer tecla pra continuar...\n");  
    getchar(); 

}

void remover_prontuario(Arvore* prontuarios)
{
    char paciente[MAX_STR];
    
    printf("Digite o nome do paciente\n");
    fgets(paciente, MAX_STR, stdin);

    char* paciente_ptr = malloc(strlen(paciente)*sizeof(char));
    strcpy(paciente_ptr, paciente);

    int resultado = remove_prontuario(prontuarios, paciente_ptr);
    
    if(resultado) printf("Paciente removido com sucesso!\n");
    else printf("Paciente não encontrado :[\n");

    printf("Pressione qualquer tecla pra continuar...\n");  
    getchar(); 
}

int main()
{
    Arvore* prontuarios = cria_arvore();
    while (1)
    {
        int escolha = menu();
        switch(escolha)
        {
            case 1:
                consultar_paciente(prontuarios);
                break;
            case 2:
                consultar_data(prontuarios);
                break;
            case 3:
                inserir_consulta(prontuarios);
                break;
            case 4:
                remover_prontuario(prontuarios);
                break;
            case 5:
                libera_arvore(prontuarios);
                return 0;
        }
    }
    
}

