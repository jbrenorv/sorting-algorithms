# include "../ordenacao.h"

void Selecao(int n, int *v) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[k]) {
                k = j;
            }
        }
        if (k != i) {
            Troca(&v[k], &v[i]);
        }
    }
}

void Selecao_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[k]) {
                k = j;
            }
            dados->comparacoes++;
        }
        if (k != i) {
            Troca(&v[k], &v[i]);
            dados->movimentacoes += 3;
        }
    }
}
