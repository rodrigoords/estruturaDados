#ifndef ARVOREBUSCA_H_INCLUDED
#define ARVOREBUSCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>

/* Constantes que definem o status de uma operacao */
#define OP_OK 0
#define ERR_ELEM_NAO_ENCONTRADO -1
#define ERR_MEM_INSUFICIENTE -2
#define ERR_ARVORE_INDEFINIDA -3
#define ERR_NODE_INDEFINIDO -4
#define ERR_ELEM_DUPLICADO -5

/* Arvore Node */
typedef struct s_arvore_node {
    struct s_arvore_node *esq;
    int info;
    struct s_arvore_node *dir;
} ArvoreNode;

/* Arvore de Busca (Header) */
typedef struct s_arvore_busca {
    int num_nodes;
    ArvoreNode *raiz;
} ArvoreBusca;

/* Opera��es do TAD Arvore de Busca */
ArvoreBusca* criaArvoreBusca();
int insereElemento(ArvoreBusca *a, int elem);
int removeElemento(ArvoreBusca *a, int elem);

int somarElementos(ArvoreNode *a);

void percorrimentoPED(ArvoreNode *a);
void percorrimentoEPD(ArvoreNode *a);
void percorrimentoEDP(ArvoreNode *a);

void printDescRetorno(int status);

#endif // ARVOREBUSCA_H_INCLUDED
