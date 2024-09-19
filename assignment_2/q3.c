#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node *newnode, *head = NULL, *temp;

void createlist()
{
    int n= 0;
    printf("Enter data: ");
    while(n<5)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->prev=NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        n++;
    }
}
void printlist()
{
    temp = head;
    printf("The list..:\n");
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertnode()
{
    struct node *temp2;
    int pos, i=1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count ++;
        temp = temp->next;
    }
    printf("Enter data: ");
    newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    if (pos >count || pos<0)
    {
        printf("Invalid position!");
        return;
    }

    if (pos == count)
    {
        temp = head;
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next  = newnode;
    }

    else if (pos==1)
    {
        temp = head;
        newnode->prev = NULL;
        newnode->next = temp;
        temp->prev = newnode;
        head = newnode;
    }
    else{
    temp = head;
    while(i<pos)
    {
        temp2 = temp;
        temp = temp->next;
        i++;   
    }
    newnode->next = temp;
    newnode->prev = temp->prev;
    temp->prev = newnode;
    temp2->next = newnode;
    }
}

void delete()
{
    int pos,i=0;
    printf("enter the position: ");
    scanf("%d", &pos);
    temp = head;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);

}
void countnodes()
{
    temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count ++;
        temp= temp->next;
    }
    printf("No. of nodes: %d", count);
    printf("\n");
}

void printreverse()
{
    temp = head;
    while(temp->next!= NULL)
    {
        temp = temp->next;
    }
    printf("The reverse printed list: ");
    while(temp!=head)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d", temp->data);
    printf("\n");
}

void reverselist()
{
    struct node *temp2=NULL;
    temp = head;
    while(temp!= NULL)
    {
        temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;

    }
    if (temp2!=NULL)
    {head = temp2->prev;}
    printlist();
}


int main ()
{
    createlist();
    printlist();
    insertnode();
    printlist();
    delete();
    printlist();
    printreverse();
    reverselist();
}