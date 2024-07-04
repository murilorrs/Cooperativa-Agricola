#include "../include/relatorios.h"

void geraRelatorio(int protocolo, int quantidadeDeAmostras, int mes, int ano, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC,
                   int faixaA[], int faixaB[], int faixaC[], float percentualImpureza) {

  printf("%f\n", percentualImpureza);
  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("---------------------------------------------------------------");
  printf("\nOrigem: %d           Num. de amostras: %d        Data: %d/%d\n", protocolo, quantidadeDeAmostras, mes, ano);
  printf("Umidade(%%): %.2f%%    Peso limpo(t): %.2f       Transgenico: %s\n\n", percentualUmidade, pesoLimpo, (transgenico == 1) ? "Sim" : "Nao");
  printf("Umidade: Faixa 1                            Quant.:%d\n", quantidadeA);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeA; i++) {
    printf("%d - ", faixaA[i]);
  }

  printf("\n\n");

  printf("Umidade: Faixa 2                            Quant.:%d\n", quantidadeB);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeB; i++) {
    printf("%d - ", faixaB[i]);
  }

  printf("\n\n");
  printf("Umidade: Faixa 3                            Quant.:%d\n", quantidadeC);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeC; i++) {
    printf("%d - ", faixaC[i]);
  }

  printf("\n\n");
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