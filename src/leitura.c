#include <../include/leitura.h>

typedef struct
{
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

void leitura(int *mes, int *opcaoRelatorioQuantitativo, int *opcaoRelatorio)
{
    Dados d;

    FILE *file;
    file = fopen("../data/database/carregamentos.dat", "rb");

    if (file == NULL)
    {
        printf("O arquivo não foi aberto corretamente\n");
        return;
    }

    cabecalho();

    while (fread(&d, sizeof(Dados), 1, file) == 1)
    {
        if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 1)
        {
            if (*mes == d.mess)
                mesEspecifico(d.origem, d.carga, d.percUmidade);
        }
        else if (*opcaoRelatorio == 1 && *opcaoRelatorioQuantitativo == 2)
            mesAMes(d.origem, d.carga, d.percUmidade);
        else
            relatorioEstatistico(d.origem, d.peso, d.pesoLimpo, d.tipo);
    }

    fclose(file);
}

void cabecalho()
{
    system("clear");
    printf("Origem    Carga(s)    GU Faixa 1    GU Faixa 2    GU Faixa 3    GU Extra\n");
    printf("-------+------------+-------------+-------------+--------------+----------\n");
}

void mesEspecifico(int origem, int cargas, float gUmidade)
{
    printf("%03d        %03d", origem, cargas);

    if (gUmidade >= 0 && gUmidade <= 8.6)
        printf("            X\n\n");
    else if (gUmidade >= 8.6 && gUmidade <= 15)
        printf("                          X\n\n");
    else if (gUmidade >= 15 && gUmidade <= 25)
        printf("                                       X\n\n");
    else
        printf("                                                     X\n\n");
}

void mesAMes(int origem, int cargas, float gUmidade)
{
    printf("%03d        %03d", origem, cargas);

    if (gUmidade >= 0 && gUmidade <= 8.6)
        printf("            X\n\n");
    else if (gUmidade >= 8.6 && gUmidade <= 15)
        printf("                          X\n\n");
    else if (gUmidade >= 15 && gUmidade <= 25)
        printf("                                       X\n\n");
    else
        printf("                                                     X\n\n");
}

void relatorioEstatistico(int origem, float pesoTotal, float pesoLimpo, int tipo)
{
    printf("Origem  Peso Total |\n                               |");
}