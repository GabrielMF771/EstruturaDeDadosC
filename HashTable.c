#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define HASH_SIZE 100

//Cria a estrutura do nó
typedef struct Node{
    char *key;
    char *value;
    struct Node *next;
} Node;

//Cria a estrutura da HashTable
typedef struct Hash{
    Node *list[HASH_SIZE];
} Hash;

//Declarações
Hash *createHash();
Node* createNode(char *key, char *value);
unsigned int hashCode(char *key);
void insertNode(Hash *hash, char *key, char *value);
char* search(Hash *hash, char *key);

//Main
int main(){
    setlocale(LC_ALL, "Portuguese");

    Hash *hash = createHash(); //Cria a HashTable

    //Inserindo os Nós
    insertNode(hash, "BSB", "Brasilia");
    insertNode(hash, "CWB", "Curitiba");

    printf("Buscando e imprimindo os nós criados\n");
    printf("Valor com a chave BSB: %s\n", search(hash, "BSB"));
    printf("Valor com a chave CWB: %s\n", search(hash, "CWB"));

    printf("\nBuscando por uma chave inválida\n");
    printf("Valor com a chave GRU: %s\n", search(hash, "GRU"));
}

//Funções
Hash *createHash(){
    Hash *hash = (Hash*)malloc(sizeof(Hash));

    if(hash == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    for(int i = 0 ; i < HASH_SIZE ; i++){
        hash->list[i] = NULL;
    }

    return hash;
}

Node* createNode(char *key, char *value){
    Node *node = (Node*)malloc(sizeof(Node));

    if(node == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;

    return node;
}

unsigned int hashCode(char *key){ //Função Hash djb2
    unsigned long hash = 6318;
    unsigned int c;

    while((c = *key++)){
        hash = ((hash << 5) + hash) + c; //hash * 33 + c
    }

    return hash % HASH_SIZE;
}

void insertNode(Hash *hash, char *key, char *value){
    unsigned int index = hashCode(key);
    Node *node = hash->list[index];

    if(node == NULL){
        hash->list[index] = createNode(key, value);
    } else {
        while(node){
            if (node->next == NULL) {
                node->next = createNode(key, value);
                break;
            }
            node = node->next;
        }
    }
}

char* search(Hash *hash, char *key){
    unsigned int index = hashCode(key);
    Node *node = hash->list[index];

    while(node){
        if(strcmp(node->key, key) == 0){
            return node->value;
        }
        node = node->next;
    }
    return "Chave Inválida";
}