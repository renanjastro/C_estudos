#ifndef TADLISTAENCADEADA_H
#define TADLISTAENCADEADA_H
#include "includes.h"
#include "model.h"

//a esturura lista que armazena a quantidade de elementos na lista e o ponteiro para o primeiro elemento.
typedef struct l {
	int qtdeElementos;
	Pessoa *cabeca;
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
Lista* CriarLista(){
	//aloca na memoria uma lista e inicializa suas variaveis (a lista esta vazia)
	Lista *lista = (Lista*) malloc(sizeof(Lista));
	lista->qtdeElementos = 0;
	lista->cabeca = NULL;
	return (lista);
}

bool ListaVazia(Lista *lista)
{
	//se a cabeca nao aponta para nada, a fila esta vazia
	if(lista->cabeca == NULL)	
		return true;
	
	return(lista->cabeca == NULL);			
}

void InserirNoInicio(Lista *lista, Pessoa *pes)
{	
	//para inserir uma pessoa na cabeca da lista, basta a cabeca apontar para essa pessoa
	//a pessoa que esta sendo inserida deverá apontar para o elemento que estava anteriormente na fila 
	//se antes nao tinha ninguem na fila, pes vai apontar para ninguem, indicando que alem de ser o primeiro, tambem é o ultimo da fila
	pes->prox = lista->cabeca;
	lista->cabeca = pes;	
	lista->qtdeElementos++;
}

void InserirNoFim(Lista *lista, Pessoa *pes)
{
	//se não existe nenhum elemento na fila, inserimos no inicio mesmo
	if (ListaVazia(lista))
	{
		InserirNoInicio(lista,pes);
		return;
	}

	//para inserir um elemento no final da fila, devemos percorrer toda a fila ate que encontramos o ultimo elemento
	//com esse elemento de pivo, adicionamos o elemento pes após esse elemento.	
	Pessoa *pivo = lista->cabeca; //o pivo inicializa com a posicao incial da fila

	//enquanto houver alguem na fila, alem da posicao que pivo indica, ele recebe a posicao desse proximo elemento.
	while(pivo->prox!=NULL)
		pivo = pivo->prox;

	pivo->prox = pes;		//coloca a pessoa na ultima posicao
	pes->prox = NULL;		//depois dessa pessoa nao terá mais ninguem, sendo assim setamos null para o ponteiro dele
	lista->qtdeElementos++;	//incrementa a quantidade de elementos na fila
}

void InserirNaPosicao(Lista *lista, Pessoa *pes, int posicao)
{
	if(posicao > lista->qtdeElementos)
		InserirNoFim(lista,pes);
	else if (posicao <= 1)		
		InserirNoInicio(lista,pes);
	else{
		Pessoa *pivo = lista->cabeca;
		int i=1;
		
		//percorrer a lista ate encontrar uma posicao antes da que queremos inserir
		for(i=1; i<posicao-1; i++)
			pivo = pivo->prox;
		
		pes->prox = pivo->prox;
		pivo->prox = pes; 						
		lista->qtdeElementos++;
	}
}

void RemoverNoInicio(Lista *lista)
{	
	Pessoa *aux;
	if(!ListaVazia(lista))
	{		
		aux = lista->cabeca; //pessoa que sera removida da lista
		if(aux->prox != NULL)
			lista->cabeca = aux->prox;
		
		free(aux);
		lista->qtdeElementos--;
	}	
}

void RemoverNoFim(Lista *lista)
{
	Pessoa *aux;
	if(!ListaVazia(lista))
	{
		aux = lista->cabeca;
		while(aux->prox->prox != NULL)
			aux = aux->prox;

		free(aux->prox->prox);
		aux->prox = NULL;
		lista->qtdeElementos--;
	}	
}

void RemoverNaPosicao(Lista *lista, int posicao)
{
	if(posicao == lista->qtdeElementos)
		RemoverNoFim(lista);
	else if (posicao == 0)
		RemoverNoInicio(lista);
	else{
		Pessoa* pes;
		Pessoa* pivo = lista->cabeca;
		int i=1;
		
		for ( i = 1; i < posicao-1; i++)
		pes = pivo->prox;
		pivo->prox = pes->prox;
		free(pes);
		lista->qtdeElementos--;
		
	}
}


#endif