#include "bibliotecas/obterdados.h"
#include "bibliotecas/tablistaduplamenteencadeada.h"
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
    Lista* le = CriarListaDE();
	    
    int opcao = 0;    
    do{
        ImprimirMenu();
        opcao = LerInteiro("\nEscolha uma opcao:");

        switch (opcao){
            case 1:                
                break;
            case 2:                
                break;
            case 3:                
                break;
            case 4:                                
                break;
            case 5:                
                break;
            case 6:                
                break;
            case 7:                
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