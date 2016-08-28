#include "ArvoreBusca.h"

/***** Opera��es internas *****/
/* Cria um Node da �rvore */
ArvoreNode* criaArvoreNode(int elem) {
    ArvoreNode *an = (ArvoreNode*)malloc(sizeof(ArvoreNode));
    if (an != NULL) {
        an->dir  = NULL;
        an->esq  = NULL;
        an->info = elem;
    }
    return an;
}

/* Fun��o que procura elemento na �rvore */
int buscaElemento(ArvoreNode **an, int elem) {
    int status = ERR_ELEM_NAO_ENCONTRADO;
    if (*an != NULL) {
        if ((*an)->info == elem) {
            status = OP_OK;
        } else if ((*an)->info > elem) {
            if ((*an)->esq != NULL) {
                *an = (*an)->esq;
                status = buscaElemento(an, elem);
            }
        } else {
            if ((*an)->dir != NULL) {
                *an = (*an)->dir;
                status = buscaElemento(an, elem);
            }
        }
    } else {
        status = ERR_NODE_INDEFINIDO;
    }
    return status;
}

/* Fun��o que insere um elemento no n� apontado, de forma coerente */
int criaNodeFilho(ArvoreNode *an, int elem) {
    int status = OP_OK;
    if (an != NULL) {
        if (an->info != elem) {
            ArvoreNode *new_an = criaArvoreNode(elem);
            if (new_an != NULL) {
                if (elem > an->info) {
                    an->dir = new_an;
                } else {
                    an->esq = new_an;
                }
            } else {
                status = ERR_MEM_INSUFICIENTE;
            }
        } else {
            status = ERR_ELEM_DUPLICADO;
        }
    } else {
        status = ERR_NODE_INDEFINIDO;
    }
    return status;
}

void buscaElementoParaRemocao(ArvoreNode **an){
    if ((*an)->dir != NULL){
        *an = (*an)->dir;
        buscaElementoParaRemocao(an);
    }else if ((*an)->esq != NULL){
        *an = (*an)->esq;
        buscaElementoParaRemocao(an);
    }
}

void ajustaUltimoElemento( ArvoreNode *an ,ArvoreNode *node){
    
    if (an != NULL){
        
        if ( an->dir == node){

            an->dir = NULL;

        }else if( an->esq == node){

            an->esq = NULL;
            
        }else{
            ajustaUltimoElemento(an->esq, node);
            ajustaUltimoElemento(an->dir, node);
        }

    }

}

/***** Opera��es p�blicas *****/
/* Opear��o que cria um �rvore de Busca vazia */
ArvoreBusca* criaArvoreBusca() {
    ArvoreBusca *a = (ArvoreBusca*)malloc(sizeof(ArvoreBusca));
    if (a != NULL) {
        a->raiz = NULL;
        a->num_nodes = 0;
    }
    return a;
}

int somarElementos(ArvoreNode *a){
    int ret = 0;
    if (a != NULL) {
        ret = a-> info;
        ret += somarElementos(a->esq);
        ret += somarElementos(a->dir);
    }
    return ret;
}

void percorrimentoPED(ArvoreNode *a) {
    if (a != NULL) {
        printf("%d\t", a->info);
        percorrimentoPED(a->esq);
        percorrimentoPED(a->dir);
    }
}

void percorrimentoEPD(ArvoreNode *a) {
    if (a != NULL) {
        percorrimentoEPD(a->esq);
        printf("%d\t", a->info);
        percorrimentoEPD(a->dir);
    }
}

void percorrimentoEDP(ArvoreNode *a) {
    if (a != NULL) {
        percorrimentoEDP(a->esq);
        percorrimentoEDP(a->dir);
        printf("%d\t", a->info);
    }
}

/* Insere elemento na �rvore de Busca */
int insereElemento(ArvoreBusca *a, int elem) {
    int status = OP_OK;
    ArvoreNode *an = NULL;
    if (a != NULL) {
            /* �rvore Vazia */
            if (a->raiz == NULL) {
                an = criaArvoreNode(elem);
                if (an != NULL) {
                    a->raiz = an;
                } else {
                    status = ERR_MEM_INSUFICIENTE;
                }
            } else {
                /* �rvore j� possui elementos */
                ArvoreNode *aux_an = a->raiz;
                int busca_status = buscaElemento(&aux_an, elem);
                if (busca_status == ERR_ELEM_NAO_ENCONTRADO) {
                    /* Se elemento n�o foi encontrado aux_an aponta para o pai */
                    status = criaNodeFilho(aux_an, elem);
                } else if (busca_status == OP_OK){
                    status = ERR_ELEM_DUPLICADO;
                } else {
                    status = busca_status;
                }
            }
            if (status == OP_OK) {
                a->num_nodes++;
            }
    } else {
        status = ERR_ARVORE_INDEFINIDA;
    }
    return status;
}

int removeElemento(ArvoreBusca *a, int elem){
    int status;
    if (a != NULL){
        ArvoreNode *aux_an = a->raiz;
        status = buscaElemento(&aux_an, elem);

        if ( status == OP_OK ){
            ArvoreNode *auxB_an = aux_an;

            buscaElementoParaRemocao(&auxB_an);
            int box = auxB_an->info;

            auxB_an -> dir = NULL;
            auxB_an -> esq = NULL;
            auxB_an -> info = NULL;

            ajustaUltimoElemento(a->raiz, auxB_an);

            free(auxB_an);

            aux_an -> info = box;

        }
    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }

    return status;
}


void printDescRetorno(int status){
    if (status == OP_OK ){
        printf("\nOP_OK\n");
    }else if(status == ERR_ELEM_NAO_ENCONTRADO){
        printf("\nERR_ELEM_NAO_ENCONTRADO\n");
    }else if(status == ERR_MEM_INSUFICIENTE){
        printf("\nERR_MEM_INSUFICIENTE\n");
    }else if(status == ERR_ARVORE_INDEFINIDA){
        printf("\nERR_ARVORE_INDEFINIDA\n");
    }else if(status == ERR_NODE_INDEFINIDO){
        printf("\nERR_NODE_INDEFINIDO\n");
    }else if(status == ERR_ELEM_DUPLICADO){
        printf("\nERR_ELEM_DUPLICADO\n");
    }
}