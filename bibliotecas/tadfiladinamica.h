#ifndef TADFILADINAMICA_H
#define TADFILADINAMICA_H
#include "includes.h"
#include "model.h"

typedef struct f{
    Pessoa** fila;          //ponteiro para armazenar a fila de informacoes
    int spos;               //(spos => store position) contem o indice do proximo armazenamento 
    int rpos;               //(rpos => retrieve position) contem o indice do elemento a ser recuperado.
    bool filaCircular;      //parametro para dizer se queremos nossa fila circular ou nao.
    int maxFila;
    int emFila;             //quantidade de elementos na fila, para simplificar a implementacao da fila circular    
}Fila;


// --------------- definicoes ---------------//
Fila* CriarFila(bool circular, int positions);
void DestruirFila(Fila* f);
void qstore(Fila* f, Pessoa* item);
Pessoa* qretrieve(Fila* f);
bool filaCheia(Fila* f);
bool filaVazia(Fila* f);

// --------------- implementações ---------------//
Fila* CriarFila(bool circular, int positions)
{           
    //cria a fila e inicializar as variaveis
    Fila* f = (Fila*) malloc(sizeof(Fila)); 
    f->spos = 0;
    f->rpos = 0;
    f->emFila = 0;
    f->filaCircular = circular;
    f->maxFila = positions;

    // alocação da fila, um vetor na quantidade de posicoes desejadas    
    f->fila = malloc(positions * sizeof(Pessoa*));    
    return f;
}

void DestruirFila(Fila* f)
{       
    int i=0;    
    for(i=0;i<f->maxFila;i++)
        free(f->fila[i]);

    free(f);
}

void qstore(Fila* f, Pessoa* item)
{
    if(filaCheia(f))        
        return;

    f->fila[f->spos] = item;
    f->spos++;
    f->emFila++;
}

Pessoa* qretrieve(Fila* f)
{
    if(filaVazia(f))           
        return NULL;    

    f->rpos++;
    f->emFila--;
    return f->fila[f->rpos-1];
}

bool filaCheia(Fila* f)
{
    if(f->filaCircular == true)
    {        
        if(f->emFila==f->maxFila)
        {
            printf("fila cheia\n");
            return true;
        }
        else
        {        
            if(f->spos==f->maxFila)
                f->spos=0;
        }
    }
    else
    {        
        if(f->spos==f->maxFila)
        {
            printf("fila cheia\n");
            return true;
        }
    }        
    return false;    
}

bool filaVazia(Fila* f)
{
    if(f->filaCircular == true)
    {
        if(f->emFila==0) 
        {
            printf("fila vazia\n");            
            return true;        
        }
    }
    else
    {
        if(f->rpos==f->spos)
        {
            printf("fila vazia\n");
            return true;        
        }
    }
    return false;
}

#endif