#include "bibliotecas/includes.h"
#include "bibliotecas/obterdados.h"
#include "bibliotecas/tadpilhadinamica.h"

void ImprimirMenu(){ 
    system("cls");   
    printf("\n|----------------------------------|\n");
    printf("| 1 Inserir na pilha A             |\n");
    printf("| 2 Inserir na pilha B             |\n");
    printf("| 3 Remover da pilha A             |\n");
    printf("| 4 Remover da pilha B             |\n");
    printf("| 5 Tirar da A e colocar em B      |\n");
    printf("| 6 Tirar da B e colocar em A      |\n");
    printf("| 7 Imprimir todos de A            |\n");
    printf("| 8 Imprimir todos de B            |\n");
    printf("| => Sair                          |\n");
    printf("|----------------------------------|\n");
}

int main(){
    system("cls");
    srand(time(NULL));
    
    Pessoa* pes;
    Pilha* pilhaA = CriarPilha(10);
    Pilha* pilhaB = CriarPilha(10);
    Pilha* pilhaAux;
    
    int opcao = 0;    
    do{
        ImprimirMenu();
        opcao = LerInteiro("Escolha uma opcao:");

        switch (opcao){
            case 1:
                if(!PilhaCheia(pilhaA))
                {
                    pes = CadastrarPessoa();
                    Push(pilhaA,pes);
                }
                break;
            case 2:
                if(!PilhaCheia(pilhaB))
                {
                    pes = CadastrarPessoa();
                    Push(pilhaB,pes);
                }                                              
                break;
            case 3:
                pes = Pop(pilhaA);
                if (pes != NULL)
                {
                    ImprimirPessoa(pes);
                    free(pes);
                }                                               
                break;
            case 4:
                pes = Pop(pilhaB);
                if (pes != NULL)
                {
                    ImprimirPessoa(pes);
                    free(pes);
                }                                               
                break;
            case 5:
                if(PilhaVazia(pilhaA))                
                    printf("\nA pilha A esta vazia.");
                else if(PilhaCheia(pilhaB)) 
                    printf("\nA pilha B esta cheia.");
                else{
                    pes = Pop(pilhaA);
                    Push(pilhaB,pes);   
                }                                               
                break;
            case 6:
                if(PilhaVazia(pilhaB))                
                    printf("\nA pilha B esta vazia.");
                else if(PilhaCheia(pilhaA)) 
                    printf("\nA pilha A esta cheia.");
                else{
                    pes = Pop(pilhaB);
                    Push(pilhaA,pes);   
                } 
                break;
            case 7:
                pilhaAux = CriarPilha(10);
                pes = Pop(pilhaA);
                while(pes != NULL)
                {
                    ImprimirPessoa(pes);
                    Push(pilhaAux,pes);                    
                    pes = Pop(pilhaA);                    
                }                                             
                TransferirPilha(pilhaAux,pilhaA);
                DestruirPilha(pilhaAux);
                break;
            case 8:
                pilhaAux = CriarPilha(10);
                pes = Pop(pilhaB);
                while(pes != NULL)
                {
                    ImprimirPessoa(pes);
                    Push(pilhaAux,pes);
                    pes = Pop(pilhaB);
                }                                
                TransferirPilha(pilhaAux,pilhaB);
                DestruirPilha(pilhaAux);
                break;
        }    
    printf("\n");
    system("pause");
    }while(opcao>=1 && opcao<=8);
  
    
    DestruirPilha(pilhaA);
    DestruirPilha(pilhaB);
    return 0;
}