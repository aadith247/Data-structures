#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    char str[100];
    int prior;
    struct node *next;
};

struct node *head=NULL;

void enqueue(char str[],int p)
{
    struct node *new=malloc(sizeof(struct node));
    strcpy(new->str,str);
    new->prior=p;
    if(head==NULL)
    {
        head=new;

    } 
    if(p<=head->prior)
    {
        new->next=head;
        head=new;
    } else {
        struct node *ptr=head;
        while(ptr->next!=NULL&& p>ptr->next->prior)
        {
            if(p>ptr->next->prior)
            {
                ptr=ptr->next;
            }
        }
        new->next=ptr->next;
        ptr->next=new;

    }
}

void printlist()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%s",temp->str);
        printf("\n");
    }
}

int main()
{
    enqueue("hello",3);
    enqueue("hi",4);
    enqueue("Mango...",9);


}