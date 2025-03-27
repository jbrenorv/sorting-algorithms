#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "ordenacao.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc < 3) {
        ImprimeErro_E_FinalizaExecucao("Deve-se informar o tamanho e o tipo do vetor");
    }

    char* output_file_name = argv[1];
    int n = atoi(argv[2]);
    int tipo = atoi(argv[3]);
    if (n < 1 || n > 214748364 || tipo < 1 || tipo > 3) {
        ImprimeErro_E_FinalizaExecucao("Parametros invalidos");
    }

    int *original = CriaVetor(n, tipo);
    int *v = AlocaVetor(n);

    const int algorithms_count = 13;
    algoritmo algoritmos[] =
    {
        // Nome               , N max    , Alg.             , Alg. coleta dados
        { "Bolha"             , 50000    , Bolha            , Bolha_ColetaDados             },
        { "BolhaFlag"         , 50000    , BolhaFlag        , BolhaFlag_ColetaDados         },
        { "Coquetel"          , 50000    , Coquetel         , Coquetel_ColetaDados          },
        { "Selecao"           , 50000    , Selecao          , Selecao_ColetaDados           },
        { "Insercao"          , 50000    , Insercao         , Insercao_ColetaDados          },
        { "Shellsort"         , 214748364, Shellsort        , Shellsort_ColetaDados         },
        { "Mergesort"         , 214748364, Mergesort        , Mergesort_ColetaDados         },
        { "Quicksort"         , 214748364, Quicksort        , Quicksort_ColetaDados         },
        { "Quicksort Prob"    , 214748364, QuicksortProb    , QuicksortProb_ColetaDados     },
        { "Quicksort Insercao", 214748364, QuicksortInsercao, QuicksortInsercao_ColetaDados },
        { "Heapsort"          , 214748364, Heapsort         , Heapsort_ColetaDados          },
        { "Contagem"          , 214748364, Contagem         , Contagem_ColetaDados          },
        { "Balde"             , 214748364, Balde            , Balde_ColetaDados             },
        { "Radixsort Contagem", 214748364, RadixsortContagem, RadixsortContagem_ColetaDados },
        { "Radixsort Balde"   , 214748364, RadixsortBalde   , RadixsortBalde_ColetaDados    },
    };

    FILE *fp;
    if ((fp = fopen(output_file_name, "a")) == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < algorithms_count; ++i) {
        if (n > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(n, original, v);

        dados_execucao dados = ObterDadosExecucao(n, v, &algoritmos[i]);

        fprintf(fp, "%s,%i,%i,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            n, tipo,
            dados.comparacoes,
            dados.movimentacoes,
            dados.tempo_ms
        );
    }

    free(original);
    free(v);
    fclose(fp);

    return 0;
}
