#ifndef TADPILHADINAMICA_H
#define TADPILHADINAMICA_H
#include "includes.h"
#include "model.h"

typedef struct pilha{
    Pessoa** pilha;         //ponteiro para armazenar a pilha de informacoes
    int top;                //top armazena o topo de uma pilha    
    int maxPilha;           //quantidade de posicoes na pilha
}Pilha;

//definicoes
Pilha* CriarPilha(int positions);
void DestruirPilha(Pilha* p);
void Push(Pilha* p, Pessoa* item);
Pessoa* Pop(Pilha* p);
bool PilhaCheia(Pilha* p);
bool PilhaVazia(Pilha* p);
void TransferirPilha(Pilha* origem, Pilha* destino);

//implementacoes
Pilha* CriarPilha(int positions)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha)); 
    p->top = 0;
    p->maxPilha = positions;
    
    // alocação da fila, um vetor na quantidade de posicoes desejadas    
    p->pilha = (Pessoa**) malloc(positions * sizeof(Pessoa*));

    //setando null nas posicoes de memoria que foram alocadas    
    for(int i=0;i<p->maxPilha;i++)
        p->pilha[i] = NULL;

    return p;                                           
}

void TransferirPilha(Pilha* origem, Pilha* destino)
{
    Pessoa* aux;
    aux = Pop(origem);
    while(aux != NULL){
        Push(destino,aux);
        aux = Pop(origem);
    }       
}

void DestruirPilha(Pilha* p)
{       
    int i=0;    
    for(i=0;i<p->maxPilha;i++)
    {
        if(p->pilha[i] != NULL)
            free(p->pilha[i]);
    }
    free(p);
}

void Push(Pilha* p, Pessoa* item)
{
    if(PilhaCheia(p))
        return;

    p->pilha[p->top]=item;    
    p->top++;
}

Pessoa* Pop(Pilha* p)
{
    Pessoa* retorno;
    if(PilhaVazia(p))        
        return NULL;   

    p->top--;    
    retorno = p->pilha[p->top]; 
    p->pilha[p->top] = NULL;    
    return retorno;
}

bool PilhaCheia(Pilha* p)
{
    return (p->top >= p->maxPilha);
}

bool PilhaVazia(Pilha* p)
{
    return(p->top == 0);
}

#endif