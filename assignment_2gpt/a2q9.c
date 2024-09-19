#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push element onto stack
void push(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

// Pop element from stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Queue using two stacks
struct Queue {
    struct Stack stack1;
    struct Stack stack2;
};

// Initialize the queue
void initQueue(struct Queue *q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

// Enqueue operation
void enqueue(struct Queue *q, int data) {
    push(&q->stack1, data);
    printf("Enqueued %d into queue\n", data);
}

// Dequeue operation
int dequeue(struct Queue *q) {
    // If both stacks are empty, queue is empty
    if (isEmpty(&q->stack1) && isEmpty(&q->stack2)) {
        printf("Queue Underflow\n");
        return -1;
    }

    // If stack2 is empty, move elements from stack1 to stack2
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            int temp = pop(&q->stack1);
            push(&q->stack2, temp);
        }
    }

    // Pop the element from stack2
    return pop(&q->stack2);
}

// Display queue elements by popping from stack2 (in reverse)
void display(struct Queue *q) {
    if (isEmpty(&q->stack1) && isEmpty(&q->stack2)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    // If stack2 is empty, move all elements from stack1 to stack2 first
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            int temp = pop(&q->stack1);
            push(&q->stack2, temp);
        }
    }

    // Display elements by popping stack2 without affecting original order
    for (int i = 0; i <= q->stack2.top; i++) {
        printf("%d ", q->stack2.arr[i]);
    }

    printf("\n");
}

// Main program
int main() {
    struct Queue q;
    initQueue(&q);

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;

            case 2:
                data = dequeue(&q);
                if (data != -1)
                    printf("Dequeued %d from queue\n", data);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
