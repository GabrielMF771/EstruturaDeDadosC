#include <stdio.h>
#include <stdlib.h>

//Cria a estrutura do nó
typedef struct nodeitem{
    int item;
    struct nodeitem *next;
}node;

//Cria a estrutura da lista
typedef struct{
    node *head;
    node *tail;
}queue;

//Declarações
int isEmpty(queue *q);
queue *createqueue();
node *createNode(int value);
void enqueue(queue *q, int value);
void dequeue(queue *q);
void showQueue(queue *q);
int lenght(queue *q);

int main(){
    queue *q = createqueue(); //Cria a fila

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    showQueue(q);
    printf("Tamanho atual da fila: %d\n", lenght(q));
    printf("\n");

    dequeue(q); //Remove um elemento da fila
    dequeue(q); //Remove um elemento da fila

    showQueue(q);
    printf("Tamanho atual da fila: %d\n", lenght(q));
}

int isEmpty(queue *q){
    if(q->head == NULL){
        return 1;
    }
    return 0;
}

queue *createqueue(){
    queue *q = (queue*)malloc(sizeof(queue));

    if (q == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    q->head = NULL;
    q->tail = NULL;
    return q;
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

void enqueue(queue *q, int value){
    node *newNode = createNode(value);

    if(isEmpty(q)){
        q->head = newNode;
        q->tail = newNode;
    }

    q->tail->next = newNode;
    q->tail = newNode;
}

void dequeue(queue *q){
    if (isEmpty(q)){
        printf("A fila está vazia!\n");
    }

    node *newNode = q->head;
    q->head = newNode->next;

    free(newNode);
}

void showQueue(queue *q){
    if(isEmpty(q)){
        printf("A fila está vazia!\n");
    } else {
        node *current = q->head;

        printf("Fila: ");

        while(current != NULL){
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}

int lenght(queue *q){
    int i = 0;

    if(isEmpty(q)){
        return i;
    } else {
        node *current = q->head;

        while(current != NULL){
            current = current->next;
            i++;
        }
        return i;
    }
}