/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que implementa as funções utilizadas para o menu.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#include <stdio.h>

#include "menu.h"
#include "utils.h"

#define WIDTH 16

void greetings(int v[]) {
    // Ordenação e Pesquisa
    printf("   ____          _                       /\\/|                _____                      _           \n"
           "  / __ \\        | |                     |/\\/                |  __ \\                    (_)          \n"
           " | |  | |_ __ __| | ___ _ __   __ _  ___ __ _  ___     ___  | |__) |__  ___  __ _ _   _ _ ___  __ _ \n"
           " | |  | | '__/ _` |/ _ \\ '_ \\ / _` |/ __/ _` |/ _ \\   / _ \\ |  ___/ _ \\/ __|/ _` | | | | / __|/ _` |\n"
           " | |__| | | | (_| |  __/ | | | (_| | (_| (_| | (_) | |  __/ | |  |  __/\\__ \\ (_| | |_| | \\__ \\ (_| |\n"
           "  \\____/|_|  \\__,_|\\___|_| |_|\\__,_|\\___\\__,_|\\___/   \\___| |_|   \\___||___/\\__,_|\\__,_|_|___/\\__,_|\n"
           "                                     )_)                                       | |                  \n"
           "                                                                               |_|                  \n"
    );
    printf("SEU PRIMEIRO VETOR: \n");

    print_half_array(v);

    printf("ATENÇÃO, O SEU 'VETOR ORDENADO' SERÁ IGUAL AO SEU VETOR ORIGINAL ENQUANTO VOCE NÃO UTILIZAR ALGUM ALGORITMO!\n");

    menu(); 
}


void menu() {
    printf(""
        " --------------------------------------------------\n"
        "|0 - Sair do programa                              |\n"
        "|1 - Criar novo vetor                              |\n"
        "|2 - Exibir vetor                                  |\n"
        "|3 - Ordenar com BubbleSort                        |\n"
        "|4 - Ordenar com ShellSort                         |\n"
        "|5 - Ordenar com QuickSort                         |\n"
        "|6 - Buscar elemento                               |\n"
        "|7 - Testar 1000 vezes                             |\n"
        " --------------------------------------------------\n"
    );
}

void shell_menu() {
    printf("ESCOLHA O GAP\n");

    printf(""
        " --------------------------------------------------\n"
        "|1 - Piso(N / 2^k)                                 |\n"
        "|2 - 4^k + 3 * 2^(k-1) + 1                         |\n"
        "|3 - 3k + 1                                        |\n"
        " --------------------------------------------------\n"
    );
}

void quick_menu() {
    printf("ESCOLHA O PIVO\n");

    printf(""
        " --------------------------------------------------\n"
        "|1 - Primeiro elemento                             |\n"
        "|2 - Elemento aleatório                            |\n"
        "|3 - Mediana entre 3 elementos                     |\n"  
        " --------------------------------------------------\n"
    );
}

void array_menu() {
    printf(""
        " --------------------------------------------------\n"
        "|1 - Vetor original (Completo)                     |\n"
        "|2 - Vetor original (Parte)                        |\n"
        "|3 - Vetor ordenado (Completo)                     |\n"
        "|4 - Vetor ordenado (Parte)                        |\n"
        "|5 - Ambos (Completos)                             |\n"
        "|6 - Ambos (Parte)                                 |\n"
        " --------------------------------------------------\n"
    );
}

void search_menu() {
    printf(""
        " --------------------------------------------------\n"
        "|1 - Busca sequencial (Escolha)                    |\n"
        "|2 - Busca sequencial (Aleatoria)                  |\n"
        "|3 - Busca binária (Escolha)                       |\n"
        "|4 - Busca binária (Aleatória)                     |\n"
        " --------------------------------------------------\n"
    );
}

void print_table(struct counter sum[], struct stats average[], struct stats variance[], struct stats standard_deviations[]) {
    int i;
    printf("ANALISANDO 1000 VEZES CADA ALGORITMO\n");

    const char *counter_names[N_ALGS] = {
        "BubbleSort",
        "FirstQs",
        "RandQs",
        "MedianQs",
        "OriginalShell",
        "SedgewickShell",
        "KnuthShell",
        "LinearSearch",
        "BinarySearch"
    };

    printf("%-*s", WIDTH, "");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*s", WIDTH, counter_names[i]);
    }
    printf("\n");
    printf("\n");

    printf("%-*s", WIDTH, "Comp");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, sum[i].comparisons);
    }
    printf("\n");

    printf("%-*s", WIDTH, "Trocas");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, sum[i].swap);
    }
    printf("\n");

    printf("%-*s", WIDTH + 1, "Média Comp ");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, average[i].comparisons);
    }
    printf("\n");

    printf("%-*s", WIDTH + 1, "Média Trocas ");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, average[i].swap);
    }
    printf("\n");

    printf("%-*s", WIDTH, "Var Comp");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, variance[i].comparisons);
    }
    printf("\n");

    printf("%-*s", WIDTH, "Var Trocas");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, variance[i].swap);
    }
    printf("\n");

    printf("%-*s", WIDTH, "DP Comp");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, standard_deviations[i].comparisons);
    }
    printf("\n");

    printf("%-*s", WIDTH, "DP Trocas");
    for (i = 0; i < N_ALGS; i++) {
        printf("%-*.2f", WIDTH, standard_deviations[i].swap);
    }
    printf("\n");
}

void ending() {
    // Fim do programa
    // -Eduardo Kaluf
    printf( "  ______ _                 _                                                          \n"
            " |  ____(_)               | |                                                         \n"
            " | |__   _ _ __ ___     __| | ___    _ __  _ __ ___   __ _ _ __ __ _ _ __ ___   __ _  \n"
            " |  __| | | '_ ` _ \\   / _` |/ _ \\  | '_ \\| '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ / _` | \n"
            " | |    | | | | | | | | (_| | (_) | | |_) | | | (_) | (_| | | | (_| | | | | | | (_| | \n"
            " |_|    |_|_| |_| |_|  \\__,_|\\___/  | .__/|_|  \\___/ \\__, |_|  \\__,_|_| |_| |_|\\__,_| \n"
            "                                    | |               __/ |                           \n"
            "         ______    _                |_|  _         _ |___/   _        __              \n"
            "        |  ____|  | |                   | |       | |/ /    | |      / _|             \n"
            "  ______| |__   __| |_   _  __ _ _ __ __| | ___   | ' / __ _| |_   _| |_              \n"
            " |______|  __| / _` | | | |/ _` | '__/ _` |/ _ \\  |  < / _` | | | | |  _|             \n"
            "        | |___| (_| | |_| | (_| | | | (_| | (_) | | . \\ (_| | | |_| | |               \n"
            "        |______\\__,_|\\__,_|\\__,_|_|  \\__,_|\\___/  |_|\\_\\__,_|_|\\__,_|_|               \n"
            "                                                                                      \n"
        );
}
