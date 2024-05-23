#include <stdio.h>
#include <string.h>

int main(){

	int valor = 2;
	int *prtValor = &valor;

	printf("Endereco de valor:%p\n", &valor);
	printf("Valor de valor:%d\n", valor);
	printf("Endereco de valor pelo prt%p\n", prtValor);
	printf("Endereco do prt%p\n", &prtValor);
	printf("Valor que esta armazenado no endereco q o ponteiro aponta%d\n", *prtValor);

	return 0;
}