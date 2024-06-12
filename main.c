#include <stdio.h>


double media (double *vetor, int);


int main(){

    double vetor[5];
    double valor;
    int tamanho = 5;

    for(int i = 0; i < tamanho; i++){
        printf("Digite o valor:\n");
        scanf("%lf", &valor);
        vetor[i] = valor;
    }

    printf("A media é: %.2lf\n",media (vetor, tamanho));

    return 0;
}

double media (double *vetor, int tamanho){
    double acumulador = 0;
    double media;

    for(int i = 0; i < tamanho; i++){
        acumulador += *(vetor + i);
        media = acumulador / tamanho;

    }
    return media;
}
