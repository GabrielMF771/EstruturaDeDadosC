#include <stdio.h>
#include <locale.h>

#define TAMANHO 10

// Função para mesclar dois subarrays em ordem crescente
void merge(int vet[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;  // Tamanho do subarray esquerdo
    int n2 = direita - meio;       // Tamanho do subarray direito

    // Cria arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vet[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    // Mescla os arrays temporários de volta para vet[esquerda..direita]
    i = 0;  // Índice inicial do subarray esquerdo
    j = 0;  // Índice inicial do subarray direito
    k = esquerda;  // Índice inicial do subarray mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }
}

// Função para implementar o Merge Sort
void mergesort(int vet[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Encontra o ponto médio para dividir o array em duas metades
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira e a segunda metade
        mergesort(vet, esquerda, meio);
        mergesort(vet, meio + 1, direita);

        // Mescla as duas metades ordenadas
        merge(vet, esquerda, meio, direita);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int vet[TAMANHO] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i;
    
    printf("Merge Sort\n\n");
    
    printf("Vetor antes da ordenação: ");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");

    mergesort(vet, 0, TAMANHO - 1);

    printf("\nVetor após a ordenação: ");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");
    
    return 0;
}
