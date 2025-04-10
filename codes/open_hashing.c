#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* table[SIZE];
} HashTable;

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert function
void insert(HashTable* ht, int key) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search function
int search(HashTable* ht, int key) {
    int index = hash(key);
    Node* temp = ht->table[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1; // Found
        temp = temp->next;
    }
    return 0; // Not found
}

// Display function
void display(HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        Node* temp = ht->table[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht;
    for (int i = 0; i < SIZE; i++)
        ht.table[i] = NULL;

    int n, val;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&ht, val);
    }

    printf("\nHash Table (Open Hashing):\n");
    display(&ht);

    // Search
    int key;
    printf("\nEnter value to search: ");
    scanf("%d", &key);
    if (search(&ht, key))
        printf("Key %d found in the hash table.\n", key);
    else
        printf("Key %d not found in the hash table.\n", key);

    return 0;
}
