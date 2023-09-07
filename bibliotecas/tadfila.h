#ifndef TADFILA_H
#define TADFILA_H
#include "includes.h"
#include "model.h"

//A lista é uma forma linear de organizar as informações
//utiliza o conceito de (FIFO) first in, first out

#define MAXFILA 10
Pessoa* fila[MAXFILA];          //Vetor de ponteiros com a quantidade de elementos que necessitamos.
int spos;                       //(spos => store position) contem o indice do proximo armazenamento 
int rpos;                       //(rpos => retrieve position) contem o indice do elemento a ser recuperado.
bool filaCircular=true;         //parametro para dizer se queremos nossa fila circular ou nao.
int emFila;                     //quantidade de elementos na fila, para simplificar a implementacao da fila circular

//------------------------------ definicoes
void qstore(Pessoa* item);      //metodo para colocar um elemento na fila
Pessoa* qretrieve();            //metodo para remover um elemento da fila
bool filaCheia();               //metodo para verificar se a fila esta cheia
bool filaVazia();               //metodo para verificar se a fila esta vazia 

//----------------------------- implementações
void qstore(Pessoa* item){        
    if(filaCheia())        
        return;

    fila[spos] = item;
    spos++;
    emFila++;
}

Pessoa* qretrieve(){
    if(filaVazia())                
        return NULL;

    rpos++;
    emFila--;
    return fila[rpos-1]; 
}

bool filaCheia()
{   
    if(filaCircular == true)
    {        
        if(emFila==MAXFILA)
        {
            printf("fila cheia");
            return true;  
        }
        else
        {
            if(spos==MAXFILA)
                spos=0;
        }
    }
    else
    {        
        if(spos==MAXFILA)
        {
            printf("fila cheia");
            return true;
        }
    }        
    return false;
}

bool filaVazia()
{
    if(filaCircular == true)
    {
        if(emFila==0)
        {
            printf("fila vazia");
            return true;  
        }
    }
    else
    {
        if(rpos==spos)
        {
            printf("fila vazia");
            return true;  
        }
    }
    return false;
}



#endif