#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at a specified position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node from a specified position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 1) {
        *head = (*head)->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

// Count the number of nodes in the doubly linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Reverse print the doubly linked list
void reversePrint(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Print the list in reverse order
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Reverse the doubly linked list
void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    // Swap the next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Adjust the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at position\n");
        printf("2. Delete from position\n");
        printf("3. Count nodes\n");
        printf("4. Reverse print\n");
        printf("5. Reverse list\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;

        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteFromPosition(&head, position);
            break;

        case 3:
            printf("Number of nodes: %d\n", countNodes(head));
            break;

        case 4:
            printf("Reversed list: ");
            reversePrint(head);
            break;

        case 5:
            reverseList(&head);
            printf("List reversed.\n");
            break;

        case 6:
            displayList(head);
            break;

        case 7:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
