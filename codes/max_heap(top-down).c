#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} MaxHeap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up after insertion
void heapifyUp(MaxHeap* h, int index) {
    if (index == 0)
        return;

    int parent = (index - 1) / 2;

    if (h->arr[parent] < h->arr[index]) {
        swap(&h->arr[parent], &h->arr[index]);
        heapifyUp(h, parent);
    }
}

void insert(MaxHeap* h, int value) {
    if (h->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }

    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

void displayHeap(MaxHeap* h) {
    printf("Max Heap (array): ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap heap;
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
