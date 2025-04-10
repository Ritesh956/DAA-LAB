#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MinHeap;

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify-up (for insertion)
void heapifyUp(MinHeap* h, int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (h->arr[parent] > h->arr[index]) {
        swap(&h->arr[parent], &h->arr[index]);
        heapifyUp(h, parent);
    }
}

// Insert into heap
void insert(MinHeap* h, int value) {
    if (h->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }

    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

// Display heap as array
void displayHeap(MinHeap* h) {
    printf("Min Heap (array): ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    heap.size = 0;

    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&heap, value);
    }

    displayHeap(&heap);
    return 0;
}
