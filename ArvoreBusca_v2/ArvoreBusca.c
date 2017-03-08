#include "ArvoreBusca.h"

/* Funções internas*/
int busca_referencia(ArvoreNode **node, int elemento);
ArvoreNode* cria_node(int elemento);
int cria_filho(ArvoreNode* node, int elemento);
int percorrePDE(ArvoreNode* node);
int percorrePED(ArvoreNode* node);
int percorreIN(ArvoreNode* node);
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

int busca_abb(ArvoreBusca* a, int elem, ArvoreNode** referencia){
    int status = OP_OK;
    *referencia = NULL;
    if(a != NULL){
        if(a->raiz != NULL){
            ArvoreNode *aux = a->raiz;
            status = busca_referencia(&aux, elem);
            *referencia = (status == OP_OK) ? aux : NULL;
        }else{
            status = ERR_ARVORE_VAZIA;
        }
    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }
    return status;
}



/*Funções internas Implementações*/
int busca_referencia(ArvoreNode **node, int elemento){

    int status = ERR_ELEM_NAO_ENCONTRADO;

    if(node != NULL && *node != NULL){

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

int insere_abb(ArvoreBusca *a, int elemento){
    int status = OP_OK;
    if(a != NULL){
        if(a->raiz == NULL){
            a->raiz = cria_node(elemento);
        }else{
            ArvoreNode *aux = a->raiz;
            if(busca_referencia(&aux, elemento) == ERR_ELEM_NAO_ENCONTRADO){
                status = cria_filho(aux, elemento);
            }else{
                status = ERR_ELEM_DUPLICADO;
            }
        }

        if(status == OP_OK){
            a->num_nodes++;
        }
    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }

    return status;
}

/*Função auxiliar para criar um node.*/
ArvoreNode* cria_node(int elemento){
    ArvoreNode* novo_node = (ArvoreNode*)malloc(sizeof(ArvoreNode));
    novo_node->info = elemento;
    novo_node->esq = NULL;
    novo_node->dir = NULL;
    return novo_node;
}

int cria_filho(ArvoreNode* node, int elemento){
    int status = OP_OK;
    if(node!=NULL){
        if(node->info < elemento){
            node->dir = cria_node(elemento);
        } else if(node->info > elemento){
            node->esq = cria_node(elemento);
        }else{
            status = ERR_ELEM_DUPLICADO;
        }
    }else{
        status = ERR_NODE_INDEFINIDO;
    }
    return status;
}

