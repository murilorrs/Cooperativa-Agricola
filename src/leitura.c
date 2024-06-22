#include <../include/leitura.h>

typedef struct
{
    int origem;
    int carga;
    int mess;
    int ano;
    int tipo;
    float peso;
    float percImpurezas;
    float percUmidade;
} Dados;

void leitura(int *mes)
{

    Dados d;

    FILE *file;
    file = fopen("../data/database/carregamentos.dat", "rb");

    if (file == NULL)
    {
        printf("O arquivo não foi aberto corretamente");
        return;
    }

    while (fread(&d, sizeof(Dados), 1, file) == 1)
    {
        if (*mes == d.mess)
        {
            // Imprimir informações do carregamento
            printf("Origem: %d\n", d.origem);
            printf("Carga: %d\n", d.carga);
            printf("Data: %02d/%02d\n", d.mess, d.ano);
            printf("Tipo: %d\n", d.tipo);
            printf("Peso: %.2f kg\n", d.peso);
            printf("Impurezas: %.2f%%\n", d.percImpurezas);
            printf("Umidade: %.2f%%\n", d.percUmidade);
            printf("\n");
        }
        else
            printf("\nO mes escolhido nao existe!\n");
    }

    fclose(file);
}