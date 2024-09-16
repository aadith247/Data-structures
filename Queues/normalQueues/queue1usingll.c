#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void insert(int d)
{
    struct node *t=malloc(sizeof(struct node));
    t->data=d;
    t->next=NULL;
    if(front==NULL)
    {
        front=t;
        rear=t;
        rear->next=front;
    } else {
        rear->next=t;
        rear=t;
        rear->next=front;
    }

}

void delete()
{
    if(front==NULL)
    {
        printf("NO element to delete");
        exit(1);
    } else {
        struct node *t=front;
        front=front->next;
        rear->next=front;
        free(t);
    }

}

void printlist()
{
    struct node *ptr=front;
   do{
    printf("%d",ptr->data);
    ptr=ptr->next;
   } while(ptr->next!=front);
     

       
} 


int main()
{
    insert(90);
    insert(12);
    insert(244);
    insert(78);
    delete();
    delete();
    printlist();




}