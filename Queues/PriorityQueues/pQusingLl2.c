#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node{
    char str[100];
    int prior;
    struct node *next;
};
struct node *head=NULL;

void enqueue(char d[],int p)
{
    struct node *temp=malloc(sizeof(struct node));
    strcpy(temp->str,d);
    temp->prior=p;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    } 
    
    else 
    {
        if(temp->prior >=head->prior)
        {
            temp->next=head;
            head=temp;
        } 
        else 
        {
            struct node *gh=head;
            while (gh->next != NULL && temp->prior < gh->next->prior)

            {
                if(temp->prior<gh->next->prior)
                {
                    gh=gh->next;
                }
            }
            temp->next=gh->next;
            gh->next=temp;
        }
    }
    
    printf("Inserted node with task %s\n", temp->str);
}




void printList()
{
    struct node *u=head;
    while(u!=NULL)
    {
        printf(" %d",u->prior);
        u=u->next;
    }
    printf("\n");
}

int main()
{
enqueue("hi",7);
enqueue("hello",3);
enqueue("apple",6);
enqueue("mango",2);
enqueue("this",4);
enqueue("bro",5);
enqueue("sis",1);
printList();
}
