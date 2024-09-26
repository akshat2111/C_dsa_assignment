#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL, *temp;


void push(int x )
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;     
}

void display()
{
    int i=0;
    temp = top;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else{
    printf("The stack elements are: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    }
    printf("\n");
}

void pop()
{
    temp = top;
    if(top == NULL)
    {
        printf("Stack is empty");
    }
    else{
        printf("Popped %d from the stack.", top->data);
        top = top->next;
        free(temp);
    }
    printf("\n");
}

void peek()
{
    if(top== NULL)
    {
        printf("Stack is empty");
    }
    else{
        printf("The top element is: %d", top->data);
    }
    printf("\n");
}

int main()
{
    push(5);
    push(4);
    push(2);
    push(3);
    display();
    peek();
    pop();
    peek();
    display();
}
