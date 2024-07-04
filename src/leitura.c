#include "../include/relatorios.h"
#include <../include/leitura.h>
#include <../include/main.h>

typedef struct {
  int origem;
  int carga;
  int mess;
  int ano;
  int tipo;
  float peso;
  float pesoLimpo;
  float percImpurezas;
  float percUmidade;
} Dados;

void leitura(int *mes, int *opcaoRelatorioQuantitativo, int *opcaoRelatorio) {
  Dados d;

  FILE *file;
  file = fopen("../data/database/carregamentos.dat", "rb");

  if (file == NULL) {
    printf("O arquivo não foi aberto corretamente\n");
    return;
  }
  if (*opcaoRelatorio == 1)

    cabecalhoRelatorioMes();
  else
    cabecalhoRelatorioGeral();

  while (fread(&d, sizeof(Dados), 1, file) == 1) {
    if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 1) {
      if (*mes == d.mess)
        mesEspecifico(d.origem, d.carga, d.percUmidade);
    } else if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 2)
      mesAMes(d.origem, d.carga, d.percUmidade);
    else
      relatorioGeral(d.origem, d.peso, d.pesoLimpo, d.tipo, d.percUmidade);
  }

  fclose(file);
}
