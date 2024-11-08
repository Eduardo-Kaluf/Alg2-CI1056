/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo principal.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "menu.h"
#include "utils.h"
#include "algorithms.h"
#include "statistics.h"

int main() {
    struct counter c;
    int v[N + 1], w[N + 1];
    int sorting_method, array_method, search_method;
    int key, index;
    int choice = 1;

    // Define a semente para gerar os números aleatórios
    srand(time(NULL));
    
    // Gera um vetor aletório e o copia para outro vetor
    generate_data(v);
    copy_array(v, w);

    // Imprime a mensagem de boas vindas, junto ao vetor aleatório gerado
    greetings(v);

    // Loop principal
    while (choice != 0) {

    // Pede para o usuário um número. 0 finaliza o programa
    printf("ESCOLHA SUA OPÇÃO: \n");
    scanf("%d", &choice);

    switch (choice) {
        // Cria um novo vetor aleatório
        case 0:
            break;
        case 1:
            printf("GERANDO VETOR ALEATÓRIO...\n");

            generate_data(v);
            copy_array(v, w);
            print_half_array(v);
            break;
        // Imprimir algum vetor na tela
        case 2:
            array_menu();

            scanf("%d", &array_method);

            printf("IMPRIMINDO VETOR(ES)...\n");

            switch (array_method) {
                case 1:
                    print_array(v);
                    break;
                case 2:
                    print_half_array(v);
                    break;
                case 3:
                    print_array(w);
                    break;
                case 4:
                    print_half_array(w);
                    break;
                case 5:
                    printf("VETOR ORIGINAL: \n");
                    print_array(v);
                    printf("VETOR 'ORDENADO': \n");
                    print_array(w);
                    break;
                case 6:
                    printf("VETOR ORIGINAL: \n");
                    print_half_array(v);
                    printf("VETOR 'ORDENADO': \n");
                    print_half_array(w);
                    break;
                default:
                    printf("Entre um digito válido\n");
                    break;
            }

            break;
        // Ordenar com o BubbleSort
        case 3:
            printf("ORDENANDO COM BUBBLE SORT...\n");

            reset_counter(&c);
            
            copy_array(v, w);
            bubble_sort(w, &c);
            
            print_counter(c);
            print_half_array(w);

            break;
        // Ordenar com o ShellSort
        case 4:
            shell_menu();

            scanf("%d", &sorting_method);
            
            reset_counter(&c);
            copy_array(v, w);

            printf("ORDENANDO COM SHELL SORT, MÉTODO ");

            switch (sorting_method) {
                case 1:
                    printf("ORIGINAL...\n");
                    shell_original(w, &c);
                    break;
                case 2:
                    printf("SEDGEWICK...\n");
                    sedgewick_exponents(w, &c);
                    break;
                case 3:
                    printf("KNUTH...\n");
                    knuth_sequence(w, &c);
                    break;
                default:
                    printf("Entre um digito válido\n");
                    break;
            }

            print_counter(c);
            print_half_array(w);

            break;
        // Ordenar com o QuickSort
        case 5:
            quick_menu();
            
            scanf("%d", &sorting_method);
            
            reset_counter(&c);
            copy_array(v, w);

            printf("ORDENANDO COM QUICK SORT, PIVO: ");

            switch (sorting_method) {
                case 1:
                    printf("PRIMEIRO ELEMENTO...\n");
                    first_element_qs(w, 1, N, &c);
                    break;
                case 2:
                    printf("ELEMENTO ALEATÓRIO...\n");
                    random_element_qs(w, 1, N, &c);
                    break;
                case 3:
                    printf("ELEMENTO MEDIANO...\n");
                    median_element_qs(w, 1, N, &c);
                    break;
                default:
                    printf("Entre um digito válido\n");
                    break;
            }

            print_counter(c);
            print_half_array(w);

            break;
        // Buscar um elemento
        case 6:
            search_menu();

            scanf("%d", &search_method);

            reset_counter(&c);

            switch (search_method) {
                case 1:
                    scanf("%d", &key);

                    printf("PROCURANDO ELEMENTO %d...\n", key);

                    index = linear_search(v, key, &c);

                    found_element(index);

                    break;
                case 2:
                    key = aleat();

                    printf("PROCURANDO ELEMENTO %d...\n", key);
                    
                    index = linear_search(v, key, &c);

                    found_element(index);
                    
                    break;
                case 3:
                    scanf("%d", &key);

                    generic_sort(w, N);

                    printf("PROCURANDO ELEMENTO %d...\n", key);

                    index = binary_search(w, key, 1, N, &c);

                    found_element(index);

                    break;
                case 4:
                    key = aleat();

                    printf("PROCURANDO ELEMENTO %d...\n", key);

                    generic_sort(w, N);
                    
                    index = binary_search(w, key, 1, N, &c);

                    found_element(index);

                    break;            
                default:
                    printf("Entre um digito válido\n");
                    break; 
            }

            print_counter(c);

            break;
        // Realiza o teste 1000 vezes com cada algoritmo e analisa os dados
        case 7:
            struct counter counters[N_ALGS][N_TESTES];
            struct stats average[N_ALGS], variance[N_ALGS], standard_deviations[N_ALGS];
            struct counter sum[N_ALGS];

            printf("REALIZANDO O TESTE MIL VEZES...\n");

            fill_counter_matrix(counters);

            run_tests(counters);

            calc_sum(sum, counters);

            calc_average(average, sum);

            calc_variance(variance, average, counters);

            calc_standart_deviation(standard_deviations, variance);

            print_table(sum, average, variance, standard_deviations);

            break;
        default:
            printf("Entre um digito válido\n");
            break;
    }
    
    if (choice) {
        menu();
    }
    
    }

    // Imprime a despedida
    ending();

    return 0;
}
