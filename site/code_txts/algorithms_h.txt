/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que molda os algoritmos utilizados.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#ifndef ALGORITHMS
#define ALGORITHMS

#include "utils.h"

/*
 * Algoritmo de ordenação genérico que não será incluso na análise  
 * Utilizado para ordenar vetores arbritários do programa
*/
void generic_sort(int v[], int n);

// Implementação do algoritmo BubbleSort
void bubble_sort(int v[], struct counter *c);

/* SHELL SORT */

// Calcula o gap original proposto pelo próprio Shell
void shell_original (int v[], struct counter *c);

// Calcula o gap proposto por Sedgewick
void sedgewick_exponents(int v[], struct counter *c);

// Calcula o gap através da sequência de Knuth
void knuth_sequence(int v[], struct counter *c);

/*
 * Algoritmo ShellSort em si
 * Todos os algoritmos anteriores são responsavéis por calcular o gap e chamar esta função
 * Que é de fato quem ordena o vetor
*/
void shell_sort(int v[], int k, struct counter *c);

/* QUICK SORT */

// QuickSort que utiliza o primeiro elemento do vetor como Pivo
void first_element_qs(int v[], int left, int right, struct counter *c);

// QuickSort que utiliza um elemento aleatório do vetor como Pivo
void random_element_qs(int v[], int left, int right, struct counter *c);

// QuickSort que utiliza a mediana de 3 elementos aleatórios do vetor como Pivo
void median_element_qs(int v[], int left, int right, struct counter *c);

/*
 * Algoritmo utilizado para particionar um vetor
 * QuickSort necessita parcticionar o vetor principal,
 * decompondo-o em vetores menores
*/
void partition(int v[], int left, int right, int *pivo_pos, int pivo, struct counter *c);

/* ALGORITMOS DE BUSCA */

// Implementação da busca linear com sentinela
int linear_search(int v[], int key, struct counter *c);

// Implementação da busca binária recursiva
int binary_search(int v[], int key, int left, int right, struct counter *c);

#endif
