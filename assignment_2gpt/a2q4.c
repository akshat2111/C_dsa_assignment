
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Push operation to add an element to the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;  // Point the new node to the current top
    *top = newNode;        // Make the new node the top of the stack
    printf("Pushed %d to the stack.\n", data);
}

// Pop operation to remove the top element from the stack
void pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }

    struct Node* temp = *top;
    printf("Popped %d from the stack.\n", temp->data);
    *top = (*top)->next;  // Move the top to the next node
    free(temp);           // Free the memory of the popped node
}

// Peek operation to view the top element of the stack
void peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Top element is %d\n", top->data);
}

// Display the stack elements
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven program
int main() {
    struct Node* top = NULL;  // Initialize the stack (empty)

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to push: ");
            scanf("%d", &data);
            push(&top, data);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
            peek(top);
            break;

        case 4:
            display(top);
            break;

        case 5:
            exit(0);
        
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}
