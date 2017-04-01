#include "ArvoreBusca.h"

/* Fun��es internas*/
ArvoreNode* cria_node(int elemento, ArvoreNode *pai);
int cria_filho(ArvoreNode* node, int elemento);
int busca_referencia(ArvoreNode **node, int elemento);
void busca_ultima_referencia_direita(ArvoreNode **node);
void busca_ultima_referencia_esquerda(ArvoreNode **node);
int remover(ArvoreNode **a, int elem_a_deletar);
void percorreIN(ArvoreNode* node);
void percorrePDE(ArvoreNode* node);
void percorreDEP(ArvoreNode* node);
void reajustaArvore(ArvoreNode **a);
int calcFB(ArvoreNode *n);
int altNode(ArvoreNode *node);
void rotacao_RR(ArvoreNode **node_A);
void rotacao_LL(ArvoreNode **node_A);
void rotacao_LR(ArvoreNode **node_A);
void rotacao_RL(ArvoreNode **node_A);
int maior(int a, int b);
int insere(ArvoreNode ** a, int elem);
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
    if (a != NULL) {
            /* �rvore Vazia */
            if (a->raiz == NULL) {
                a->raiz = cria_node(elemento, a->raiz);
            } else {
                /* �rvore j� possui elementos */
                status = insere(&(a->raiz), elemento);
            }
            if (status == OP_OK) {
                a->num_nodes++;
            }
    } else {
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
            status = remover(&(a->raiz), elem);
        }

    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }

    return status;
}


/*
Percorre uma arvore imprimindo no console o valor para o usuario, de forma que a impress�o aconte�a entre o percorrimento dos
filhos direitos e esquedo.
*/
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
Percorre uma arvore imprimindo no console o valor para o usuario, de forma que a impress�o aconte�a antes do percorrimento dos
filhos direitos e esquedo.
*/
int percorre_pre(ArvoreBusca *a){
    int status = OP_OK;
    if(a != NULL){
        if(a->raiz != NULL){
            percorrePDE(a->raiz);
        }else{
            status = ERR_NODE_INDEFINIDO;
        }
    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }
    return status;
}

/*
Percorre uma arvore imprimindo no console o valor para o usuario, de forma que a impress�o aconte�a ap�s o percorrimento dos
filhos direitos e esquedo.
*/
int percorre_pos(ArvoreBusca *a){
    int status = OP_OK;
    if(a != NULL){
        if(a->raiz != NULL){
            percorreDEP(a->raiz);
        }else{
            status = ERR_NODE_INDEFINIDO;
        }
    }else{
        status = ERR_ARVORE_INDEFINIDA;
    }
    return status;
}

