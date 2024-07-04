#include "../include/escrevedb.h"
#include "../include/main.h"

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