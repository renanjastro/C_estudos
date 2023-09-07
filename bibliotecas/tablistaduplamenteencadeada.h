#ifndef TADLISTADUPLAMENTEENCADEADA_H
#define TADLISTADUPLAMENTEENCADEADA_H
#include "includes.h"
#include "model.h"

//a esturura lista que armazena a quantidade de elementos na lista e o ponteiro para o primeiro elemento.
typedef struct l {
	int qtdeElementos;
	
	Pessoa *inicio;
	Pessoa *fim;

} Lista;



//Definicoes
Lista* CriarLista();
bool ListaVazia(Lista *lista);
void InserirNoInicio(Lista *lista, Pessoa *pes);
void InserirNoFim(Lista *lista, Pessoa *pes);
void InserirNaPosicao(Lista *lista, Pessoa *pes, int posicao);
void RemoverNoInicio(Lista *lista);
void RemoverNoFim(Lista *lista);
void RemoverNaPosicao(Lista *lista, int posicao);


//Implementacoes
Lista* CriarLista()
{
Lista *lista = (Lista*) malloc(sizeof(Lista));
	lista->qtdeElementos = 0;
	lista->inicio = NULL;
	return (lista);

}
bool ListaVazia(Lista *lista)
{
return(lista->qtdeElementos == 0);
}

void InserirNoInicio(Lista *lista, Pessoa *pes)
{
pes->ant = NULL;
pes->prox = lista->inicio;
lista->inicio = pes;
lista->qtdeElementos++;
	
	if(pes->prox != NULL)
	pes->prox->ant = pes;

	if(lista->fim == NULL)
	lista->fim = pes;

}
void InserirNoFim(Lista *lista, Pessoa *pes)
{
pes->prox = NULL;
pes->ant = lista->fim;
lista->fim = pes;
lista->qtdeElementos++;

	if (pes->ant != NULL)
	pes->ant->prox = pes;

	if (lista->inicio == NULL)
	lista->inicio = pes;

	

}

void InserirNaPosicao(Lista *lista, Pessoa *pes, int posicao)
{
	
if(posicao > lista->qtdeElementos)
		InserirNoFim(lista,pes);
	else if (posicao <= 1)		
		InserirNoInicio(lista,pes);
	else{
		Pessoa *A = lista->inicio;
		Pessoa *D = NULL;
		int i=1;
		
		//percorrer a lista ate encontrar uma posicao antes da que queremos inserir
		for(i=1; i<posicao-1; i++)
			A = A->prox;
		
		D = A->prox;
		pes->prox = A->prox;
		pes->ant = D->ant;
		A->prox = pes;
		D->ant = pes;
		lista->qtdeElementos++;
	}
}

void RemoverNoInicio(Lista *lista)
{
	Pessoa *aux;
	if(!ListaVazia(lista))
	{		
		aux = lista->inicio; //pessoa que sera removida da lista
		if(aux->prox != NULL)
		{
			lista->inicio = aux->prox;
			aux->prox->ant = NULL;
		}
		
		
		free(aux);
		lista->qtdeElementos--;
	}	

}

void RemoverNoFim(Lista *lista)
{
	Pessoa *aux;
	if(!ListaVazia(lista))
	{
		aux = lista->inicio;
		while(aux->prox != NULL)
			aux = aux->prox;
		if(aux->ant == NULL)
			lista = aux->prox;
		else
			aux->ant->prox = NULL;
			free(aux);
		
		lista->qtdeElementos--;
	}	

}

#endif

