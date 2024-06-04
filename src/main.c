#include <stdio.h>
#include <stdlib.h>
#include "../include/carregamento.h"
#include "../include/arquiva.h"


void limpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//system
int main() {
    int opcaoGeral, opcaoRelatorio, opcaoRelatorioQuantitativo, mesEscolhido;

    int sair = 0;
    while(sair == 0){

        printf("******************SELECIONE UMA DAS OPCOES******************\n\n");
        printf("1: Analisar --- 2: Arquivar --- 3: Gerar relatorio --- 4: Sair\n=> ");

        scanf("%d", &opcaoGeral);

        if(opcaoGeral >= 1 && opcaoGeral <= 4){

        switch(opcaoGeral){
            case 1:
                limpaBuffer();
                system("clear");
                carregamento();
                break;
            case 2:

                break;
            case 3: 
                printf("Escolha uma opcao de relatório:\n");
                printf("1: Quantitativo mensal\n");
                printf("2: Geral\n=> ");
                scanf("%d", &opcaoRelatorio);

                if(opcaoRelatorio == 1){
                    printf("Escolha o modelo de relatório quantitativo:\n");
                    printf("1: Mes especifico\n");
                    printf("2: Mes a mes\n=> ");
                    scanf("%d", &opcaoRelatorioQuantitativo);

                    if(opcaoRelatorioQuantitativo == 2){
                        printf("Aqui deve vir uma funcao que vai imprimir o relatório mes a mes\n");
                    }else{
                        printf("Qual o mes desejado?\n");
                        printf("1: Janeiro\n");
                        printf("2: Fevereiro\n");
                        printf("...\n");
                        printf("12: Dezembro\n=> ");
                        scanf("%d", &mesEscolhido);

                        printf("aqui vai vir uma funcao que vai checar se existe relatório no mes escolhido e mostrar pro user\n");
                }
            }
            case 4:
                printf("\nTem certeza que deseja sair?\n1 sim | 2 nao:\n=> ");

                while(1){
                    
                    int opcaoDeSair;
                    scanf("%d", &opcaoDeSair);

                    if(opcaoDeSair == 1){
                        sair = 1;
                        break;
                    }else if(opcaoDeSair == 2){
                        system("clear");
                        break;
                    }else{
                        printf("\nEntrada invalida. Insira um valor dentro do intervalo\n=> ");
                        while(getchar() != '\n');
                        system("clear");
                    }
                } 
            }
        }else{
            system("clear");
            printf("Opcao invalida, digite novamente\n\n");
        }
    }
    
    return 0;
}