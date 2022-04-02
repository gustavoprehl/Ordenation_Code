#include "bolha.h"
#include "insercao.h"
#include "selecao.h"
#include "geracao.h"
#include "performance.h"
//=============================================================================
#include <stdio.h>
#include <stdlib.h>
//=============================================================================
int main(int argc, char *argv[])
{ 
    int *V;
    
    srand(time(0));

    printf("Time\tMemory\tN\n");
    for(int n = 2000; n <= 1024000; n *= 2){
        
        Performance ordenacao;
        V = malloc(n * sizeof(int));

        //Melhor caso
        crescente2(V, n); //printf("M\t");
        //Pior caso
        decrescente2(V, n); //printf("P\t");
        //Médio caso
        aleatorio2(V, n); //printf("Me\t");

        //Algoritmo bolha
        start_ordenation(&ordenacao);
        bolha(V, n);
        end_ordenation(&ordenacao);
        calculate_cpu(&ordenacao);
        print_performance(&ordenacao, n);

        //Algoritmo inserção
        start_ordenation(&ordenacao);
        insercao(V, n);
        end_ordenation(&ordenacao);
        calculate_cpu(&ordenacao);
        print_performance(&ordenacao, n);

        //Algoritmo seleção
        start_ordenation(&ordenacao);
        selecao(V, n);
        end_ordenation(&ordenacao);
        calculate_cpu(&ordenacao);
        print_performance(&ordenacao, n);
        free(V);
    }
    return 0;
}
