#include "avl.h"


Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; 
    return node;
}

// Get height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Get balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotate
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Left rotate
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Insert node into AVL tree
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root;  // No duplicates allowed
    }

    // Update height
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Perform rotations if unbalanced
    if (balance > 1 && key < root->left->key) return rotateRight(root);
    if (balance < -1 && key > root->right->key) return rotateLeft(root);
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Inorder traversal (for debugging)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Find successor (next greater key)
Node* findSuccessor(Node* root, int key) {
    Node* successor = NULL;
    while (root) {
        if (key < root->key) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// Find predecessor (next smaller key)
Node* findPredecessor(Node* root, int key) {
    Node* predecessor = NULL;
    while (root) {
        if (key > root->key) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;
    int n, key, searchKey;
    
    // Insert Elements into AVL Tree
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

      // Print AVL Tree (Inorder)
    printf("Inorder Traversal of AVL Tree: ");
    inOrder(root);
    printf("\n");

    // Find Successor & Predecessor
    printf("Enter key to find successor and predecessor: ");
    scanf("%d", &searchKey);

    Node* successor = findSuccessor(root, searchKey);
    Node* predecessor = findPredecessor(root, searchKey);

    if (predecessor) {
        printf("Predecessor of %d: %d\n", searchKey, predecessor->key);
    } else {
        printf("No predecessor found for %d\n", searchKey);
    }

    if (successor) {
        printf("Successor of %d: %d\n", searchKey, successor->key);
    } else {
        printf("No successor found for %d\n", searchKey);
    }

    return 0;
}