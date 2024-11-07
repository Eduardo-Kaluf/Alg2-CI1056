/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que molda as funções usadas na análise estatística dos algoritmos.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#ifndef STATISTICS
#define STATISTICS

#include "utils.h"

// Calcula a soma de uma matriz de contadores e a devolve em um vetor
void calc_sum(struct counter sum[], struct counter counters[][N_TESTES]);

// Calcula a média através de um vetor que contém a soma dos contadores
void calc_average(struct stats average[], struct counter sum[]);

// Calcula a variancia através de um vetor que contém a média dos contadores e um vetor com os próprios contadores
void calc_variance(struct stats variance[], struct stats average[], struct counter counters[][N_TESTES]);

// Calcula o desvio padrão através de um vetor que contém a variância
void calc_standart_deviation(struct stats standard_deviations[], struct stats variance[]);

// Teste 1000 vezes cada algoritmo, contando as trocas e comparações
void run_tests(struct counter counters[][N_TESTES]);

#endif
