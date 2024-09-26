#include<stdio.h>

struct node{
    int data;
    struct node* next;
};
struct node *front= NULL, *rear = NULL, *temp;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(rear == NULL)
    {
        rear = front = newnode;
        rear->next = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue()
{
    if(rear == NULL &&front == NULL)
    {
        printf("The queue is empty");
    }
    else if(rear == front)
    {
        temp = front;
        front = rear = 0;
        free(temp);
    }
    else{
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    
}