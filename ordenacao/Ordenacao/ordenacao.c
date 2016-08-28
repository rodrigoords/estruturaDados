
void switchVetor(int vet[], int posA, int posB){

    int aux;

    aux       = vet[posA];
    vet[posA] = vet[posB];
    vet[posB] = aux;
}

int valorMedia(int a, int b, int c){
    int ret;

    if (a >= b){
        if(a <= c){
            ret = a;
        }else{
            if( b >= c){
                ret = b;
            }else{
                ret = c;
            }
        }
    }else{
        if(b>=c){
            ret = c;
        }else{
            ret = b;
        }
    }
    return ret;
}

int escolhePivo(int vet[], int tam){
    int a,b,c, mediana;

    a = vet[0];
    b = vet[tam -1];
    c = vet[tam/2];

    mediana = valorMedia(a,b,c);

    if (mediana == a){
        return 0;
    }else if (mediana == b){
        return tam -1;
    }else{
        return tam/2;
    }
}

void bubbleShort(int vet[], int tam){
    int i,j;

    for (i=tam-1; i >= 1; i--){
        for (j=0; j < i; j++){
            if ( vet[j] > vet[j+1] ){
                switchVetor(vet, j, j+1);
            }
        }
    }
}

void selectionShort(int vet[], int tam){
    int menor;
    for(int i = 0; i < tam ; i++){
        menor = i;
        for (int j = i+1; j < tam; j++){
            if (vet[menor] > vet[j]){
                menor = j;
            }
        }

        switchVetor(vet, i, menor);
    }
}

void quickShort(int vet[], int inicio, int fim){

    int i = 0, j = fim;
    int pivo = escolhePivo(vet, (fim+1) - inicio );

    while(i<j){
        if(vet[i] >= vet[pivo]){
            while(j>i){
                if(vet[j] < vet[pivo]){
                    switchVetor(vet, i, j);
                    break;
                }
                j--;
            }
        }
        i++;
    }

    if(i <= fim ){
        quickShort(vet, inicio, pivo);
    }
    if(j > inicio){
        quickShort(vet, pivo, fim);
    }

}


