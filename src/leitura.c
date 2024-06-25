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

void cabecalhoRelatorioMes() {
  limpaTerminal();
  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("--------------------------------------------------------------------------\n");

  printf("Origem    Carga(s)    GU Faixa 1    GU Faixa 2    GU Faixa 3    GU Extra\n");
  printf("-------+------------+-------------+-------------+--------------+-----"
         "-----\n");
}

void mesEspecifico(int origem, int cargas, float gUmidade) {
  printf("%03d        %03d", origem, cargas);

  if (gUmidade >= 0 && gUmidade <= 8.5)
    printf("            X\n\n");
  else if (gUmidade >= 8.6 && gUmidade <= 15)
    printf("                          X\n\n");
  else if (gUmidade >= 15 && gUmidade <= 25)
    printf("                                       X\n\n");
  else
    printf("                                                     X\n\n");
}

void mesAMes(int origem, int cargas, float gUmidade) {
  printf("%03d        %03d", origem, cargas);

  if (gUmidade >= 0 && gUmidade <= 8.6)
    printf("            X\n\n");
  else if (gUmidade >= 8.6 && gUmidade <= 15)
    printf("                          X\n\n");
  else if (gUmidade >= 16 && gUmidade <= 25)
    printf("                                       X\n\n");
  else
    printf("                                                     X\n\n");
}

void cabecalhoRelatorioGeral() {
  limpaTerminal();
  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("---------------------------------------------------------------------"
         "-----\n\n");

  printf("             | Faixa 1   (umid.) | Faixa 2   (umid.) |Faixa 3    (umid.)\n");
  printf("Ori-   Peso  | Peso      Tipo(%%) | Peso      Tipo(%%) | Peso      Tipo(%%)\n");
  printf("Gem    Total | Limpo  Trans  Nao | Limpo  Trans  Nao | Limpo  Trans  Nao ");
  printf("\n");
  printf("-----+-------+-------+------+----+------+------+-----+------+------+--------\n");
}

void relatorioGeral(int origem, float pesoTotal, float pesoLimpo, int tipo, float gUmidade) {

  if (gUmidade >= 0 && gUmidade <= 8.5) {

    if (tipo == 0) {
      printf("%03d    %.2f | %.2f          X  |                   |\n", origem, pesoTotal, pesoLimpo);
    } else {
      printf("%03d    %.2f | %.2f    X        |                   |\n", origem, pesoTotal, pesoLimpo);
    }
    printf("             |                   |                   |\n");

  } else if (gUmidade >= 8.6 && gUmidade <= 15) {

    if (tipo == 0) {
      printf("%03d    %.2f |                   | %.2f          X  |\n", origem, pesoTotal, pesoLimpo);
    } else {
      printf("%03d    %.2f |                   | %.2f    X        |\n", origem, pesoTotal, pesoLimpo);
    }
    printf("             |                   |                   |\n");

  } else if (gUmidade >= 16 && gUmidade <= 30) {

    if (tipo == 0) {
      printf("%03d    %.2f |                   |                   |  %.2f         X\n", origem, pesoTotal, pesoLimpo);
    } else {
      printf("%03d    %.2f |                   |                   |  %.2f    X\n", origem, pesoTotal, pesoLimpo);
    }
    printf("             |                   |                   |\n");
  }
}