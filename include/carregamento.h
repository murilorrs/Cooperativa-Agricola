#ifndef CARREGAMENTO_H 
#define CARREGAMENTO_H
#define PATH_PREFIX "../data/cargas/"  // Diretório onde os arquivos de entrada estão armazenados
#define MAX_FILENAME_SIZE 100   // Tamanho máximo permitido para o nome do arquivo
#define MAX_PATH_SIZE (MAX_FILENAME_SIZE + sizeof(PATH_PREFIX)) // Tamanho total da string. ex:(../data/cargas/DadosGraos-Carga1.txt) ||funcao sizeof retorna a quantidade de caracteres de uma string.


void geraRelatorio(int protocolo, int quantidadeDeAmostras, int DD, int MM, float percentualUmidade, float pesoLimpo, int transgenico, int quantidadeA, int quantidadeB, int quantidadeC, int faixaA[], int faixaB[], int faixaC[]);
void carregamento();


#endif
