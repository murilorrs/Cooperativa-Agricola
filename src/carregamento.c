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

  snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX,nomeDoArquivo); 

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


  float somatorioDoPesoDasImpurezas = 0, somatorioDoPesoDasAmostras = 0, somatorioDiferencaPesoImpureza = 0, multiplicaUmidadePesoImpureza = 0, diferencaPesoImpureza; // variaveis usadas pra calcular PIC E GUC
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

      somatorioDoPesoDasImpurezas += (pesoDaImpureza / 1000);
      somatorioDoPesoDasAmostras += pesoDaAmostra;

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

  percentualDeImpurezas = somatorioDoPesoDasImpurezas / somatorioDoPesoDasAmostras;
  percentualUmidade = multiplicaUmidadePesoImpureza / somatorioDiferencaPesoImpureza;
  pesoLimpo = pesoGeralDaCarga - ((percentualDeImpurezas * pesoGeralDaCarga) / 100);

  fclose(file); 

  geraRelatorio(protocolo, quantidadeDeAmostras, mes, ano, percentualUmidade, pesoLimpo, tipo, quantidadeA, quantidadeB, quantidadeC, faixaA, faixaB, faixaC);
  arquivar(ID, protocolo, mes, ano, tipo, pesoGeralDaCarga, percentualDeImpurezas, percentualUmidade, pesoLimpo);
  
}

void geraRelatorio(int protocolo, int quantidadeDeAmostras, int mes, int ano, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC, int faixaA[], int faixaB[], int faixaC[]) {

  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("---------------------------------------------------------------");
  printf("\nOrigem: %d           Num. de amostras: %d        Data: %d/%d\n", protocolo, quantidadeDeAmostras, mes, ano);
  printf("Umidade(%%): %.2f%%    Peso limpo(t): %.2f       Transgenico: %d\n\n", percentualUmidade, pesoLimpo, transgenico);
  printf("Umidade: Faixa 1                            Quant.:%d\n", quantidadeA);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeA; i++) {
    printf("%d, ", faixaA[i]);
  }

  printf(".\n\n");

  printf("Umidade: Faixa 2                            Quant.:%d\n", quantidadeB);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeB; i++) {
    printf("%d, ", faixaB[i]);
  }

  printf(".\n\n");
  printf("Umidade: Faixa 3                            Quant.:%d\n", quantidadeC);
  printf("Ident. das Amostras: ");

  for (int i = 0; i < quantidadeB; i++) {
    printf("%d, ", faixaC[i]);
  }

  printf(".\n\n");
}

void arquivar(int origem, int carga, int MM, int DD, int tipo, float peso, float percImpurezas, float percUmidade, float pesoLimpo) {

  FILE *file;
  file = fopen("../data/database/carregamentos.dat", "ab");

  if (file == NULL) {
    printf("O arquivo não foi aberto corretamente");
    return;
  }
  fwrite(&origem, sizeof(int), 1, file);
  fwrite(&carga, sizeof(int), 1, file);
  fwrite(&MM, sizeof(int), 1, file);
  fwrite(&DD, sizeof(int), 1, file);
  fwrite(&tipo, sizeof(int), 1, file);
  fwrite(&peso, sizeof(float), 1, file);
  fwrite(&pesoLimpo, sizeof(float), 1, file);
  fwrite(&percImpurezas, sizeof(float), 1, file);
  fwrite(&percUmidade, sizeof(float), 1, file);

  fclose(file);
}