/***************************************************************************************************
 * C File: pilha.c
 * Implementa as fun��es da TAD pilha.
 *
 * Disciplina: Estruturas de Dados Avan�adas
 * Professor: MSc. Giulliano Paes Carnielli
 **************************************************************************************************/

#include "Pilha.h"

/**
  * @function criaPilha()
  * @description Cria uma Pilha vazia (topo aponta para NULL).
  * @param ---
  * @return pilha (Referencia para nova estrutura Pilha alocada.)
  */
Pilha* criaPilha()
{
    // Aloca espa�o para a estrutura da pilha
    Pilha *nova_pilha = (Pilha *)malloc(sizeof(Pilha));

    // Aloca espa�o para o 1� bloco da pilha
    nova_pilha->pilha =  (float *)calloc(TAM_BLOCO, sizeof(float));

    //
    nova_pilha->topo = PILHA_VAZIA;
    nova_pilha->qtd_elementos = 0;
    nova_pilha->num_blocos = 1;
    return nova_pilha;
}

/**
  * @function push()
  * @descricao Faz o empilhamento dos valores, sempre adicionando um novo elemento no topo da pilha.
  * @param
  *   a. Pilha *pilha: pilha na qual um novo elemento sera empilhado
  *   b. float elemento: elemento que sera empilhado na pilha
  *
  * @return status da operacao
  *   a. OP_OK (Se o elemento for empilhado com sucesso)
  *   b. ERRO_PILHA_INDEFINIDA (Se a referencia para Pilha seja nula)
  */
int push(Pilha *pilha, float elemento)
{
    int status = OP_OK;
    /* Verifica se a pilha existe */
    if (pilha != NULL)
    {
        if ( (TAM_BLOCO * pilha->num_blocos) <= pilha->qtd_elementos){
            pilha->pilha = (float *) realloc(pilha->pilha, TAM_BLOCO * sizeof(float));
            pilha->num_blocos = pilha->num_blocos + 1;
        }
        pilha->topo = pilha->topo + 1;
        pilha->pilha[pilha->topo] = elemento;
        pilha->qtd_elementos = pilha->qtd_elementos +1;
    }
    else
    {
        /* Pilha Indefinida */
        status = ERRO_PILHA_INDEFINIDA;
    }

    return status;

}


int peek(Pilha *pilha, float* elemento){
    int status = OP_OK;
    if(pilha == NULL){
        status = ERRO_PILHA_INDEFINIDA;
    }else if(pilha->topo == PILHA_VAZIA){
        status = ERRO_PILHA_VAZIA;
    }else{
        elemento = &pilha->pilha[pilha->topo];
    }
    return status;
}

void imprimePilha(Pilha *pilha){
    int i;
    for(i = pilha->topo; i >= 0 ; i--){
        printf("%f\n", pilha->pilha[i]);
    }
    return;
}
