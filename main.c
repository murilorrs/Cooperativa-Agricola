#include <stdio.h>

int main(){

    int notas [5];
    int nota;
    int maiorNota = 0;

    for(int i = 1; i < 6; i++){
        printf("Digite a nota %d\n", i);
        scanf("%d", &nota);

        notas[i] = nota;
    }


    return 0;
}