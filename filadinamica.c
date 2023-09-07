#include "bibliotecas/obterdados.h"
#include "bibliotecas/tadfiladinamica.h"
#include "bibliotecas/model.h"

void ImprimirMenu(){    
    printf("\n|---------------------------------|\n");
    printf("| 1 Inserir na fila A               |\n");
    printf("| 2 Inserir na fila B               |\n");    
    printf("| 3 Remover da fila A               |\n");
    printf("| 4 Remover da fila B               |\n");
    printf("| => Sair                           |\n");
    printf("|-----------------------------------|\n");
}

int main(){
    system("cls");
    srand(time(NULL));

    int qtdeFilaA = LerInteiro("Digite a quantidade de elementos na fila A:\n");
    int qtdeFilaB = LerInteiro("Digite a quantidade de elementos na fila B:\n");
    
    Pessoa* pes;          
    Fila* filaA = CriarFila(true,qtdeFilaA);    
    Fila* filaB = CriarFila(true,qtdeFilaB);
    
    int opcao = 0;    
    do{
        ImprimirMenu();
        opcao = LerInteiro("Escolha uma opcao:");

        switch (opcao){
            case 1:
                if(!filaCheia(filaA)){
                    pes = CadastrarPessoa();
                    qstore(filaA,pes);
                }                
                break;
            case 2:
                if(!filaCheia(filaB)){
                    pes = CadastrarPessoa();
                    qstore(filaB,pes);
                }                
                break;
            case 3:
                pes = qretrieve(filaA);
                if(pes != NULL){
                    ImprimirPessoa(pes);
                    free(pes);
                }
                break;
            case 4:
                pes = qretrieve(filaB);
                if(pes != NULL){
                    ImprimirPessoa(pes);
                    free(pes);
                }
                break;            
        }
    }while(opcao>=1 && opcao<=4);    
    
    DestruirFila(filaA);
    DestruirFila(filaB);   
    return 0;
}