#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100

//Create node structure
typedef struct Node{
    char *key;
    char *value;
    struct Node *next;
} Node;

//Create hash table structure
typedef struct Hash{
    Node *list[HASH_SIZE];
} Hash;

//Functions Declaration
Hash *createHash();
Node* createNode(char *key, char *value);
unsigned int hashCode(char *key);
void insertNode(Hash *hash, char *key, char *value);
char* search(Hash *hash, char *key);

//Main
int main(){
    Hash *hash = createHash(); //Create the hash table

    printf("Hash Table\n\n");

    //Inserting the nodes
    insertNode(hash, "BSB", "Brasilia");
    insertNode(hash, "CWB", "Curitiba");

    printf("Searhing and printing the nodes:\n");
    printf("Value with \"BSB\" key: %s\n", search(hash, "BSB"));
    printf("Value with \"CWB\" key: %s\n", search(hash, "CWB"));

    printf("\nSearching for an invalid key:\n");
    printf("Value with \"GRU\" key: %s\n", search(hash, "GRU"));
}

//Functions implementation
Hash *createHash(){
    Hash *hash = (Hash*)malloc(sizeof(Hash));

    if(hash == NULL){
        printf("Allocation Error!\n");
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
        printf("Allocation Error!\n");
        exit(1);
    }

    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;

    return node;
}

unsigned int hashCode(char *key){ //hash function djb2
    unsigned long hash = 6318;
    unsigned int c;

    while((c = *key++))
        hash = ((hash << 5) + hash) + c; //hash * 32 + c
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
    return "Invalid Key";
}