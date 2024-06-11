#include <../include/leitura.h>

void leitura(){

	FILE *file;

	file = fopen("../data/database/carregamentos.dat", "rb");

	if(!file){
		printf("erro ao abrir o arquivo");
		return;
	}

	int data[1000];
	fread(data, sizeof(int), 1000, file);

	for(int i = 0; i < 10; i++){
		printf("%d", data[i]);
		printf("\n");
	}

	fclose(file);
}