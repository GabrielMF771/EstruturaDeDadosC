#include <stdio.h>
#include <locale.h>

#define TAMANHO 10

void quicksort(int vet[], int inicio, int fim) {
    int i, j, pivo, aux;

    i = inicio;
    j = fim;
    pivo = vet[(inicio + fim) / 2];  // Escolhe o pivô no meio

    while (i <= j) {
        // Encontra o elemento maior que o pivô
        while (vet[i] < pivo) {
            i++;
        }
        // Encontra o elemento menor que o pivô
        while (vet[j] > pivo) {
            j--;
        }
        // Faz a troca
        if (i <= j) {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
        }
    }

    // Recursivamente ordena os dois subarrays
    if (inicio < j) {
        quicksort(vet, inicio, j);
    }
    if (i < fim) {
        quicksort(vet, i, fim);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[TAMANHO] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i;
    
    printf("Quick Sort\n\n");
    
    printf("Vetor antes da ordenação: ");
    for(i = 0 ; i < TAMANHO ; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    quicksort(vet, 0, TAMANHO - 1);

    printf("\nVetor após a ordenação: ");
    for(i = 0 ; i < TAMANHO ; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
    
    return 0;
}
