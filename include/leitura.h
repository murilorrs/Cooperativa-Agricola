#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LEITURA_H
#define LEITURA_H

void cabecalho();
void leitura(int *mes, int *opcaoRelatorioQuantitativo, int *opcaoRelatorio);
void mesEspecifico(int, int, float);
void mesAMes(int, int, float);
void relatorioEstatistico(int, float, float, int);

#endif