#include <stdio.h>


int parImpar (int par);


int main(){

    int numero;

    printf("Digite o numero\n");
    scanf("%d", &numero);
   

    
    parImpar(numero) ? printf("Par\n") : printf("impar\n");

    return 0;
}
int parImpar (int numero){

    return numero % 2 == 0;
}
