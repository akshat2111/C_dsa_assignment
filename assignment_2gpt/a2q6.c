#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit() function

#define MAX 100

// Stack structure
struct Stack {
    int top;
    int arr[MAX];
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Evaluate the postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);
    char ch;
    int i = 0, operand1, operand2, result;

    // Loop through the characters in the postfix expression
    while ((ch = postfix[i++]) != '\0') {
        // If the character is a digit, push it onto the stack
        if (isdigit(ch)) {
            push(&stack, ch - '0');  // Convert character to integer
        }
        // If the character is an operator, pop two operands and perform the operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Division by zero error\n");
                    return -1;
                }
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid operator encountered: %c\n", ch);
                return -1;
            }

            // Push the result back onto the stack
            push(&stack, result);
        }
    }

    // The final result is the remaining element in the stack
    return pop(&stack);
}

// Main function
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression (single digit operands): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    if (result != -1) {
        printf("The result of the postfix expression is: %d\n", result);
    }

    return 0;
}
