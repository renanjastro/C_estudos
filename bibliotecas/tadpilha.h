#ifndef TADPILHA_H
#define TADPILHA_H
#include "includes.h"
#include "model.h"

//A PILHA é uma forma de organizar as informações empilhadas
//utiliza-se o conceito de (LIFO) last in, first out
#define MAXPILHA 10
Pessoa *pilha[MAXPILHA];         //Vetor de ponteiros com a quantidade de elementos que necessitamos.
int top=0;                       //top armazena o topo de uma pilha

//definicoes
void Push(Pessoa* item);
Pessoa* Pop();
bool PilhaCheia();
bool PilhaVazia();

//implementacoes
void Push(Pessoa* item)
{
    if(top>=MAXPILHA)
    {
        printf("pilha cheia");
        return;
    }
    pilha[top]=item;
    top++;
}

Pessoa* Pop()
{
    if(top==0)
    {
        printf("pilha vazia");
        return NULL;   
    }
    top--;
    return pilha[top];
}

bool PilhaCheia()
{
    return (top>=MAXPILHA);
}

bool PilhaVazia()
{
    return(top==0);
}

#endif