#include "ArvoreBusca.h"

/* Funções internas*/
ArvoreNode* cria_node(int elemento, ArvoreNode *pai);
int cria_filho(ArvoreNode* node, int elemento);
int busca_referencia(ArvoreNode **node, int elemento);
void busca_ultima_referencia_direira(ArvoreNode **node);
void busca_ultima_referencia_esquerda(ArvoreNode **node);
int remover(ArvoreNode *elem_a_deletar);
void percorreIN(ArvoreNode* node);
void percorrePDE(ArvoreNode* node);
void percorreDEP(ArvoreNode* node);
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

int insere_abb(ArvoreBusca *a, int elemento){
    int status = OP_OK;
    if(a != NULL){
        if(a->raiz == NULL){
            a->raiz = cria_node(elemento, a->raiz);
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

int remove_abb(ArvoreBusca *a, int elem){
    int status = OP_OK;
    if(a != NULL){

        if(a->raiz->info == elem &&
            a->raiz->dir == NULL &&
             a->raiz->esq == NULL){
                free(a->raiz);
                a->raiz = NULL;
        }else{
            ArvoreNode *elem_a_deletar = a->raiz;
            status = busca_referencia(&elem_a_deletar, elem);
            if (status == OP_OK){
                status = remover(elem_a_deletar);
            }
        }

    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }

    return status;
}

int remover(ArvoreNode *elem_a_deletar){
    int status = OP_OK;
    ArvoreNode *aux = NULL;

    if(elem_a_deletar->esq != NULL){
        aux = elem_a_deletar->esq;
        busca_ultima_referencia_direira(&aux);
        elem_a_deletar->info = aux->info;
        remover(aux);

    }else if(elem_a_deletar->dir != NULL){
        aux = elem_a_deletar->dir;
        busca_ultima_referencia_esquerda(&aux);
        elem_a_deletar->info = aux->info;
        remover(aux);
    }else{
        if (elem_a_deletar->pai->dir != NULL && elem_a_deletar->pai->dir->info == elem_a_deletar->info){
            elem_a_deletar->pai->dir = NULL;
        }else{
            elem_a_deletar->pai->esq = NULL;
        }
        free(elem_a_deletar);
    }

    return status;
}

int percorre_in(ArvoreBusca *a){
    int status = OP_OK;
    if(a != NULL){
        if(a->raiz != NULL){
            percorreIN(a->raiz);
        }else{
            status = ERR_NODE_INDEFINIDO;
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

void busca_ultima_referencia_direira(ArvoreNode **node){
    if(*node != NULL && (*node)->dir != NULL){
        *node = (*node)->dir;
        busca_ultima_referencia_direira(node);
    }
    return;
}

void busca_ultima_referencia_esquerda(ArvoreNode **node){
    if(*node != NULL && (*node)->esq != NULL){
        *node = (*node)->esq;
        busca_ultima_referencia_esquerda(node);
    }
    return;
}

/*Função auxiliar para criar um node.*/
ArvoreNode* cria_node(int elemento, ArvoreNode *pai){
    ArvoreNode* novo_node = (ArvoreNode*)malloc(sizeof(ArvoreNode));
    novo_node->pai = pai;
    novo_node->info = elemento;
    novo_node->esq = NULL;
    novo_node->dir = NULL;
    return novo_node;
}

int cria_filho(ArvoreNode* node, int elemento){
    int status = OP_OK;
    if(node!=NULL){
        if(node->info < elemento){
            node->dir = cria_node(elemento, node);
        } else if(node->info > elemento){
            node->esq = cria_node(elemento, node);
        }else{
            status = ERR_ELEM_DUPLICADO;
        }
    }else{
        status = ERR_NODE_INDEFINIDO;
    }
    return status;
}

void percorreIN(ArvoreNode* node){
    if(node->dir != NULL){
        percorreIN(node->dir);
    }
    printf("%d\n", node->info);
    if(node->esq != NULL){
        percorreIN(node->esq);
    }
}

void percorrePDE(ArvoreNode* node){
    printf("%d", node->info);
    if(node->dir != NULL){
        percorrePDE(node->dir);
    }
    if(node->esq != NULL){
        percorrePDE(node->esq);
    }
    return;
}

void percorreDEP(ArvoreNode* node){
    if(node->dir != NULL){
        percorrePDE(node->dir);
    }
    if(node->esq != NULL){
        percorrePDE(node->esq);
    }
    printf("%d", node->info);
    return;
}
