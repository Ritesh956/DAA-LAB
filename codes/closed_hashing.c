#include <stdio.h>

#define SIZE 10
#define EMPTY -1

typedef struct {
    int table[SIZE];
} HashTable;

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert using linear probing
void insert(HashTable* ht, int key) {
    int index = hash(key);
    int start = index;

    while (ht->table[index] != EMPTY) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Hash table is full!\n");
            return;
        }
    }
    ht->table[index] = key;
}

// Search using linear probing
int search(HashTable* ht, int key) {
    int index = hash(key);
    int start = index;

    while (ht->table[index] != EMPTY) {
        if (ht->table[index] == key)
            return 1; // Found

        index = (index + 1) % SIZE;
        if (index == start)
            break; // Searched entire table
    }
    return 0; // Not found
}

// Display function
void display(HashTable* ht) {
    printf("Index : Value\n");
    for (int i = 0; i < SIZE; i++) {
        if (ht->table[i] != EMPTY)
            printf("%2d : %d\n", i, ht->table[i]);
        else
            printf("%2d : EMPTY\n", i);
    }
}

int main() {
    HashTable ht;
    for (int i = 0; i < SIZE; i++)
        ht.table[i] = EMPTY;

    int n, val;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&ht, val);
    }

    printf("\nHash Table (Closed Hashing - Linear Probing):\n");
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
