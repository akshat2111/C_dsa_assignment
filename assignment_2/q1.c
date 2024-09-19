#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *head, *next, *newnode, *prevnode, *temp;

void create_list()
{
    int i = 0;
    while(i<4){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    }
}
void printlist()
{
    temp = head;
    while(temp!= NULL){
        printf("%d", newnode->data);
    }
}
void insertnode()
{
    int pos,i=1;
    printf("\nenter the position: ");
    scanf("%d", &pos);
    temp = head;
    while(i<pos){
        temp = temp->next;
        i++;
    }
    
}