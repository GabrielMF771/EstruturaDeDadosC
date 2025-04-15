#include <stdio.h>
#include <stdlib.h>

//Create node structure
typedef struct nodeitem{
    int item;
    struct nodeitem *next;
}node;

//Create list structure
typedef struct{
    node *first;
}linkedlist;

//Functions Declaration
linkedlist *createlist();
node *createNode(int value);
void addItem(linkedlist *list, int value, int pos);
void removeItem(linkedlist *list, int pos);
int isEmpty(linkedlist *list);
void showList(linkedlist *list);
int lenght(linkedlist *list);

int main(){
    linkedlist *list = createlist(); //Create a new list

    printf("Linked List\n\n");

    addItem(list,10,1);
    addItem(list,20,2);
    addItem(list,30,3);
    addItem(list,40,4);
    addItem(list,50,5);

    showList(list);
    printf("List size: %d\n", lenght(list));
    printf("\n");

    removeItem(list, 5); //Remove the last element of the list
    removeItem(list, 1); //Remove the first element of the list

    showList(list);
    printf("List size: %d\n", lenght(list));

}

//Functions implementation
linkedlist *createlist(){
    linkedlist *list = (linkedlist*)malloc(sizeof(linkedlist));

    if (list == NULL) {
        printf("Allocation Error!\n");
        exit(1);
    }

    list->first = NULL;
    return list;
}

node *createNode(int value){
    node *newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL){
        printf("Allocation Error!\n");
        exit(1);
    }

    newNode->item = value;
    newNode->next = NULL;
    return newNode;
}

void addItem(linkedlist *list, int value, int pos){
    if(pos < 1 || pos > lenght(list) + 1){
        printf("Invalid Position!\n");
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
        printf("Invalid Position!\n");
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
        printf("The list is empty!\n");
    } else {
        node *current = list->first;

        printf("List: ");

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