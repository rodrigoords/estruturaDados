#include "ArvoreBusca.h"

/* Funções internas*/
int busca_referencia(ArvoreNode **node, int elemento);
/*******************************************/

ArvoreBusca* cria_abb(){
    ArvoreBusca *abb = (ArvoreBusca*) malloc(sizeof(ArvoreBusca));
    abb->raiz = NULL;
    abb->num_nodes = 0;

    return abb;
}

int abb_vazia(ArvoreBusca *a){

    return (a != NULL && a->num_nodes > 0) ? FALSE : TRUE;

}

/*Funções internas Implementações*/
int busca_referencia(ArvoreNode **node, int elemento){

    int status = ERR_ELEM_NAO_ENCONTRADO;

    if(node != NULL &&
       *node != NULL){

        if ((*node)->info > elemento){
            if((*node)->esq != NULL){
                *node = (*node)->esq;
                status = busca_referencia(node, elemento);
            }
        }else if((*node)->info < elemento){
            if((*node)->dir){
                *node = (*node)->dir;
                status = busca_referencia(node, elemento);
            }
        }else{
            status = OP_OK;
        }

    }else{
        status = ERR_NODE_INDEFINIDO;
    }

    return status;
}
