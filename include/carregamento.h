#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CARREGAMENTO_H
#define CARREGAMENTO_H
#define PATH_PREFIX "../data/cargas/"
#define MAX_FILENAME_SIZE 100
#define MAX_PATH_SIZE (MAX_FILENAME_SIZE + sizeof(PATH_PREFIX))

void geraRelatorio(int protocolo, int quantidadeDeAmostras, int DD, int MM, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC, int faixaA[],
                   int faixaB[], int faixaC[], float percentualImpureza);
void carregamento();
void arquivar(int origem, int carga, int mes, int ano, int tipo, float peso, float percImpurezas, float percUmidade, float pesoLimpo);

#endif
