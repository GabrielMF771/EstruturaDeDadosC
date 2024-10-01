#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int top;
    int capacity;
    int *elements;
} Stack;

void initializeStack(Stack *s, int initialCapacity);
void resizeStack(Stack *s);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
void freeStack(Stack *s);
void printStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

int main(){
    setlocale(LC_ALL, "Portuguese");

    Stack s;
    initializeStack(&s, 2);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30); //Redimensiona a pilha.

    printStack(&s); //Imprime a pilha.
    printf("Topo da pilha: %d\n", peek(&s));

    pop(&s);
    printf("\nUm elemento foi removido\n");

    printf("\n");
    printStack(&s);
    printf("Topo da pilha ap�s a remo��o: %d\n", peek(&s));

    //Liberando a mem�ria da pilha.
    freeStack(&s);

    return 0;
}

void initializeStack(Stack *s, int initialCapacity) {
    if (s == NULL) {
        printf("Ponteiro inválido!\n");
        exit(1);
    }

    s->top = -1;
    s->capacity = initialCapacity;
    s->elements = (int*) malloc(initialCapacity * sizeof(int));

    if (s->elements == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }
}

void resizeStack(Stack *s) {
    int *newElements = (int*) realloc(s->elements, s->capacity * 2 * sizeof(int));
    if (newElements == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    s->elements = newElements;
    s->capacity *= 2;
}

int isStackFull(Stack *s) {
    return (s->top == s->capacity - 1);  // Se o topo for o último índice, a pilha está cheia.
}

int isStackEmpty(Stack *s) {
    return (s->top == -1); // Se o topo for -1, a pilha está vazia.
}

void freeStack(Stack *s) {
    free(s->elements);
    s->elements = NULL;
    s->top = -1;
    s->capacity = 0;
}

void printStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("\nA pilha está vazia!\n\n");
    } else {
        printf("Pilha: { ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->elements[i]);
        }
        printf("}\n");
    }
}

void push(Stack *s, int value) {
    if (s == NULL) {
        printf("Ponteiro inválido!\n");
        return;
    }

    if (isStackFull(s)) {
        resizeStack(s);
    }
    s->top++;
    s->elements[s->top] = value;
}

int pop(Stack *s) {
    if (s == NULL) {
        printf("Ponteiro inválido!\n");
        return -1;
    }

    if (isStackEmpty(s)) {
        printf("\nA pilha está vazia!\n\n");
        return -1;
    } else {
        int value = s->elements[s->top];
        s->top--;
        return value;
    }
}

int peek(Stack *s) {
    if (s == NULL) {
        printf("Ponteiro inválido!\n");
        return -1;
    }

    if (isStackEmpty(s)) {
        printf("\nA pilha está vazia!\n\n");
        return -1;
    } else {
        return s->elements[s->top];
    }
}
