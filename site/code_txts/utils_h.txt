/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que molda as funções utilitárias.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#ifndef UTILS
#define UTILS

// Tamanho padrão dos vetores
#define N 1024

// Número de algoritmos que serão testados
#define N_ALGS 9

// Vezes que cada algoritmo é executado no teste grande
#define N_TESTES 1000

// Estrutura usada para contar a quantidade de comparações e trocas dos algoritmos
struct counter {
    double comparisons;
    double swap;
};

// Estrutura usada para a análise de dados, visando ter maior precisão decimal
struct stats {
    double comparisons;
    double swap;
};

// Cria uma estrutura contador e a devolve para o usuário
struct counter create_counter(long comparisons, long swaps);

// Popula uma matrix com contadores zerados
void fill_counter_matrix(struct counter counters[][N_TESTES]);

// Seta o contador para 0 trocas e 0 comparações
void reset_counter(struct counter *c);

// Imprime de maneira formatada a quantidade de trocas e comparações
void print_counter(struct counter c);

// Preenche um veotr com inteiros entre 0 e 2048
void generate_data(int v[]);

// Imprime um vetor inteiro de maneira formatada
void print_array(int v[]);

// Imprime os primeiros e últimos 9 números de um vetor de maneira formatada
void print_half_array(int v[]);

// Copia os elementos do primeiro vetor para o segundo
void copy_array(int v[], int w[]);

/*
 * Imprime de maneira formatada o índice de um elemento encontrado
 * Considera 0 como elemento não encontrado
*/
void found_element(int index);

// Gera um número aleatório entre 0 e 2048
int aleat();

#endif
