#include "../include/escrevedb.h"
#include "../include/relatorios.h"
#include <../include/carregamento.h>
#include <../include/main.h>

void carregamento() {
  FILE *file;
  char nomeDoArquivo[MAX_FILENAME_SIZE];

  char caminhoCompleto[MAX_PATH_SIZE];

  int ID, mes, ano, protocolo, quantidadeDeAmostras, tipo;
  float pesoGeralDaCarga;

  printf("Digite o nome do arquivo da carga:\n=> ");
  fgets(nomeDoArquivo, MAX_FILENAME_SIZE, stdin);

  nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0';

  snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX, nomeDoArquivo);

  file = fopen(caminhoCompleto, "r");

  if (file == NULL) {
    limpaTerminal();
    printf("ESTE ARQUIVO NAO EXISTE.");
    return;
  }

  printf("\nDigite o mes do recebimento dessa carga:\n=> ");
  scanf("%d", &mes);
  printf("\nDigite o ano do recebimento dessa carga:\n=> ");
  scanf("%d", &ano);
  limpaTerminal();

  fscanf(file, "%d%d%f%d%d", &ID, &protocolo, &pesoGeralDaCarga, &quantidadeDeAmostras, &tipo);

  char conteudoDoArquivo[200];

  fgets(conteudoDoArquivo, 200, file);

  int idAmostra, pesoDaImpureza;
  float pesoDaAmostra, umidade;

  float somatorioDoPesoDasImpurezas = 0, somatorioDoPesoDasAmostras = 0, somatorioDiferencaPesoImpureza = 0, multiplicaUmidadePesoImpureza = 0, diferencaPesoImpureza;
  float percentualDeImpurezas, percentualUmidade, pesoLimpo;

  int quantidadeA = 0, quantidadeB = 0, quantidadeC = 0;
  int faixaA[100] = {0};
  int faixaB[100] = {0};
  int faixaC[100] = {0};

  while (fgets(conteudoDoArquivo, 200, file) != NULL) {

    if (sscanf(conteudoDoArquivo, "%d %f %d %f", &idAmostra, &pesoDaAmostra, &pesoDaImpureza, &umidade) == 4) {

      diferencaPesoImpureza = pesoDaAmostra - (pesoDaImpureza / 1000);
      multiplicaUmidadePesoImpureza += umidade * diferencaPesoImpureza;
      somatorioDiferencaPesoImpureza += pesoDaAmostra - (pesoDaImpureza / 1000);

      somatorioDoPesoDasImpurezas += pesoDaImpureza;      //(g)
      somatorioDoPesoDasAmostras += pesoDaAmostra * 1000; //(g)

      if (umidade >= 0 && umidade <= 8.5) {
        faixaA[quantidadeA] = idAmostra;
        quantidadeA++;
      }

      if (umidade >= 8.6 && umidade <= 15) {
        faixaB[quantidadeB] = idAmostra;
        quantidadeB++;
      }

      if (umidade >= 15.1 && umidade <= 25) {
        faixaC[quantidadeC] = idAmostra;
        quantidadeC++;
      }
    } else {
      printf("Nao foi possivel ler a linha do arquivo.\n");
    }
  }

  percentualDeImpurezas = (somatorioDoPesoDasImpurezas / somatorioDoPesoDasAmostras) * 100;
  percentualUmidade = multiplicaUmidadePesoImpureza / somatorioDiferencaPesoImpureza;
  pesoLimpo = pesoGeralDaCarga - ((percentualDeImpurezas * pesoGeralDaCarga) / 100);

  fclose(file);

  geraRelatorio(protocolo, quantidadeDeAmostras, mes, ano, percentualUmidade, pesoLimpo, tipo, quantidadeA, quantidadeB, quantidadeC, faixaA, faixaB, faixaC, percentualDeImpurezas);
  arquivar(ID, protocolo, mes, ano, tipo, pesoGeralDaCarga, percentualDeImpurezas, percentualUmidade, pesoLimpo);
}
