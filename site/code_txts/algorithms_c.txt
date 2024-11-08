/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo de implementação para os algoritmos utilizados.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "algorithms.h"
#include "utils.h"

void generic_sort(int v[], int n) {
    int aux;

    for (int i = 1; i < n ; i++) {

        for (int j = 1; j < n - i + 1; j++) {

            if (v[j] > v[j + 1]) {

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

            }
        }
    }
}

void bubble_sort(int v[], struct counter *c) {
    int aux, swapped;

    for (int i = 1; i < N ; i++) {
        swapped = 0;

        for (int j = 1; j < N - i + 1; j++) {

            c->comparisons++;

            if (v[j] > v[j + 1]) {

                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                swapped = 1;
                c->swap++;
            }
        }
              
        if (!swapped)
            break;
    }
}

void shell_original (int v[], struct counter *c) {
    int k, step = 1;

    do {
        k = N / pow(2, step);

        shell_sort(v, k, c);

        step++;
    } while (k != 0);
}

void sedgewick_exponents(int v[], struct counter *c) {
    int k = 1;

    int step = 1;
    while (k <= N) {
        k = pow(4, step) + 3 * pow(2, step - 1) + 1;
        step++;
    }

    step -= 2;

    do {
        k = pow(4, step) + 3 * pow(2, step - 1) + 1;

        shell_sort(v, k, c);

        step--;
    } while (k != 1);
}

void knuth_sequence(int v[], struct counter *c) {
    int k = 1;

    do {
        k = k * 3 + 1;
    } while (k <= N);

    do {
        k = k / 3;

        shell_sort(v, k, c);
        
    } while (k != 1);
}

void shell_sort(int v[], int k, struct counter *c) {
    int i, j, aux;

    for (i = k + 1; i <= N; i++) {
        aux = v[i];
        j = i;

        // DECIDI NÃO CONTAR O CASO QUE SAI DO WHILE
        while (j > k && v[j - k] > aux ) {
            c->comparisons++;

            v[j] = v[j - k];
            c->swap++;

            j = j - k;
            if (j <= k)
                break;
        }

        v[j] = aux;
        c->swap++;
    }
}

int partition_first_element(int arr[], int low, int high, struct counter *c) {
    int pivot = arr[low];
    
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            c->comparisons++;
            i++;
            c->swap++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[low], &arr[i]);  
    c->swap++;
    return i;
}

int partition_rand(int arr[], int low, int high, struct counter *c) {
    int random_index = low + rand() % (high - low + 1);
    swap(&arr[low], &arr[random_index]);

    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            c->comparisons++;
            i++;
            c->swap++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[low], &arr[i]);  
    c->swap++;
    return i;
}

int partition_median(int arr[], int low, int high, struct counter *c) {
    int rand1 = low + rand() % (high - low + 1);
    int rand2 = low + rand() % (high - low + 1);
    int rand3 = low + rand() % (high - low + 1);

    int median_index = median_of_three(arr, rand1, rand2, rand3);

    swap(&arr[low], &arr[median_index]);

    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            c->comparisons++;
            i++;
            c->swap++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[low], &arr[i]);  
    c->swap++;
    return i;
}

void first_element_qs(int v[], int low, int high, struct counter *c) {
    if (low < high) {
        int pi = partition_first_element(v, low, high, c);

        first_element_qs(v, low, pi - 1, c);
        first_element_qs(v, pi + 1, high, c);
    }
}

void random_element_qs(int v[], int low, int high, struct counter *c) {
    if (low < high) {
        int pi = partition_rand(v, low, high, c);

        random_element_qs(v, low, pi - 1, c);
        random_element_qs(v, pi + 1, high, c);
    }
}

void median_element_qs(int v[], int low, int high, struct counter *c) {
    if (low < high) {
        int pi = partition_median(v, low, high, c);

        median_element_qs(v, low, pi - 1, c);
        median_element_qs(v, pi + 1, high, c);
    }
}

int linear_search(int v[], int key, struct counter *c) {
    int i = N;

    v[0] = key;

    while (v[i] != key) {
        c->comparisons++;
        i--;
    }
    
    return i;
}

int binary_search(int v[], int key, int left, int right, struct counter *c) {
    int middle = (left + right) / 2;

    if (left > right) {
        return 0;
    }

    c->comparisons++;

    if (key < v[middle])
        return binary_search(v, key, left, middle - 1, c);
    else if (key > v[middle])
        return binary_search(v, key, middle + 1, right, c);
    else
        return middle;
}
