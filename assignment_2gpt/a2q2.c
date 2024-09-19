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

// Function to create a circular linked list with 'n' nodes
struct Node* createCircularList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* last = NULL;

    // Create nodes and link them in circular fashion
    for (int i = 1; i <= n; i++) {
        temp = createNode(i);

        if (head == NULL) {
            head = temp;
        } else {
            last->next = temp;
        }
        last = temp;
        last->next = head; // Making the list circular
    }

    return head;
}

// Function to solve the Josephus problem
int josephus(struct Node** head, int k) {
    struct Node* prev = *head;
    struct Node* current = *head;

    // If there's only one node
    if (*head == NULL || (*head)->next == *head) {
        return current->data;
    }

    // Traverse the list until only one node is left
    while (current->next != current) {
        // Move (k-1) steps forward in the circle
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }

        // Remove the current node (the k-th person)
        prev->next = current->next;
        printf("Person at position %d is eliminated.\n", current->data);
        free(current);

        // Move current pointer to the next person
        current = prev->next;
    }

    // The last remaining person is the survivor
    *head = current;
    return current->data;
}

int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);

    printf("Enter the step count (k): ");
    scanf("%d", &k);

    // Create a circular linked list with n people
    struct Node* head = createCircularList(n);

    // Solve the Josephus problem
    int survivor = josephus(&head, k);
    printf("The last remaining person is at position: %d\n", survivor);

    return 0;
}