/*Fun��es internas Implementa��es*/
int insere(ArvoreNode **a, int elem) {
    int status = OP_OK;

    if ((*a)->info > elem) {
        if ((*a)->esq != NULL) {
            status = insere(&((*a)->esq), elem);
        } else {
            /* Encontrei ponto de inser��o � esquerda */
            (*a)->esq = cria_node(elem, *a);
        }
    } else if ((*a)->info < elem) {
        if ((*a)->dir != NULL) {
            status = insere(&((*a)->dir), elem);
        } else {
            /* Encontrei ponto de inser��o � direita */
            (*a)->dir = cria_node(elem, *a);
        }
    } else {
        status = ERR_ELEM_DUPLICADO;
    }

    if (status == OP_OK) {
      reajustaArvore(a);
    }
    return status;
}
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
int remover(ArvoreNode **a, int elem_a_deletar) {
    int status = OP_OK;
    ArvoreNode *aux = NULL;

    if ((*a)->info > elem_a_deletar) {
        if ((*a)->esq != NULL) {
            status = remover(&((*a)->esq), elem_a_deletar);
        } else {
            status = ERR_ELEM_NAO_ENCONTRADO;
        }
    } else if ((*a)->info < elem_a_deletar) {
        if ((*a)->dir != NULL) {
            status = remover(&((*a)->dir), elem_a_deletar);
        } else {
            status = ERR_ELEM_NAO_ENCONTRADO;
        }
    } else {
        if((*a)->esq != NULL){
            aux = (*a)->esq;
            busca_ultima_referencia_direita(&aux);
            (*a)->info = aux->info;
            status = remover(&((*a)->esq), aux->info);

        }else if((*a)->dir != NULL){
            aux = (*a)->dir;
            busca_ultima_referencia_esquerda(&aux);
            (*a)->info = aux->info;
            status = remover(&((*a)->dir), aux->info);
        }else{
            if ((*a)->pai->dir != NULL && (*a)->pai->dir->info == (*a)->info){
                (*a)->pai->dir = NULL;
            }else{
                (*a)->pai->esq = NULL;
            }
            free((*a));
            return status; // Ap�s liberar a mem�ria eu n�o tenho mais um node para trabalhar, n�o existe a necessidade
                           // de realizar um reajuste, por isso o retun nesse ponto, a recurs�o ir� recalcular do node acima.
        }
    }

    if (status == OP_OK) {
        reajustaArvore(a);
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
void busca_ultima_referencia_direita(ArvoreNode **node){
    if(*node != NULL && (*node)->dir != NULL){
        *node = (*node)->dir;
        busca_ultima_referencia_direita(node);
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
    novo_node->alt = 0;
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
/*
Fun��o interna para percorrer uma arvore e mostrar o conteudo de cada no de acordo com a seguinte regra:
 Percorre primeiro o n� a direita, e antes de ir ao n� a esqueda mostra o valor do node, depois percorre a arvore a esquerda.
*/
void percorreIN(ArvoreNode* node){
    if(node->dir != NULL){
        percorreIN(node->dir);
    }
    printf("info: %d | pai: %d\n", node->info, node->pai != NULL ? node->pai->info : 0);
    if(node->esq != NULL){
        percorreIN(node->esq);
    }
    return;
}

/*
Fun��o interna para percorrer uma arvore e mostrar o conteudo de cada no de acordo com a seguinte regra:
 Antes de percorrer a arvore mostra o valor do node, depois percorre a arvore pelo filho direito e quando chegar ao final
 percorre pelo filho esquerdo.
*/
void percorrePDE(ArvoreNode* node){
    printf("%d\n", node->info);
    if(node->dir != NULL){
        percorrePDE(node->dir);
    }
    if(node->esq != NULL){
        percorrePDE(node->esq);
    }
    return;
}

/*
Fun��o interna para percorrer uma arvore e mostrar o conteudo de cada no de acordo com a seguinte regra:
 Percorre a arvore pelo filho direito e quando chegar ao final percorre pelo filho esquerdo ap�s percorrer
 os dois caminhos mostra a informa�o do node.
*/
void percorreDEP(ArvoreNode* node){
    if(node->dir != NULL){
        percorreDEP(node->dir);
    }
    if(node->esq != NULL){
        percorreDEP(node->esq);
    }
    printf("%d\n", node->info);
    return;
}

int maior(int a, int b) {
    return (a > b)? a : b;
}

/*
RR Rotation
             *****                       *****
            |  A  |                     |  B  |
             *****                       *****
           /                          /        \
        *****                      *****      *****
       |  B  |       ====>        |  C  |    |  A  |
        *****                      *****      *****
        /
     *****
    | C   |
     *****
*/
void rotacao_RR(ArvoreNode **node_A) {
    ArvoreNode *node_B = (*node_A)->esq;
    (*node_A)->esq = node_B->dir;

    if(node_B->dir != NULL)
        node_B->dir->pai = (*node_A);

    node_B->dir = (*node_A);

    node_B->pai = (*node_A)->pai;
    (*node_A)->pai = node_B;

    (*node_A)->alt = maior(altNode((*node_A)->esq),
                           altNode((*node_A)->dir)) + 1;
    node_B->alt = maior(altNode(node_B->esq),
                        altNode(node_B->dir)) + 1;

    *node_A = node_B;
}

/*
LL Rotation
 *****                                *****
|  A  |                              |  B  |
 *****                                *****
        \                          /        \
        *****                    *****      *****
       |  B  |      ====>       |  A  |    |  C  |
        *****                    *****      *****
				\
			   *****
			  |  C  |
			   *****
*/
void rotacao_LL(ArvoreNode **node_A) {
    ArvoreNode *node_B = (*node_A)->dir;
    (*node_A)->dir = node_B->esq;

    if(node_B->esq != NULL)
        node_B->esq->pai = (*node_A);

    node_B->esq = (*node_A);

    node_B->pai = (*node_A)->pai;
    (*node_A)->pai = node_B;

    (*node_A)->alt = maior(altNode((*node_A)->esq),
                           altNode((*node_A)->dir)) + 1;
    node_B->alt = maior(altNode(node_B->esq),
                        altNode(node_B->dir)) + 1;

    *node_A = node_B;
}

/*
LR Rotation
 *****                                *****
|  A  |                              |  C  |
 *****                                *****
        \                          /        \
        *****                    *****      *****
       |  B  |  ====>           |  A  |    |  B  |
        *****                    *****      *****
	  /
 *****
|  C  |
 *****
*/
void rotacao_LR(ArvoreNode **node_A) {
    rotacao_LL(&((*node_A)->esq));
    rotacao_RR(node_A);

}

/*
RL Rotation
		 *****                        *****
		|  A  |                      |  C  |
		 *****                        *****
       /                           /        \
 *****                          *****      *****
|  B  |           ====>        |  B  |    |  A  |
 *****                          *****      *****
	   \
		 *****
		|  C  |
		 *****
*/
void rotacao_RL(ArvoreNode **node_A) {
    rotacao_RR(&((*node_A)->dir));
    rotacao_LL(node_A);
}

/* Calcula o Fator de Balanceamento de um node */
int calcFB(ArvoreNode *n){
    int fb = (n != NULL)? altNode(n->esq) - altNode(n->dir) : 0;
    return fb;
}

/* Retorna a altura de um Node */
int altNode(ArvoreNode *node){
  return (node != NULL)? node->alt : -1;
}

void reajustaArvore(ArvoreNode **a){
    int fb = calcFB(*a);
    if (fb > 1) {
        /* Desbalanceado � esquerda A(+2)*/
        if (calcFB((*a)->esq) > 0) {
            /* Rota��o RR: B(+1)*/
            rotacao_RR(a);
        } else {
            /* Rota��o LR: B(-1)*/
            rotacao_LR(a);
        }
    } else if (fb < -1) {
        /* Desbalanceado � direita A(-2) */
        if (calcFB((*a)->dir) > 0) {
            /* Rota��o RL: B(+1)*/
            rotacao_RL(a);
        } else {
            /* Rota��o LL: B(-1)*/
            rotacao_LL(a);
        }
    } else {
        (*a)->alt = maior(altNode((*a)->esq),
                       altNode((*a)->dir)) + 1;
    }
}
