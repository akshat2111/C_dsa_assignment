#include <stdio.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == size-1&& front == -1)
    {
        printf("Overflow!\n");
    }
    else if(rear==-1&&front == -1){
        front= rear = 1;
        queue[front]= x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void peek()
{
    if(front== -1 &&rear ==-1)
    {
        printf("The queue is empty\n");
    }
    else{
    printf("The first element of the queue is: %d",queue[front] );
    printf("\n");
    }
}

void dequeue()
{
    if(rear==-1&&front ==-1)
    {
        printf("Queue is empty!");
        printf("\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else{
        printf("Dequeued %d from the queue", queue[front]);
        front++;
    }
    printf("\n");
}

void display()
{
    int i;
    printf("The elements in the queue: "); 
    for(i=front; i<rear+1; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void count()
{
    int i, count=0;
    printf("The no. elements in the queue: "); 
    for(i=front; i<=rear; i++)
    {
        count++;
    }
    printf("%d", count);
    printf("\n");
}

int main ()
{
    enqueue(10);
    enqueue(34);
    enqueue(12);
    enqueue(9);
    display();
    count();
    peek();
    dequeue();
    peek();
    display();
    count();

}