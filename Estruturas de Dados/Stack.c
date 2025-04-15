#include <stdio.h>
#include <stdlib.h>

//Create node structure
typedef struct nodeitem{
    int item;
    struct nodeitem *next;
}node;

//Create stack structure
typedef struct{
    node *top;
}stack;

//Functions declaration
int isEmpty(stack *s);
stack *createstack();
node *createNode(int value);
void push(stack *s, int value);
void pop(stack *s);
void showStack(stack *s);
int lenght(stack *s);

int main(){
    stack *s = createstack(); //Create the stack

    printf("Stack\n\n");

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    showStack(s);
    printf("Stack size: %d\n", lenght(s));
    printf("\n");

    pop(s); //Temove an element from the stack
    pop(s); //Temove an element from the stack

    showStack(s);
    printf("Stack size: %d\n", lenght(s));

}

//Functions implementation
int isEmpty(stack *s){
    if(s->top == NULL){
        return 1;
    }
    return 0;
}

stack *createstack(){
    stack *s = (stack*)malloc(sizeof(stack));

    if (s == NULL) {
        printf("Allocation Error!\n");
        exit(1);
    }

    s->top = NULL;
    return s;
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

void push(stack *s, int value){
    node *newNode = createNode(value);

    newNode->next = s->top;
    s->top = newNode;
}

void pop(stack *s){
    node *aux;

    aux = s->top;
    s->top = aux->next;
    free(aux);
}

void showStack(stack *s){
    if(isEmpty(s)){
        printf("The stack is empty!\n");
    } else {
        node *current = s->top;

        printf("Stack: ");

        while(current != NULL){
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}

int lenght(stack *s){
    int i = 0;

    if(isEmpty(s)){
        return i;
    } else {
        node *current = s->top;

        while(current != NULL){
            current = current->next;
            i++;
        }
        return i;
    }
}