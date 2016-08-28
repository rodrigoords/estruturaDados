#include "ArvoreBusca.h"

int main()
{
    ArvoreBusca *a = criaArvoreBusca();

    int status = insereElemento(a, 20);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 12);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 25);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 15);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 5);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 7);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 2);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 14);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    status = insereElemento(a, 13);
    printf("Status: %d\nNumero de nos: %d\n", status, a->num_nodes);

    /*
    int i = 0;
    int status;
    int num;
    srand(time(0));
    for (i = 0; i < 10; i++) {
        num = (rand()%100);
        status = insereElemento(a, num);
        printf("Status: %d\nInserido:%d\nNumero de nos: %d\n", status, num, a->num_nodes);
    }
    */
    percorrimentoEPD(a->raiz);

    printf("\nSoma dos elementos: %d",somarElementos(a->raiz));

    printDescRetorno(removeElemento(a, 2));
    percorrimentoEPD(a->raiz);

    printDescRetorno(removeElemento(a, 12));
    percorrimentoEPD(a->raiz);

//    getch();
    return 0;
}
