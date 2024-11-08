/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que implementa as funções usadas na análise estatística dos algoritmos.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "statistics.h"
#include "utils.h"
#include "algorithms.h"

void calc_sum(struct counter sum[], struct counter counters[][N_TESTES]) {
    long comparisons, swaps;

    for (int i = 0; i < N_ALGS; i++) {
        comparisons = 0;
        swaps = 0;

        for (int j = 0; j < N_TESTES; j++) {
            comparisons += counters[i][j].comparisons;
            swaps += counters[i][j].swap;
        }

        sum[i] = create_counter(comparisons, swaps);
    }
}

void calc_average(struct stats average[], struct counter sum[]) {
    for (int i = 0; i < N_ALGS; i++) {
        average[i].comparisons = (double)sum[i].comparisons / N_TESTES;
        average[i].swap = (double)sum[i].swap / N_TESTES;
    }
}


void calc_variance(struct stats variance[], struct stats average[], struct counter counters[][N_TESTES]) {
    for (int i = 0; i < N_ALGS; i++) {
        double comparisons_diff_sum = 0.0;
        double swaps_diff_sum = 0.0;
        
        for (int j = 0; j < N_TESTES; j++) {
            double comparisons_diff = counters[i][j].comparisons - average[i].comparisons;
            double swaps_diff = counters[i][j].swap - average[i].swap;

            comparisons_diff_sum += comparisons_diff * comparisons_diff;
            swaps_diff_sum += swaps_diff * swaps_diff;
        }


        variance[i].comparisons = (double)comparisons_diff_sum / (N_TESTES - 1);
        variance[i].swap = (double)swaps_diff_sum / (N_TESTES - 1);
    }

}

void calc_standart_deviation(struct stats standard_deviations[], struct stats variance[]) {
    for (int i = 0; i < N_ALGS; i++) {
        standard_deviations[i].comparisons = sqrt(variance[i].comparisons);
        standard_deviations[i].swap = sqrt(variance[i].swap);
    }
}

void run_tests(struct counter counters[][N_TESTES]) {
    int key;

    int v[N + 1], w[N + 1];

    for (int i = 0; i < N_TESTES; i++) {
        generate_data(v);

        copy_array(v, w);
        bubble_sort(w, &counters[0][i]);

        copy_array(v, w);
        first_element_qs(w, 1, N, &counters[1][i]);

        copy_array(v, w);
        random_element_qs(w, 1, N, &counters[2][i]);

        copy_array(v, w);
        median_element_qs(w, 1, N, &counters[3][i]);

        copy_array(v, w);
        shell_original(w, &counters[4][i]);

        copy_array(v, w);
        sedgewick_exponents(w, &counters[5][i]);

        copy_array(v, w);
        knuth_sequence(w, &counters[6][i]);

        key = aleat();

        linear_search(v, key, &counters[7][i]);
        binary_search(w, key, 1, N, &counters[8][i]);
    }
}