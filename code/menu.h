/* 
 * Trabalho Prático: Ordenação e Pesquisa
 * Arquivo header, que molda as funções utilizadas para o menu.
 * Feito em 20/11/2024 para a disciplina CI1056 - Algoritmos e Estruturas de Dados 2 
*/

#ifndef MENU
#define MENU

#include "utils.h"

// Imprime a mensagem de boas vindas, junto a um vetor passado
void greetings(int v[]);

// Imprime na tela o menu principal do programa, onde as escolhas são feitas
void menu();

// Imprime na tela a despedida do programa
void ending();

// Imprime na tela o menu de escolhas relacionadas a impressão dos vetores
void array_menu();

// Imprime na tela o menu de escolhas relacionadas a pesquisa nos vetores
void search_menu();

// Imprime na tela o menu de escolhas relacionadas ao método de Gap utilizado pelo shell
void shell_menu();

// Imprime na tela o menu de escolhas relacionadas ao método do Pivo utilizado pelo Quick
void quick_menu();

// Imprime na tela a tabela que mostra os resultado da análise feita, a partir dos dados concedidos
void print_table(struct counter counters[], struct stats average[], struct stats variance[], struct stats standard_deviations[]);

#endif