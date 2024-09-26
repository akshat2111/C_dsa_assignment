#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp, *newnode,*front = NULL, *rear =NULL;

void enqueue(int x)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    if(rear == NULL && front ==NULL){
    newnode->next = front=rear;
    front =rear =  newnode;
  }
  else{
    rear->next = newnode;
    rear = newnode;
  }   
}

void dequeue()
{
    if(front==NULL&&rear == NULL)
    {
        printf("Queue is empty.\n");
    }
    else {
        temp = front;
        printf("Deueued %d from the queue", temp->data);
        front = front->next;
        free(temp);
    }
    printf("\n");
}

void display()
{
    if(front == NULL && rear == NULL){
        printf("The queue is empty.");
    }
    else{
    temp = front;
    int i =0;
    printf("The queue: ");
    while(temp!=rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
    }
    printf("\n");
}
void count()
{
    temp = front;
    int i =0,count=0;
    printf("The queue count: ");
    while(temp!=rear)
    {
        count++;
        temp = temp->next;
        i++;
    }
    printf("%d", count);
    printf("\n");
}

void peek()
{
    printf("front: %d \n", front->data);
}

int main ()
{
    enqueue(10);
    enqueue(1);
    enqueue(4);
    enqueue(5);
    display();
    peek();
    count();
    
    dequeue();
    peek();
    count();
    display();
}