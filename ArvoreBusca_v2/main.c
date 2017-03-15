#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBusca.h"

int main()
{
    ArvoreBusca *arvore = cria_abb();
    if(abb_vazia() == TRUE){
        printf("Arvore Vazia\n");
    }else{
        printf("Arvore com valores\n");
    }

    insere_abb(arvore, 43);
    insere_abb(arvore, 71);
    insere_abb(arvore, 67);
    insere_abb(arvore, 73);
    insere_abb(arvore, 59);

    insere_abb(arvore, 33);
    insere_abb(arvore, 19);
    insere_abb(arvore, 34);
    insere_abb(arvore, 12);
    insere_abb(arvore, 23);
    insere_abb(arvore, 37);
    insere_abb(arvore, 31);
    insere_abb(arvore, 35);
    insere_abb(arvore, 38);
    printf("Arvode antes remoção \n");
    percorre_in(arvore);

    remove_abb(arvore, 43);
    printf("Arvode após remoção - 43\n");
    percorre_in(arvore);

    remove_abb(arvore, 71);
    printf("Arvode após remoção - 71\n");
    percorre_in(arvore);
    return 0;
}
