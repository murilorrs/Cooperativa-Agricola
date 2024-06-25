#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LEITURA_H
#define LEITURA_H

void cabecalhoRelatorioMes();
void cabecalhoRelatorioGeral();
void leitura(int *mes, int *opcaoRelatorioQuantitativo, int *opcaoRelatorio);
void mesEspecifico(int, int, float);
void mesAMes(int, int, float);
void relatorioGeral(int, float, float, int, float);

#endif