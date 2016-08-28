#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

int main()
{
    int vetorAux[TAMANHO_VETOR] = {10,9,8,7,6,5,4,3,2,1};
    int vetor[TAMANHO_VETOR];

    //inicia vetor com valores de teste.
    resetaVetor(vetor, TAMANHO_VETOR, vetorAux);

    printf("testa função bubbleShort\n");
    bubbleShort(vetor, TAMANHO_VETOR);
    printVetor(vetor, TAMANHO_VETOR);

    //reseta vetor com valores de teste
    resetaVetor(vetor, TAMANHO_VETOR, vetorAux);

    printf("\nteste função selectionShort\n");
    selectionShort(vetor, TAMANHO_VETOR);
    printVetor(vetor, TAMANHO_VETOR);

    //reseta vetor com valores de teste
    resetaVetor(vetor, TAMANHO_VETOR, vetorAux);

    printf("\nteste função quickShort\n");
    quickShort(vetor, 0 ,TAMANHO_VETOR-1);
    printVetor(vetor, TAMANHO_VETOR);

    return 0;
}

void printVetor(int vet[], int tam){

    for (int i = 0; i < tam; i++){
        printf("%d\t",vet[i]);
    }
}

void resetaVetor(int vet[], int tam, int valores[]){
    for (int i = 0; i < tam; i++){
        vet[i] = valores[i];
    }
}
