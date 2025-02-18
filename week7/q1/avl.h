#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

// AVL Tree Node
typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;

// Function Prototypes
Node* insert(Node* root, int key);
void inOrder(Node* root);
Node* findSuccessor(Node* root, int key);
Node* findPredecessor(Node* root, int key);

#endif