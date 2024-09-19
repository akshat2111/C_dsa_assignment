#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top;


void push(struct node *newnode )
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    
}