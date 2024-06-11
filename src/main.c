#include <stdio.h>
#include <stdlib.h>
#include "../include/carregamento.h"
#include <../include/leitura.h>

void limpaBuffer();

int main() {
    int opcaoGeral, opcaoRelatorio, opcaoRelatorioQuantitativo, mesEscolhido;

    int sair = 0;
    while(sair == 0){

        printf("******************SELECIONE UMA DAS OPCOES******************\n\n");
        printf("1: Analisar --- 2: Gerar relatorio --- 3: Sair\n=> ");

        scanf("%d", &opcaoGeral);
        limpaBuffer();
        if(opcaoGeral >= 1 && opcaoGeral <= 4){
            
        switch(opcaoGeral){
            case 1:
                system("clear");
                carregamento();
                break;
            case 2: 
                printf("\nEscolha uma opcao de relatorio:\n");
                printf("1: Quantitativo mensal\n");
                printf("2: Geral\n=> ");
                scanf("%d", &opcaoRelatorio);
                limpaBuffer();
                
                if(opcaoRelatorio == 1){
                    printf("\nEscolha o modelo de relatorio quantitativo:\n");
                    printf("1: Mes especifico\n");
                    printf("2: Mes a mes\n=> ");
                    scanf("%d", &opcaoRelatorioQuantitativo);
                    limpaBuffer();

                    if(opcaoRelatorioQuantitativo == 1){
                        printf("\nQual o mes desejado?\n");
                        printf("1: Janeiro\n");
                        printf("2: Fevereiro\n");
                        printf("...\n");
                        printf("12: Dezembro\n=> ");
                        scanf("%d", &mesEscolhido);
                        limpaBuffer();
                        leitura();      

                    }

                    if(opcaoRelatorioQuantitativo == 2){
                        printf("Aqui deve vir uma funcao que vai imprimir o relatorio mes a mes\n");
                    }
                }else{
                    printf("Funcao que vai imprimir o relatorio geral\n");
                }
                break;
            case 3:
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
                break;
            }
        }
    }
    return 0;
}

void limpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}