#include<stdio.h>
#define size 5

int queue[size];
int front  = -1;
int rear = -1; 

void enqueue(int x)
{
    if(rear == -1 && front == -1 )
    {
         rear = front = 0;
         queue[rear]= x;
    }
    else if((rear+1)%size == front)
    {
        printf("Queue is full");
    }
    else{
        rear = (rear+1)%size;
        queue[rear]= x;
    }
}

void dequeue()
{
    if(front ==-1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else{
        printf("Dequeued %d from the queue\n",queue[front]);
        front = (front+1)%size;
    }
}
void display()
{
    int i=front;
    if(front == -1 && rear == -1)
    {
        printf("The queue is empty!");
    }
    else{
        printf("The queue: ");
        while (1)
        {
            printf("%d ", queue[i]);
            if (i==rear)
            break;
            i= (i+1)%size;
        }
    }
    printf("\n");
}
void count()
{
       int i=front,count=0;
    if(front == -1 && rear == -1)
    {
        printf("The queue is empty!");
    }
    else{
        printf("The queue count: ");
        while(1)
        {
            count++;
            if(i==rear)
            break;
            i= (i+1)%size;
        }
    }
    printf("%d", count);
    printf("\n"); 
}

int main ()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    count();
    dequeue();
    display();
    count ();
    enqueue(1);
    display();
    count();

}