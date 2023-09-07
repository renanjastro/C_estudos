#ifndef MODEL_H
#define MODEL_H
#include "includes.h"
#include "obterdados.h"

typedef struct p {
    char nome[100];
    int idade;    
    struct p *prox;
    struct p *ant;
} Pessoa;


//definicoes
Pessoa* CadastrarPessoa();
void ImprimirPessoa(Pessoa *pes);

//implementacoes
Pessoa* CadastrarPessoa()
{
    Pessoa* p; 
    p = (Pessoa*) malloc(sizeof(Pessoa));           
    LerTexto("Digite o nome:",p->nome);
    p->idade = LerInteiro("Digite a idade:");                
    return p;
}

void ImprimirPessoa(Pessoa* pes)
{
    printf("\nNome:%s Idade:%d",pes->nome,pes->idade);
}

#endif
