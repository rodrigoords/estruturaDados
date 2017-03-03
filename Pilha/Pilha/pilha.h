/***************************************************************************************************
 * Header File: Pilha.h
 * Define as estruturas necessarias para a especificacao do TAD Pilha.
 *
 * A estrutura da pilha contém 3 variaveis, sendo elas:
 * - *pilha (ponteiro que receberá os valores que serão empilhados)
 * - topo (recebe o indice do ultimo valor da pilha)
 * - num_blocos (numero de elementos na pilha)
 *
 *  |-------------------|    |------------|
 *  |           topo:---|----|--->89.3    |2
 *  |          pilha:---|--->|    23.0    |1
 *  |     num_blocos: 3 |    |    15.6    |0
 *  |-------------------|    |------------|
 *
 * Disciplina: Estruturas de Dados Avançadas
 * Professor: MSc. Giulliano Paes Carnielli
 **************************************************************************************************/
#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

/* Inclusao de bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Constantes que definem valores gerais */
#define TAM_BLOCO 9
#define PILHA_VAZIA -1

/* Constantes definindo valores logicos */
#define TRUE 1
#define FALSE 0

/* Constantes que definem o status de uma operacao */
#define OP_OK 0
#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_INDEFINIDA -2

/*
 *Definicao da representacao do 'header' da Pilha
 */
typedef struct s_pilha {
    float *pilha;
    int topo;
    int qtd_elementos;
    int num_blocos;
} Pilha;

/*
 * Definicao das operacoes da Pilha
 */
Pilha* criaPilha();
int push(Pilha *pilha, float elemento);
int pop(Pilha *pilha, float* elemento);
int peek(Pilha *pilha, float* elemento);
int pilha_vazia(Pilha *pilha);

void imprimePilha(Pilha *pilha);

#endif // PILHA_H_INCLUDED
