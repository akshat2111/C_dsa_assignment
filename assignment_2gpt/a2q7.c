#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue using array
struct ArrayQueue {
    int arr[MAX];
    int front;
    int rear;
    int count;
};

// Initialize queue
void initArrayQueue(struct ArrayQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is empty
int isEmptyArray(struct ArrayQueue *q) {
    return q->count == 0;
}

// Check if queue is full
int isFullArray(struct ArrayQueue *q) {
    return q->count == MAX;
}

// Insert an element into the queue
void enqueueArray(struct ArrayQueue *q, int data) {
    if (isFullArray(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
    q->count++;
    printf("Inserted %d into queue\n", data);
}

// Remove an element from the queue
void dequeueArray(struct ArrayQueue *q) {
    if (isEmptyArray(q)) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted %d from queue\n", q->arr[q->front]);
    q->front = (q->front + 1) % MAX;
    q->count--;
}

// Check number of elements in the queue
int numberOfElementsArray(struct ArrayQueue *q) {
    return q->count;
}

// Display queue elements
void displayArrayQueue(struct ArrayQueue *q) {
    if (isEmptyArray(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for (i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX]);
    }
    printf("\n");
}
// Queue using linked list
struct Node {
    int data;
    struct Node* next;
};

struct LinkedListQueue {
    struct Node* front;
    struct Node* rear;
    int count;
};

// Initialize linked list queue
void initLinkedListQueue(struct LinkedListQueue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

// Check if queue is empty
int isEmptyLinkedList(struct LinkedListQueue* q) {
    return q->front == NULL;
}

// Insert an element into the queue
void enqueueLinkedList(struct LinkedListQueue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmptyLinkedList(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("Inserted %d into queue\n", data);
}

// Remove an element from the queue
void dequeueLinkedList(struct LinkedListQueue* q) {
    if (isEmptyLinkedList(q)) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Deleted %d from queue\n", temp->data);
    q->front = q->front->next;
    free(temp);
    q->count--;
}

// Check number of elements in the queue
int numberOfElementsLinkedList(struct LinkedListQueue* q) {
    return q->count;
}

// Display queue elements
void displayLinkedListQueue(struct LinkedListQueue* q) {
    if (isEmptyLinkedList(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct ArrayQueue arrayQueue;
    struct LinkedListQueue linkedListQueue;
    initArrayQueue(&arrayQueue);
    initLinkedListQueue(&linkedListQueue);

    int choice, data, structureChoice;

    while (1) {
        printf("\nChoose data structure:\n");
        printf("1. Array Queue\n");
        printf("2. Linked List Queue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &structureChoice);

        if (structureChoice == 3)
            break;

        printf("\nMenu:\n");
        printf("1. Construct Queue\n");
        printf("2. Insertion (Enqueue)\n");
        printf("3. Deletion (Dequeue)\n");
        printf("4. Check number of elements\n");
        printf("5. Display queue\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (structureChoice == 1)
                    initArrayQueue(&arrayQueue);
                else
                    initLinkedListQueue(&linkedListQueue);
                printf("Queue constructed.\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                if (structureChoice == 1)
                    enqueueArray(&arrayQueue, data);
                else
                    enqueueLinkedList(&linkedListQueue, data);
                break;

            case 3:
                if (structureChoice == 1)
                    dequeueArray(&arrayQueue);
                else
                    dequeueLinkedList(&linkedListQueue);
                break;

            case 4:
                if (structureChoice == 1)
                    printf("Number of elements: %d\n", numberOfElementsArray(&arrayQueue));
                else
                    printf("Number of elements: %d\n", numberOfElementsLinkedList(&linkedListQueue));
                break;

            case 5:
                if (structureChoice == 1)
                    displayArrayQueue(&arrayQueue);
                else
                    displayLinkedListQueue(&linkedListQueue);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
