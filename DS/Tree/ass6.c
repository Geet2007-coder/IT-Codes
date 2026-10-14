
#include <stdio.h>

#define MAX 100

int heap[MAX];
int n = 0;

// Maintain heap after insertion
void reheapUp(int i) {
    int parent, temp;

    while (i > 0) {
        parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

// Maintain heap after removal
void reheapDown(int i) {
    int left, right, largest, temp;

    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

// Build heap from input elements
void buildHeap() {
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        reheapDown(i);
}

// Insert an element
void insert(int x) {
    if (n == MAX) {
        printf("Heap is Full\n");
        return;
    }

    heap[n] = x;
    reheapUp(n);
    n++;
}

// Delete maximum element
void deleteMax() {
    if (n == 0) {
        printf("Heap is Empty\n");
        return;
    }

    printf("Deleted: %d\n", heap[0]);

    heap[0] = heap[n - 1];
    n--;

    if (n > 0)
        reheapDown(0);
}

// Display heap array
void display() {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int i, count, x;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    if (count < 0 || count > MAX) {
        printf("Invalid number of elements\n");
        return 1;
    }

    n = count;

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    buildHeap();

    printf("Max Heap: ");
    display();

    printf("Enter element to insert: ");
    scanf("%d", &x);

    insert(x);

    printf("After insertion: ");
    display();

    deleteMax();

    printf("After deletion: ");
    display();

    return 0;
}
