#include <stdio.h>
#include <locale.h>

#define TAMANHO 10

// Função para implementar o Selection Sort
void selectionsort(int vet[], int tam) {
    int i, j, min_idx, aux;

    for (i = 0; i < tam - 1; i++) {
        min_idx = i; // Inicialmente assume que o menor é o primeiro da sequência
        for (j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min_idx]) {
                min_idx = j; // Atualiza o índice do menor valor
            }
        }
        // Faz a troca do menor elemento encontrado com o primeiro elemento da sequência
        if (min_idx != i) {
            aux = vet[min_idx];
            vet[min_idx] = vet[i];
            vet[i] = aux;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[TAMANHO] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i;
    
    printf("Selection Sort\n\n");
    
    printf("Vetor antes da ordenação: ");
    for(i = 0; i < TAMANHO; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    selectionsort(vet, TAMANHO);

    printf("\nVetor após a ordenação: ");
    for(i = 0; i < TAMANHO; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
    
    return 0;
}
