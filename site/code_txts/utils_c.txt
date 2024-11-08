/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que implementa as funções utilitárias.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

struct counter create_counter(long comparisons, long swaps) {
    struct counter c;

    c.comparisons = comparisons;
    c.swap = swaps;
    
    return c;
}

void fill_counter_matrix(struct counter counters[][N_TESTES]) {
    for (int i = 0; i < N_ALGS; i++) {
        for (int j = 0; j < N_TESTES; j++) {
            counters[i][j] = create_counter(0, 0);
        }
    }
}

void reset_counter(struct counter *c) {
    if (c == NULL)
        return;

    c->comparisons = 0;
    c->swap = 0;
}

void print_counter(struct counter c) {
    printf("NUMERO DE TROCAS: %.0f\n", c.swap);
    printf("NUMERO DE COMPARAÇÕES: %.0f\n", c.comparisons);
}

void generate_data(int v[]) {
    for (int i = 1; i <= N; i++) {
        v[i] = aleat();
    }
}

void print_array(int v[]) {
    printf("[ ");
    for (int i = 1; i < N; i++) {
        printf("%d, ", v[i]);
    }
    printf("%d ]\n\n", v[N]);
}

void print_half_array(int v[]) {
    printf("[ ");
    
    for (int i = 1; i < 10; i++) {
        printf("%d, ", v[i]);
        
        if (i % 3 == 0) {
            printf("\n  ");
        }
    }

    printf("\n  ... \n\n  ");

    for (int i = N - 8; i <= N; i++) {
        if (i != N)
            printf("%d, ", v[i]);
    
        if ((i - 1) % 3 == 0) {
            if (i == N) {
                printf("%d ]\n", v[i]);
                break;
            }
            printf("\n  ");

        }
    }

    printf("\n");
}

void copy_array(int v[], int w[]) {
    for (int i = 1; i <= N; i++) {
        w[i] = v[i];
    }
}

void found_element(int index) {
    if (index == 0)
        printf("ELEMENTO NÃO ENCONTRADO! \n");
    else
        printf("ELEMENTO ENCONTRANDO NO ÍNDICE %d\n", index);
}

int aleat() {
    return (rand() % 2047) + 1;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int median_of_three(int arr[], int a, int b, int c) {
    if ((arr[a] > arr[b]) != (arr[a] > arr[c])) {
        return a;
    } else if ((arr[b] > arr[a]) != (arr[b] > arr[c])) {
        return b;
    } else {
        return c;
    }
}
