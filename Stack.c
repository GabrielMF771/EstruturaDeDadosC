#include <stdio.h>
#include <stdlib.h>

//Cria a estrutura do nó
typedef struct nodeitem{
    int item;
    struct nodeitem *next;
}node;

//Cria a estrutura da pilha
typedef struct{
    node *top;
}stack;

//Declarações
int isEmpty(stack *s);
stack *createstack();
node *createNode(int value);
void push(stack *s, int value);
void pop(stack *s);
void showStack(stack *s);
int lenght(stack *s);

int main(){
    stack *s = createstack(); //Cria a pilha

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);

    showStack(s);
    printf("Tamanho atual da pilha: %d\n", lenght(s));
    printf("\n");

    pop(s); //Remove um elemento da pilha
    pop(s); //Remove um elemento da pilha

    showStack(s);
    printf("Tamanho atual da pilha: %d\n", lenght(s));

}

//Funções
int isEmpty(stack *s){
    if(s->top == NULL){
        return 1;
    }
    return 0;
}

stack *createstack(){
    stack *s = (stack*)malloc(sizeof(stack));

    if (s == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    s->top = NULL;
    return s;
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
        printf("Pilha Vazia!\n");
    } else {
        node *current = s->top;

        printf("Pilha: ");

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