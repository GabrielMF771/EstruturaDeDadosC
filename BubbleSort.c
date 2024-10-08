#include <stdio.h>
#include <locale.h>

#define TAMANHO 10

void bubblesort(int vet[], int tam){
    int i, j, aux;

    for(i = 0 ; i < tam - 1 ; i++){
        for(j = 0 ; j < tam - i - 1 ; j++){
            if(vet[j] > vet[j + 1]){
                aux = vet[j + 1];
                vet[j + 1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int vet[TAMANHO] = {10,9,8,7,6,5,4,3,2,1}, i;
    
    printf("Vetor antes da ordenação: ");
    for(i = 0 ; i < TAMANHO ; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    bubblesort(vet, TAMANHO);

    printf("\nVetor após a ordenação: ");
    for(i = 0 ; i < TAMANHO ; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
    
    return 0;
}