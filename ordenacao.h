#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef long long int64;

typedef enum tipo_vetor {
    CRESCENTE = 1,
    DECRESCENTE,
    ALEATORIO
} tipo_vetor;

typedef struct dados_execucao {
    int64 comparacoes;
    int64 movimentacoes;
    int64 iteracoes;
    double tempo_ms;
} dados_execucao;

typedef struct algoritmo {
    char *nome;
    int tamanho_maximo;
    void (* alg)(int, int *);
    void (* alg_coleta_dados)(int, int *, dados_execucao *);
} algoritmo;

typedef struct noh {
    int valor;
    struct noh* prox;
} noh;


// Utils
void ImprimeErro_E_FinalizaExecucao(const char *mensagem);
void Troca(int* a, int* b);
int* AlocaVetor(int n);
int* AlocaVetorLimpo(int n);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
void GeraVetorCrescente(int n, int* v);
void GeraVetorDecrescente(int n, int* v);
void GeraVetorAleatorio(int n, int* v);
int *CriaVetor(int n, tipo_vetor tipo);
void CopiaVetor(int n, int *origem, int* destino);
void ImprimeVetor(int n, int *v, const char* prefixo);
int min(int a, int b);
int max(int a, int b);
int ObterMaiorElemento(int n, int *v);
int ObterMaiorElemento_ColetaDados(int n, int *v, dados_execucao* dados);
void Verifica_Ordenacao(int n, int* v, algoritmo* a);
dados_execucao ObterDadosExecucao(int n, int* v, algoritmo* a);

// Bolha
void Bolha(int n, int *v);
void Bolha_ColetaDados(int n, int *v, dados_execucao *dados);

// BolhaFlag
void BolhaFlag(int n, int *v);
void BolhaFlag_ColetaDados(int n, int *v, dados_execucao *dados);

// Coquetel
void Coquetel(int n, int *v);
void Coquetel_ColetaDados(int n, int *v, dados_execucao *dados);

// Selecao
void Selecao(int n, int *v);
void Selecao_ColetaDados(int n, int *v, dados_execucao *dados);

// Insercao
void Insercao(int n, int *v);
void Insercao_ColetaDados(int n, int *v, dados_execucao *dados);

// Shellsort
void Shellsort(int n, int *v);
void Shellsort_ColetaDados(int n, int *v, dados_execucao *dados);

// Mergesort
void Mergesort(int n, int *v);
void MergesortRec(int l, int r, int *v, int *aux);
void Merge(int l, int m, int r, int *v, int *aux);
void Mergesort_ColetaDados(int n, int *v, dados_execucao *dados);
void MergesortRec_ColetaDados(int l, int r, int *v, int *aux, dados_execucao *dados);
void Merge_ColetaDados(int l, int m, int r, int *v, int *aux, dados_execucao *dados);

// Quicksort
void Quicksort(int n, int *v);
void QuicksortProb(int n, int *v);
void QuicksortInsercao(int n, int *v);
void QuicksortRec(int l, int r, int *v);
void QuicksortProbRec(int l, int r, int *v);
void QuicksortLimitado(int l, int r, int k, int *v);
int Particiona(int l, int r, int *v);
void ParticionaDuplo(int l, int r, int *i, int *j, int *v);
int ParticionaAleatorio(int l, int r, int *v);
void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *v);
void Quicksort_ColetaDados(int n, int *v, dados_execucao *dados);
void QuicksortProb_ColetaDados(int n, int *v, dados_execucao *dados);
void QuicksortInsercao_ColetaDados(int n, int *v, dados_execucao *dados);
void QuicksortRec_ColetaDados(int l, int r, int *v, dados_execucao *dados);
void QuicksortProbRec_ColetaDados(int l, int r, int *v, dados_execucao *dados);
void QuicksortLimitado_ColetaDados(int l, int r, int k, int *v, dados_execucao *dados);
int Particiona_ColetaDados(int l, int r, int *v, dados_execucao *dados);
void ParticionaDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados);
int ParticionaAleatorio_ColetaDados(int l, int r, int *v, dados_execucao *dados);
void ParticionaAleatorioDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados);

// Heapsort
void Heapsort(int n, int *v);
void ConstroiHeap(int n, int *v);
void Heapify(int i, int n, int *v);
void Heapsort_ColetaDados(int n, int *v, dados_execucao *dados);
void ConstroiHeap_ColetaDados(int n, int *v, dados_execucao *dados);
void Heapify_ColetaDados(int i, int n, int *v, dados_execucao *dados);

// Contagem
void Contagem(int n, int *v);
void Contagem_ColetaDados(int n, int *v, dados_execucao *dados);

// Balde
void Balde(int n, int *v);
void InsereOrdenado(int valor, noh** l);
void ApagaLista(noh* cabeca);
void Balde_ColetaDados(int n, int *v, dados_execucao *dados);
void InsereOrdenado_ColetaDados(int valor, noh** cabeca, dados_execucao* dados);

// Radixsort
void RadixsortContagem(int n, int *v);
void RadixsortBalde(int n, int *v);
void ContagemDigital(int p, int n,  int* v);
void BaldeDigital(int p, int n, int *v);
int d(int p, int valor);
void RadixsortContagem_ColetaDados(int n, int *v, dados_execucao *dados);
void RadixsortBalde_ColetaDados(int n, int *v, dados_execucao *dados);
void ContagemDigital_ColetaDados(int p, int n,  int* v, dados_execucao *dados);
void BaldeDigital_ColetaDados(int p, int n, int *v, dados_execucao *dados);

#endif
