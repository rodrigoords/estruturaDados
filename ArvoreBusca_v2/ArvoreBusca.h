#ifndef ARVOREBUSCA_H_INCLUDED
#define ARVOREBUSCA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/* Constantes que definem o status de uma operacao */
#define OP_OK 0
#define FALSE 0
#define TRUE 1
#define ERR_ELEM_NAO_ENCONTRADO -1
#define ERR_ARVORE_VAZIA -2
#define ERR_ARVORE_INDEFINIDA -3
#define ERR_NODE_INDEFINIDO -4
#define ERR_ELEM_DUPLICADO -5

/* Arvore Node */
typedef struct s_arvore_node {
    struct s_arvore_node *pai;
    struct s_arvore_node *esq;
    struct s_arvore_node *dir;
    int info;
} ArvoreNode;

/* Arvore de Busca (Header) */
typedef struct s_arvore_busca {
    int num_nodes;
    ArvoreNode *raiz;
} ArvoreBusca;

/* Operações do TAD Arvore de Busca */
ArvoreBusca* cria_abb();
int insere_abb(ArvoreBusca *a, int elem);
int remove_abb(ArvoreBusca *a, int elem);
int busca_abb(ArvoreBusca *a, int elem, ArvoreNode** referencia);
int percorre_pre(ArvoreBusca *a);
int percorre_in(ArvoreBusca *a);
int percorre_pos(ArvoreBusca *a);
int abb_vazia();


/* For debugging */
int mostraArvoreCompleta (ArvoreBusca *arvore, int col, int lin, int desloc);

#endif // ARVOREBUSCA_H_INCLUDED
