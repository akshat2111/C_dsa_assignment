#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode,*head=NULL,*temp;
void createlist()
{
    int n = 0;
    printf("Enter data: \n");
    while(n<5)
    {
       newnode = (struct node*)malloc(sizeof(struct node));
       scanf("%d", &newnode->data);
       newnode->next = NULL;
       if(head==NULL)
       {
        head =temp= newnode;
       }
       else{
        temp->next = newnode;
        temp = newnode;
       }
       n++;
    }
    temp->next = head;
    
}
void printlist()
{
    temp = head;
    printf("The list: \n");
    do{
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    printf("\n");
}

void josephproblem()
{
    struct node* temp2;
    int k,count = 0;
    printf("Enter the Kth element: ");
    scanf("%d", &k);
    temp = head;
    do{
        count++;
        temp = temp->next;
    }
    while(temp!=head);
    printf("count: %d\n",count);
    
    temp = head;
    temp2 = NULL;
    while (count>1)
    {
        int i=1;
        while(i<k)
        {
            temp2 = temp;
            temp = temp->next;
            i++;
        }
        temp2->next = temp->next;
        free(temp);
        temp = temp2->next;
        count --;
    }
    printf("The last remaining node: %d",temp->data);
}

int main ()
{
    createlist();
    printlist();
    josephproblem();
}