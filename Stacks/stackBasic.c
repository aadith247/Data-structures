#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;

void printlist()
{ 
    struct node *ptr=top;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
}

int isfull(struct node *temp)
{
    if(temp==NULL)
    {
        return 1;
    } else {
        return 0;
    }
}
void push(int d)
{
     struct node *temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    if(!isfull(temp))
    {
        
    if(top==NULL)
    {
        top=temp;

    } else {
        temp->next=top;
        top=temp;

    }
    }}



    
    int main()
    {
        push(90);
        push(23);
        push(12);
        printlist();
    }
   
