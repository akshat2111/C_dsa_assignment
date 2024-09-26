#include <stdio.h>

#define size 10

int stack[size];
int top = -1;

void push()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    if (top == size-1)
    {
        printf("stack is full\n");
        return;
    }
    else{
    top++;
    stack[top] = data; 
    }
}
void pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
         int poppedItem = stack[top];
        top--;
        printf("Popped %d from the stack.\n", poppedItem);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else {
        int item = stack[top];
        printf("Top of the stack: %d", item);
    }
    printf("\n");
}

void display()
{
    int i;
    printf("Stack elements: ");
    for (i=top; i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push();
    push();
    push();
    push();
    display();
    pop(); 
    peek();
    display();
}