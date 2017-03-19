#include "ArvoreBusca.h"

/* Fun��es internas*/
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

/*
 Cria uma estrutura de arvore que serve como Header. Como est� sendo criada n�o existe uma raiz
 por isso nasce como null. 
 O mesmo vale para o numero de nodes.
*/
ArvoreBusca* cria_abb(){
    ArvoreBusca *abb = (ArvoreBusca*) malloc(sizeof(ArvoreBusca));
    abb->raiz = NULL;
    abb->num_nodes = 0;

    return abb;
}

/*
 Verifica se a arvore est� vazia.
*/
int abb_vazia(ArvoreBusca *a){

    return (a != NULL && a->num_nodes > 0) ? FALSE : TRUE;

}

/*
 Fun��o busca um elemento da arvore de acordo com o inteiro informado, 
 caso a fun��o encontre dentro da ArvoreNode.info o elemento ser� ent�o
 retornado um ponteiro apontando para o elemento. 
 Caso n�o seja encontrado o elemento ser� retornado um ponteiro para NULL;
*/
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

/*
 Insere um novo node na arvore de acordo com as regras de uma arvore binaria.
*/
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

/*
Remove o elemento da arvore e ajusta a arvore.
    Ajuste: Caso um elemente se encontrado e removido em seu lugar ser� incluido o maior elemento que est� 
    no node a esquerda.
    Caso o elemento deletado n�o contenha um node a esquerda o ajuste ir� buscar o menor elemento do node a direita.
*/
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
/*Fun��es internas Implementa��es*/

/*
Fun��o interna que ser� chamada recursivamente para remover os nodes de uma arvore.
nela � implementada a regra de ajuste da arvore. Uma vez que um node � informado para elem_a_deletar
a l�gica busca qual o node mais a direita que est� no filho esquerdo. Caso n�o exista um node esquerdo 
ser� buscado o node mais a esquerda do filho direito.

Exemplo: Caso exista filho esquerdo:
                     **************
                    | info_Deletar |
                     **************
                   /            ^
                ***********     |
               | info_menor|    | O node info_Deletar ir� receber o valor do node info_troca ( o mais a direita abaixo do filho esquerdo)
                ***********     |
                    \           -
                     ************
                    | info_troca |
                     ************

Exemplo: Caso exista filho direito:

                     **************
                    | info_Deletar |
                     **************
                     ^              \              
                     |               ***********     
                     |              | info_menor|    | O node info_Deletar ir� receber o valor do node info_troca ( o mais a esquerda abaixo do filho direito)
                     |               ***********     
                     -             /
                     ************
                    | info_troca |
                     ************
*/
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

/*
Fun��o interna utilizada para percorrer de forma recursiva a arvore procurando no ArvoreNode.info o elemento informado.
A cada intera��o o ponteiro node � movimentado para no final caso exista o elemento procurado aponto examente para o node.
Caso o elemento n�o exista o ponteiro ser� retornado apontando para o ultimo node que teoricamente deveria ser o pai do elemento
procurado.
*/
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

/*
Dado um node de arvore a fun��o ir� retornar uma ponteiro para o ultimo elemente mais a direita.
exemplo:
    ******
   | node |
    ******
            \              
             **********     
            | node_dir |   
             ********** 
                    \              
                     ***************   
                    | node_mais_dir | --> Ser� retornado uma referencia para esse ArvoreNode;   
                     *************** 
*/
void busca_ultima_referencia_direira(ArvoreNode **node){
    if(*node != NULL && (*node)->dir != NULL){
        *node = (*node)->dir;
        busca_ultima_referencia_direira(node);
    }
    return;
}

/*
                     ******
                    | node |
                     ******
                   /            
                **********     
               | node_esq |    
                ********** 
                /            
             ***************    
            | node_mais_esq | --> Ser� retornada uma referencia para esse objeto.    
             ***************     
*/
void busca_ultima_referencia_esquerda(ArvoreNode **node){
    if(*node != NULL && (*node)->esq != NULL){
        *node = (*node)->esq;
        busca_ultima_referencia_esquerda(node);
    }
    return;
}

/*Fun��o auxiliar para criar um node.*/
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
