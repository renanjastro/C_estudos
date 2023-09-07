#include "bibliotecas/includes.h"
#include "bibliotecas/obterdados.h"
#include "bibliotecas/tadfila.h"


void ImprimirMenu(){    
    printf("\n|---------------------------------|\n");
    printf("| 1 Inserir na fila               |\n");
    printf("| 2 Imprimir Proximo              |\n");
    printf("| => Sair                         |\n");
    printf("|---------------------------------|\n");
}

int main(){
    system("cls");
    srand(time(NULL));
        
    Pessoa* pes;
    int opcao = 0;    
    do{
        ImprimirMenu();
        opcao = LerInteiro("Escolha uma opcao:");

        switch (opcao){
            case 1:
                if(!filaCheia()){
                    pes = CadastrarPessoa();
                    qstore(pes);
                }                
                break;
            case 2:
                pes = qretrieve();
                if(pes != NULL){
                    ImprimirPessoa(pes);
                    free(pes);
                }                                    
                break;
        }

    }while(opcao>=1 && opcao<=2);
    
    printf("\nBons estudos.");
    return 0;
}