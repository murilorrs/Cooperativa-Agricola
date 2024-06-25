#include <../include/carregamento.h>
#include <../include/main.h>

// Essa é a funcao que realiza a leitura e os calculos do projeto
void carregamento() {
  FILE *file;                            // declarando o ponteiro do tipo FILE
  char nomeDoArquivo[MAX_FILENAME_SIZE]; // declarando um vetor que vai receber o
                                         // nome do arquivo que o usuário digitar
                                         // || O [MAX_FILE_NAME] recebe nada mais
                                         // que o valor 100 definido la em cima
  char caminhoCompleto[MAX_PATH_SIZE];   // declarando um vetor que vai receber
                                         // a string completa do caminho

  int ID, mes, ano, protocolo, quantidadeDeAmostras, tipo;
  float pesoGeralDaCarga; // variaveis que vamos usar pra fazer os calculos de
                          // PIC e GUC

  printf("Digite o nome do arquivo da carga:\n=> ");
  fgets(nomeDoArquivo, MAX_FILENAME_SIZE,
        stdin);                                       // Aqui eu usei fgets invés de scanf porque o scanf estava me
                                                      // retornando um "O" no final do nome do arquivo, aí o
                                                      // programa nao encontrava o caminho certo
  nomeDoArquivo[strcspn(nomeDoArquivo, "\n")] = '\0'; // Removendo o /n do final da string porque também estava
                                                      // atrapalhando na hora de encontrar o arquivo

  snprintf(caminhoCompleto, sizeof(caminhoCompleto), "%s%s", PATH_PREFIX,
           nomeDoArquivo); // Essa função snprintf vai juntar o PATH_PREFIX
                           // (../cargas/data/) com o nome do arquivo que o usuário
                           // digitar, e vai retornar na variável caminhoCompleto,
                           // que é o caminho inteiro do arquivo de entrada
                           // (../data/cargas/nome_do_arquivo)
  // printf("%s\n", caminhoCompleto); // Esse codigo comentado mostra no
  // terminal o caminho completo para ter certeza que não houve erro de
  // digitação

  file = fopen(caminhoCompleto, "r"); // abre o arquivo

  // checa se o arquivo foi aberto corretamente
  if (file == NULL) {
    limpaTerminal();
    printf("ESTE ARQUIVO NAO EXISTE.");
    return;
  }

  // se abriu corretamente continua o codigo
  printf("\nDigite o mes do recebimento dessa carga:\n=> ");
  scanf("%d", &mes);
  printf("\nDigite o ano do recebimento dessa carga:\n=> ");
  scanf("%d", &ano);

  fscanf(file, "%d%d%f%d%d", &ID, &protocolo, &pesoGeralDaCarga, &quantidadeDeAmostras,
         &tipo); // Usa fscanf para ler os 5 primeiros dados do arquivo

  // **********************************************************************LENDO
  // OS PROXIMOS
  // ARQUIVOS******************************************************************************************************************************

  char conteudoDoArquivo[200]; // declara um vetor que vai receber o conteúdo
                               // do arquivo =>  a unica finalidade é pra
                               // podermos usar o fgets mais pra frente, nao
                               // armazena dados relevantes
  fgets(conteudoDoArquivo, 200,
        file); // Como a gente precisa ler a partir da segunda linha (os dados
               // de impureza e umidade começam lá), lemos aqui a primeira
               // linha para pulá-la no próximo fgets

  // inicializa as variáveis que vao receber os valores de cada elemento da
  // amostra
  int idAmostra, pesoDaImpureza; // recebe o elemento 1 da linha
  float pesoDaAmostra,
      umidade; // recebe o elemento 2 em diante da mesma linha

  // variaveis de calculo PIC GUC
  float somatorioDoPesoDasImpurezas = 0, somatorioDoPesoDasAmostras = 0, somatorioDiferencaPesoImpureza = 0,
        multiplicaUmidadePesoImpureza = 0,
        diferencaPesoImpureza; // variaveis usadas pra calcular PIC E GUC
  float percentualDeImpurezas, percentualUmidade,
      pesoLimpo; // recebe valores de PIC E GUC

  // variáveis para gerar o relatório
  int quantidadeA = 0, quantidadeB = 0, quantidadeC = 0;
  int faixaA[100] = {0};
  int faixaB[100] = {0};
  int faixaC[100] = {0};

  // faz um loop para ler linha a linha do arquivo até acabar
  while (fgets(conteudoDoArquivo, 200, file) != NULL) {

    // O laço ta lendo linha por linha, toda vez que ele passa por uma linha
    // esse sscanf armazena um dado da linha nas variaveis, nessa ordem do
    // sscanf
    if (sscanf(conteudoDoArquivo, "%d %f %d %f", &idAmostra, &pesoDaAmostra, &pesoDaImpureza,
               &umidade) == 4) { // estou usando sscanf pq essa funcao além de
                                 // funcionar como um fscanf normal, ela checa
                                 // se os 4 valores foram lidos corretamente.

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

  fclose(file); // fecha o arquivo de entrada

  geraRelatorio(protocolo, quantidadeDeAmostras, mes, ano, percentualUmidade, pesoLimpo, tipo, quantidadeA, quantidadeB,
                quantidadeC, faixaA, faixaB, faixaC);
  arquivar(ID, protocolo, mes, ano, tipo, pesoGeralDaCarga, percentualDeImpurezas, percentualUmidade, pesoLimpo);
}

void geraRelatorio(int protocolo, int quantidadeDeAmostras, int mes, int ano, float percentualUmidade, float pesoLimpo,
                   int transgenico, int quantidadeA, int quantidadeB, int quantidadeC, int faixaA[], int faixaB[],
                   int faixaC[]) {

  printf("\nCOOPERATIVA AGRICOLA GRAO_DO_VALE V1.0\n");
  printf("ANO: 2024\n");
  printf("---------------------------------------------------------------");
  printf("\nOrigem: %d           Num. de amostras: %d        Data: %d/%d\n", protocolo, quantidadeDeAmostras, mes, ano);
  printf("Umidade(%%): %.2f%%    Peso limpo(t): %.2f       Transgenico: %d\n\n", percentualUmidade, pesoLimpo,
         transgenico);
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

void arquivar(int origem, int carga, int MM, int DD, int tipo, float peso, float percImpurezas, float percUmidade,
              float pesoLimpo) {

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