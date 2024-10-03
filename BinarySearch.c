#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int binarySearch(int vet[], int value, int left, int right);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int vet[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int value;
    int i;

    printf("O vetor e: {");

    for(i = 0 ; i < 9 ; i++){
        if(vet[i] == vet[8]){
            printf("%d}\n", vet[i]);
        } else{
            printf("%d, ", vet[i]);
        }
    }

    printf("Digite o número que deseja encontrar no vetor: ");
    scanf("%d", &value);
    printf("\n");

    int result = binarySearch(vet, value, 0, 8);

    if(result != -1){
        printf("O valor %d foi encontrado no vetor no índice %d.\n", value, result);
    } else {
        printf("O valor %d não foi encontrado no vetor!\n", value);
    }

    return 0;
}

int binarySearch(int vet[], int value, int left, int right){
    if(left > right){
        return -1; //Retorna erro se o valor não for encontrado no array
    }    

    int mid = (right + left) / 2; //Acha o meio do array

    if (value == vet[mid]){
        return mid;
    } else if(value > vet[mid]){
        return binarySearch(vet, value, mid + 1, right); //Busca da metade pra frente do array
    } else {
        return binarySearch(vet, value, left, mid - 1); //Busca da metade para tras do array
    }
}