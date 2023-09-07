#include "bibliotecas/obterdados.h"
#include "bibliotecas/tadlistaencadeada.h"
#include "bibliotecas/model.h"


void ImprimirMenu(){    
    system("cls");
    printf("-------------------------------------------------------------\n");    
    printf("| 1 Inserir Novo Fim                                        |\n");
    printf("| 2 Inserir No Inicio                                       |\n");
    printf("| 3 Inserir Na Posicao                                      |\n");
    printf("| 4 Remover No Inicio                                       |\n");
    printf("| 5 Remover No Fim                                          |\n");
    printf("| 6 Remover Na Posicao                                      |\n");
    printf("| 7 Imprimir Todos Registros                                |\n");
    printf("| 8 Pesquisar Registro                                      |\n");    
    printf("| 9 Salvar Agenda                                           |\n");
    printf("| 10 Formatar Agenda                                        |\n");
    printf("| => SAIR                                                   |\n");
    printf("-------------------------------------------------------------\n");    
}

int main(){
    system("cls");
    srand(time(NULL));
    
    Pessoa* pes;
    Lista* le = CriarLista();
	
    int posicao=0;
    int opcao = 0;    
    do{
        ImprimirMenu();
        opcao = LerInteiro("\nEscolha uma opcao:");

        switch (opcao){
            case 1:
                pes = CadastrarPessoa();
                InserirNoFim(le,pes);
                break;
            case 2:
                pes = CadastrarPessoa();
                InserirNoInicio(le,pes);
                break;
            case 3:
                posicao = LerInteiro("\nEm qual posicao deseja inserir:");
                pes = CadastrarPessoa();
                InserirNaPosicao(le,pes,posicao);
                break;
            case 4:                
                RemoverNoInicio(le);
                break;
            case 5:
                RemoverNoFim(le);
                break;
            case 6:
                posicao = LerInteiro("\nEm qual posicao deseja remover:");
                RemoverNaPosicao(le,posicao);                            
                break;
            case 7:
                if(!ListaVazia(le))
                {                                    
                    pes = le->cabeca;     
                    do{                        
                        ImprimirPessoa(pes);
                        pes = pes->prox;
                    }while (pes != NULL);                      
                }
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;            
        }

    printf("\n");
    system("pause");
    }while(opcao>=1 && opcao <= 10);  
    
    printf("\nfim do programa");
    return 0;
}

