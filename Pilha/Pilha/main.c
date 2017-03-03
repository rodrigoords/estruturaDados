/***************************************************************************************************
 * C File: main.c
 * Implementa as funções passadas em aula.
 * Disciplina: Estruturas de Dados Avançadas
 * Professor: MSc. Giulliano Paes Carnielli
 **************************************************************************************************/
#include "pilha.h"

int main()
{
    Pilha *p = criaPilha();
    printf("");
    push(p, 33.5);
    push(p, 18);
    push(p, 26.9);
    push(p, 17.4);
    push(p, 9.2);
    push(p, 67.5);
    push(p, 89);
    push(p, 23.9);
    push(p, 123.4);
    push(p, 87.20);
    push(p, 47.2);

    imprimePilha(p);

    float* retorno;
    peek(p, retorno);
    printf("Peek: %f", *retorno);


    return 0;
}
