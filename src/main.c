#include <stdio.h>
#include "../include/carregamento.h"

int main() {

    int a;
    printf("valor de a\n");
    scanf("%d", &a);

    if(a == 1){
        carregamento();
    }else{
        printf("diferente de 1 ");
    }

    // int opcaoGeral, opcaoRelatorio, opcaoRelatorioQuantitativo, mesEscolhido;

    // printf("******************SELECIONE UMA DAS OPCOES******************\n");
    // printf("1: Analisar --- 2: Arquivar --- 3: Gerar relatorio\n");
    // scanf("%d", &opcaoGeral);

    // switch(opcaoGeral){
    //     case 1:
    //         carregamento();
    //         break;
    //     case 2:
    //         printf("funcao pra armazenar o arquivo");
    //         break;
    //     case 3: 
    //         printf("Escolha uma opcao de relatório:\n");
    //         printf("1: Quantitativo mensal\n");
    //         printf("2: Geral\n");
    //         scanf("%d", opcaoRelatorio);

    //         if(opcaoRelatorio == 1){
    //             printf("Escolha o modelo de relatório quantitativo:\n");
    //             printf("1: Mes especifico\n");
    //             printf("2: Mes a mes\n");
    //             scanf("%d", &opcaoRelatorioQuantitativo);

    //             if(opcaoRelatorioQuantitativo == 2){
    //                 printf("Aqui deve vir uma funcao que vai imprimir o relatório mes a mes\n");
    //             }else{
    //                 printf("Qual o mes desejado?\n");
    //                 printf("1: Janeiro\n");
    //                 printf("2: Fevereiro\n");
    //                 printf("...\n");
    //                 printf("12: Dezembro\n");
    //                 scanf("%d", &mesEscolhido);

    //                 printf("aqui vai vir uma funcao que vai checar se existe relatório no mes escolhido e mostrar pro user\n");
    //         }
    //     }   
    // }
    
    return 0;
}