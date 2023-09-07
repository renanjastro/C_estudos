#include "bibliotecas/includes.h"
#include "bibliotecas/obterdados.h"
#include "bibliotecas/tadpilha.h"

void ImprimirMenu(){
    system("cls");
    printf("|---------------------------------|\n");
    printf("| 1 Inserir na pilha              |\n");
    printf("| 2 Remover da pilha              |\n");
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
                if(!PilhaCheia())
                {
                    pes = CadastrarPessoa();
                    Push(pes);
                }
                break;
            case 2:
                pes = Pop();
                if (pes != NULL)
                {
                    ImprimirPessoa(pes);
                    free(pes);
                }                                                
                break;
        }

    }while(opcao>=1 && opcao<=2);
  
    return 0;
}