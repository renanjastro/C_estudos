#ifndef OBTERDADOS_H
#define OBTERDADOS_H
#include "includes.h"
 
 //definicoes
int LerInteiro(char *mensagem);
float LerFloat(char *mensagem);
void LerTexto(char *mensagem, char *outValor);
bool QuestionaUsuario(char *mensagem);
int Randomiza(int inicio, int fim);

//implementacoes
int LerInteiro(char *mensagem)
{
    int valor;
    printf("%s",mensagem);
    scanf("%d", &valor);
    return valor;
}

float LerFloat(char *mensagem)
{
    float valor=0;
    printf("%s",mensagem);
    scanf("%f", &valor);
    return valor;
}

void LerTexto(char *mensagem, char *outValor)
{      
    char s[256];      
    printf("%s",mensagem);
    scanf("%s",s);    
    strcpy(outValor,s);   
}

bool QuestionaUsuario(char *mensagem)
{
    char opcao = 'S';
    printf("%s [S]Sim\n",mensagem);
    scanf("%s",&opcao);
    return (opcao =='S' || opcao == 's');
}

int Randomiza(int inicio, int fim)
{
    int r = 0;    
    r = rand();
    r = r%(fim+inicio+1);
    r = r+inicio;
    return r;
}

#endif

