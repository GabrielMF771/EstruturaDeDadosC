#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Cria a estrutura do nó
typedef struct nodeitem{
    int item;
    struct nodeitem *next;
}node;

//Cria a estrutura da lista
typedef struct{
    node *first;
}linkedlist;

//Declarações
linkedlist *createlist();
node *createNode(int value);
void addItem(linkedlist *list, int value, int pos);
void removeItem(linkedlist *list, int pos);
int isEmpty(linkedlist *list);
void showList(linkedlist *list);
int lenght(linkedlist *list);

int main(){
    setlocale(LC_ALL, "Portuguese");

    linkedlist *list = createlist(); //Cria a lista

    printf("Lista Encadeada\n\n");

    addItem(list,10,1);
    addItem(list,20,2);
    addItem(list,30,3);
    addItem(list,40,4);
    addItem(list,50,5);

    showList(list);
    printf("Tamanho atual da lista: %d\n", lenght(list));
    printf("\n");

    removeItem(list, 5); //Remove o último elemento da lista
    removeItem(list, 1); //Remove o primeiro elemento da lista

    showList(list);
    printf("Tamanho atual da lista: %d\n", lenght(list));

}

//Funções
linkedlist *createlist(){
    linkedlist *list = (linkedlist*)malloc(sizeof(linkedlist));

    if (list == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    list->first = NULL;
    return list;
}

node *createNode(int value){
    node *newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    newNode->item = value;
    newNode->next = NULL;
    return newNode;
}

void addItem(linkedlist *list, int value, int pos){
    if(pos < 1 || pos > lenght(list) + 1){
        printf("Posição Inválida!\n");
    }

    node *newNode = createNode(value);

    if(pos == 1){
        newNode->next = list->first;
        list->first = newNode; 
    } else {
        node *previousNode = list->first;
        
        for(int i = 1; i < pos - 1; i++){
            previousNode = previousNode->next;
        }

        newNode->next = previousNode->next;
        previousNode->next = newNode;
    }
}

void removeItem(linkedlist *list, int pos){
    if(pos < 1 || pos > lenght(list) + 1 || isEmpty(list)){
        printf("Posição Inválida!\n");
    }

    node *previousNode = list->first;

    if(pos == 1){
        list->first = previousNode->next;
        free(previousNode);
    } else {
        for(int i = 1; i < pos - 1; i++){
            previousNode = previousNode->next;
        }

        node *aux = previousNode->next;
        previousNode->next = aux->next;
        free(aux);
    }

}

int isEmpty(linkedlist *list){
    if(list->first == NULL){
        return 1;
    }
    return 0;
}

void showList(linkedlist *list){
    if(isEmpty(list)){
        printf("Lista Vazia!\n");
    } else {
        node *current = list->first;

        printf("Lista: ");

        while(current != NULL){
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}

int lenght(linkedlist *list){
    int i = 0;

    if(isEmpty(list)){
        return i;
    } else {
        node *current = list->first;

        while(current != NULL){
            current = current->next;
            i++;
        }
        return i;
    }
}