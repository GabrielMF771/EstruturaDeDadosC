#include <stdio.h>
#include <locale.h>

#define TAMANHO 10

// Fun��o para implementar o Insertion Sort
void insertionsort(int vet[], int tam) {
    int i, j, chave;
    
    for (i = 1; i < tam; i++) {
        chave = vet[i];  // Armazena o valor atual a ser inserido
        j = i - 1;

        // Move os elementos maiores que a chave uma posi��o � frente
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            j--;
        }
        // Insere a chave na posi��o correta
        vet[j + 1] = chave;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[TAMANHO] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i;
    
    printf("Insertion Sort\n\n");
    
    printf("Vetor antes da ordena��o: ");
    for(i = 0; i < TAMANHO; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");

    insertionsort(vet, TAMANHO);

    printf("\nVetor ap�s a ordena��o: ");
    for(i = 0; i < TAMANHO; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
    
    return 0;
}
